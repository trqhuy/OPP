#include "ATM.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <string.h>
using namespace std;

ATM::ATM(string idATM, float soDuATM, string diaChi, bool trangThai, string nganHang)
			: Cust("", "", "", 0), idATM(idATM), soDuATM(soDuATM), diaChi(diaChi), trangThaiHoatDong(trangThai), nganHangQuanLy(nganHang) {}

bool ATM::timSTK(string soThe) {
	string idBank = soThe.substr(0, 3);
	ifstream inputFile(idBank + "_information.txt");
	if (inputFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			stringstream ss(line);
			string tenChuThe, pin;
			float soDu;

			getline(ss, Cust.soThe, ',');
			getline(ss, Cust.tenChuThe, ',');
			getline(ss, Cust.PIN, ',');
			ss >> soDu;

			if (Cust.soThe == soThe) {
				Cust.soDu = soDu;
				return true;
			}
		}
	}
	return false;
}

bool ATM::checkPIN(string PIN) {
	return Cust.PIN == PIN;
}

void ATM::ghiLichSu(string action, float amount, const string& transactionId) {
	string idBank = Cust.soThe.substr(0, 3);
	string transactionFileName = idBank + "_" + Cust.soThe + "_transaction_history.txt";
	ofstream logFile(transactionFileName, ios::app);
	if (logFile.is_open()) {
		time_t now = time(0);
		char* dt = ctime(&now);
		logFile << dt << ": " << action << " - " << amount << " VND, Transaction ID: " << transactionId << endl;
		logFile.close();
	} else {
		cout << "Khong the mo file lich su giao dich!" << endl;
	}
}

void ATM::ghiLichSuNganHang(string action, float amount, const string& transactionId) {
	string idBank = Cust.soThe.substr(0, 3);
	string bankTransactionFileName = idBank + "_transaction_history.txt";
	ofstream bankLogFile(bankTransactionFileName, ios::app);
	if (bankLogFile.is_open()) {
		time_t now = time(0);
		char* dt = ctime(&now);
		bankLogFile << dt << ": " << action << " - " << amount << " VND, Tai khoan: " << Cust.soThe << ", Transaction ID: " << transactionId << endl;
		bankLogFile.close();
	} else {
		cout << "Khong the mo file lich su giao dich ngan hang!" << endl;
	}
}

void ATM::ghiThongTinKhachHang() {
	string idBank = Cust.soThe.substr(0, 3);
	string customerFileName = idBank + "_information.txt";
	ifstream inputFile(customerFileName);
	ofstream tempFile(idBank + "_temp.txt");

	if (inputFile.is_open() && tempFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			stringstream ss(line);
			string tk;
			getline(ss, tk, ',');
			if (tk == Cust.soThe) {
				tempFile << Cust.soThe << "," << Cust.tenChuThe << "," << Cust.PIN << "," << Cust.soDu << endl;
			} else {
				tempFile << line << endl;
			}
		}
		inputFile.close();
		tempFile.close();
		remove(customerFileName.c_str());
		rename((idBank + "_temp.txt").c_str(), customerFileName.c_str());
	} else {
		cout << "Khong the mo file de ghi!" << endl;
	}
}

void ATM::ghiThongTinATM() {
	string customerFileName = "atm-info.txt";
	ifstream inputFile(customerFileName);
	ofstream tempFile("_temp.txt");

	if (inputFile.is_open() && tempFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			stringstream ss(line);
			string id;
			getline(ss, id, ',');
			if (id == idATM) {
				tempFile << idATM << "," << soDuATM << "," << diaChi << "," << "Hoat Dong" "," << trangThaiHoatDong << endl;
			} else {
				tempFile << line << endl;
			}
		}
		inputFile.close();
		tempFile.close();
		remove(customerFileName.c_str());
	} else {
		cout << "Khong the mo file de ghi!" << endl;
	}
}
string ATM::generateTransactionId() {
	srand(static_cast<unsigned>(time(0)));
	stringstream ss;
	ss << "TX" << setw(6) << setfill('0') << rand() % 1000000;
	return ss.str();
}

void ATM::printReceipt(const string& action, float amount, const string& transactionId) {
	cout << "=== HOA DON GIAO DICH ===" << endl;
	cout << "Ma giao dich: " << transactionId << endl;
	cout << "Loai giao dich: " << action << endl;
	cout << "So tien: " << amount << " VND" << endl;
	cout << "So du sau giao dich: " << Cust.soDu << " VND" << endl;
	cout << "=========================" << endl;
}

void ATM::capNhatSoDuATM() {
	ifstream inputFile("atm_info.txt");
	ofstream tempFile(nganHangQuanLy + "_temp.txt");

	if (inputFile.is_open() && tempFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			stringstream ss(line);
			string id, diaChi, nganHang, trangThaiStr;
			float soDu;
			bool trangThai;

			getline(ss, id, ',');
			ss >> soDu;
			ss.ignore();
			getline(ss, diaChi, ',');
			getline(ss, trangThaiStr, ',');
			trangThai = (trangThaiStr == "Hoat Dong");
			getline(ss, nganHang, ',');

			if (id == idATM) {
				// Write updated ATM balance
				tempFile << idATM << "," << soDuATM << "," << diaChi << ","
				         << (trangThaiHoatDong ? "Hoat Dong" : "Khong Hoat Dong") << ","
				         << nganHangQuanLy << endl;
			} else {
				tempFile << line << endl;
			}
		}

		inputFile.close();
		tempFile.close();

		remove("atm_info.txt");
		rename((nganHangQuanLy + "_temp.txt").c_str(), "atm_info.txt");


	} else {
		cout << "Khong the mo file de cap nhat so du ATM!" << endl;
	}
}

void ATM::rutTien(float soTien) {
	if (soTien > Cust.soDu) {
		cout << "So tien rut vuot qua so du!" << endl;
		return;
	}

	if (soTien > soDuATM) {
		cout << "ATM khong du tien de rut!" << endl;
		return;
	}

	Cust.setSoDu(Cust.soDu - soTien);

	soDuATM -= soTien;

	string transactionId = generateTransactionId();
	ghiLichSu("Rut tien", soTien, transactionId);
	ghiLichSuNganHang("Rut tien", soTien, transactionId);

	ghiThongTinKhachHang();

	capNhatSoDuATM();

	printReceipt("Rut tien", soTien, transactionId);
}



void ATM::napTien(float soTien) {
	Cust.setSoDu(Cust.soDu + soTien);
	string transactionId = generateTransactionId();
	ghiLichSu("Nap tien", soTien, transactionId);
	ghiLichSuNganHang("Nap tien", soTien, transactionId);
	ghiThongTinKhachHang();
	printReceipt("Nap tien", soTien, transactionId);
}

