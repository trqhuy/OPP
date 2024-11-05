#include "ATM.h"
#include "Menu.h"
#include <fstream>
#include <sstream>//ham xu ly chuoi, dung de tach chuoi
#include <ctime>
#include <iostream>
#include <iomanip>//tao so ngau nhien
#include <cstdlib>
#include <windows.h>
#include <string.h>

using namespace std;

ATM::ATM(string idATM, float soDuATM, string diaChi, bool trangThai)
	: Cust("", "", "", 0), idATM(idATM), soDuATM(soDuATM), diaChi(diaChi), trangThaiHoatDong(trangThai) {}

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
		tm *ltm = localtime(&now);

		char dt[20];
		strftime(dt, sizeof(dt), "%d/%m/%Y %H:%M:%S", ltm);

		logFile << dt << ", " <<"Transaction ID: " << transactionId <<", "<< action << " - " << amount << " VND" << endl;
		logFile.close();
	} else {
		cout << "Khong the mo file lich su giao dich!" << endl;
	}
}

void ATM::ghiLichSuATM(string action, float amount, const string& transactionId) {
	string bankTransactionFileName = idATM + "_transaction_history.txt";
	ofstream bankLogFile(bankTransactionFileName, ios::app);
	if (bankLogFile.is_open()) {
		time_t now = time(0);
		tm *ltm = localtime(&now);

		char dt[20];
		strftime(dt, sizeof(dt), "%d/%m/%Y %H:%M:%S", ltm);


		bankLogFile << dt << ", "<< "Transaction ID: " << transactionId <<", " << action << " - " << amount << " VND, Tai khoan: " << Cust.soThe  << endl;
		bankLogFile.close();
	} else {
		cout << "Khong the mo file lich su giao dich ngan hang!" << endl;
	}
}

void ATM::ghiLichSuNganHang(string action, float amount, const string& transactionId) {
	string idBank = Cust.soThe.substr(0, 3);
	string bankTransactionFileName = idBank + "_transaction_history.txt";
	ofstream bankLogFile(bankTransactionFileName, ios::app);
	if (bankLogFile.is_open()) {
		time_t now = time(0);
		tm *ltm = localtime(&now);

		char dt[20];
		strftime(dt, sizeof(dt), "%d/%m/%Y %H:%M:%S", ltm);


		bankLogFile << dt << ", "<< "Transaction ID: " << transactionId <<", " << action << " - " << amount << " VND, Tai khoan: " << Cust.soThe  << endl;
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
				tempFile << Cust.soThe << "," << Cust.tenChuThe << "," << Cust.PIN << "," <<  fixed << setprecision(0) << Cust.soDu  << endl;
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
	string ATMFileName = "atm_info.txt";
	ofstream outputFile(ATMFileName, ios::app);

	if (outputFile.is_open()) {
		outputFile << idATM << "," << fixed << setprecision(0) << soDuATM << "," << diaChi << ","
		           << (trangThaiHoatDong ? "Hoat Dong" : "Khong Hoat Dong") << endl;
		outputFile.close();
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

//void ATM::printReceipt(const string& action, float amount, const string& transactionId) {
//	cout << "+=== HOA DON GIAO DICH ===+" << endl;
//	cout << "Ma giao dich: " << transactionId << endl;
//	cout << "Loai giao dich: " << action << endl;
//	cout << "So tien: " << amount << " VND" << endl;
//	cout << "So du sau giao dich: " << Cust.soDu << " VND" << endl;
//	cout << "=========================" << endl;
//}

void ATM::printReceipt(const string& action, float amount, const string& transactionId) {
	weigh();
    cout << "|" << setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) << "|" << "\n";
    cout << "|" << setw(39) << (char)186 << "          HOA DON GIAO DICH             " << (char)186 << setw(39) << "|" << "\n";
    cout << "|" << setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) << "|" << "\n";
    weigh();
    cout << "|" << setw(119) << "|" << "\n";
    cout << "|" << setw(30) << "Ma giao dich:" << setw(20) << transactionId << setw(69) << "|\n";
    cout << "|" << setw(30) << "Loai giao dich:" << setw(20) << action << setw(69) << "|\n";
    cout << "|" << setw(30) << "So tien:" << setw(20) << fixed << setprecision(2) << amount << " VND" << setw(59) << "|\n";
    cout << "|" << setw(30) << "So du sau giao dich:" << setw(20) << fixed << setprecision(2) << Cust.soDu << " VND" << setw(49) << "|\n";
    cout << "|" << setw(119) << "|" << "\n";
    
    weigh();
}

void ATM::capNhatSoDuATM() {
	string idBank = idATM.substr(0, 3);
	ifstream inputFile("atm_info.txt");
	ofstream tempFile(idBank + "_temp.txt");

	if (inputFile.is_open() && tempFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			stringstream ss(line);
			string id, diaChi, trangThai;
			float soDu;

			getline(ss, id, ',');
			ss >> soDu;
			ss.ignore();
			getline(ss, diaChi, ',');
			getline(ss, trangThai);

			if (id == idATM) {
				tempFile << idATM << "," << fixed << setprecision(0) << soDuATM << "," << diaChi << "," << trangThai << endl;
			} else {
				tempFile << line << endl;
			}
		}

		inputFile.close();
		tempFile.close();

		remove("atm_info.txt");
		rename((idBank + "_temp.txt").c_str(), "atm_info.txt");


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
	ghiLichSuATM("Rut tien", soTien, transactionId);
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

