#include "ATM.h"
#include "Menu.h"
#include <fstream>//ham mo file
#include <sstream>//ham xu ly chuoi, dung de tach chuoi
#include <ctime>//ham lay thoi gian
#include <iostream>
#include <iomanip>//tao so ngau nhien
#include <cstdlib>
#include <windows.h>
#include <string.h>

using namespace std;

ATM::ATM(string idATM, int soDuATM, string diaChi, bool trangThai)
	: Cust("", "", "", 0), idATM(idATM), soDuATM(soDuATM), diaChi(diaChi), trangThaiHoatDong(trangThai) {}

bool ATM::timSTK(string soThe) {
	string idBank = soThe.substr(0, 3);
	ifstream inputFile("Bank_"+ idBank + "_information.txt");
	if (inputFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			stringstream ss(line);
			string tenChuThe, pin, soTheTim;
			int soDu;
			
			getline(ss, soTheTim, ',');
			getline(ss, tenChuThe, ',');
			getline(ss, pin, ',');
			ss >> soDu;
			
			Cust =Customer(soTheTim,tenChuThe,pin,soDu);
			
			if (Cust.getSoThe() == soThe) {
				Cust.set_SoDu(soDu);
				return true;
			}
		}
	}
	return false;
}

bool ATM::checkPIN(string PIN) {
	return Cust.getPin() == PIN;
}

void ATM::ghiLichSu(string action, float amount, const string& transactionId) {
	string idBank = Cust.getSoThe().substr(0, 3);
	string transactionFileName = "Cust_" + Cust.getSoThe() + "_transaction_history.txt";
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
	string bankTransactionFileName = "ATM_" + idATM + "_transaction_history.txt";
	ofstream bankLogFile(bankTransactionFileName, ios::app);
	if (bankLogFile.is_open()) {
		time_t now = time(0);
		tm *ltm = localtime(&now);

		char dt[20];
		strftime(dt, sizeof(dt), "%d/%m/%Y %H:%M:%S", ltm);


		bankLogFile << dt << ", "<< "Transaction ID: " << transactionId <<", " << action << " - " << amount << " VND, Tai khoan: " << Cust.getSoThe()  << endl;
		bankLogFile.close();
	} else {
		cout << "Khong the mo file lich su giao dich ngan hang!" << endl;
	}
}

void ATM::ghiLichSuNganHang(string action, float amount, const string& transactionId) {
	string idBank = Cust.getSoThe().substr(0, 3);
	string bankTransactionFileName = "Bank_" + idBank + "_transaction_history.txt";
	ofstream bankLogFile(bankTransactionFileName, ios::app);
	if (bankLogFile.is_open()) {
		time_t now = time(0);
		tm *ltm = localtime(&now);

		char dt[20];
		strftime(dt, sizeof(dt), "%d/%m/%Y %H:%M:%S", ltm);


		bankLogFile << dt << ", "<< "Transaction ID: " << transactionId <<", " << action << " - " << amount << " VND, Tai khoan: " << Cust.getSoThe()  << endl;
		bankLogFile.close();
	} else {
		cout << "Khong the mo file lich su giao dich ngan hang!" << endl;
	}
}


void ATM::ghiThongTinKhachHang() {
	string idBank = Cust.getSoThe().substr(0, 3);
	string customerFileName = "Bank_" + idBank + "_information.txt";
	ifstream inputFile(customerFileName);
	ofstream tempFile(idBank + "_temp.txt");

	if (inputFile.is_open() && tempFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			stringstream ss(line);
			string tk;
			getline(ss, tk, ',');
			if (tk == Cust.getSoThe()) {
				tempFile << Cust.getSoThe() << "," << Cust.getTenChuThe() << "," << Cust.getPin() << "," <<  fixed << setprecision(0) << Cust.getSoDu()  << endl;
			} else {
				tempFile << line << endl;
			}
		}
		inputFile.close();
		tempFile.close();
		remove(customerFileName.c_str());
		rename((idBank + "_temp.txt").c_str(), customerFileName.c_str());
	} else {
		cout << "1.Khong the mo file de ghi!" << endl;
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

void ATM::printReceipt(const string& action, float amount, const string& transactionId) {
	weigh();
    cout << "|" << setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) << "|" << "\n";
    cout << "|" << setw(39) << (char)186 << "          HOA DON GIAO DICH             " << (char)186 << setw(39) << "|" << "\n";
    cout << "|" << setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) << "|" << "\n";
    weigh();
    cout << "|" << setw(119) << "|" << "\n";
    cout << "|" << setw(30) << "Ma giao dich:" << setw(20) << transactionId << setw(70) << "|\n";
    cout << "|" << setw(30) << "Loai giao dich:" << setw(20) << action << setw(70) << "|\n";
    cout << "|" << setw(30) << "So tien:" << setw(20) << fixed << setprecision(2) << amount << " VND" << setw(66) << "|\n";
    cout << "|" << setw(30) << "So du sau giao dich:" << setw(20) << fixed << setprecision(2) << Cust.getSoDu() << " VND" << setw(66) << "|\n";
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
	if (soTien > Cust.getSoDu()) {
		cout << "So tien rut vuot qua so du!" << endl;
		return;
	}

	if (soTien > soDuATM) {
		cout << "ATM khong du tien de rut!" << endl;
		return;
	}

	Cust.set_SoDu(Cust.getSoDu() - soTien);

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
	Cust.set_SoDu(Cust.getSoDu() + soTien);

	soDuATM += soTien;

	string transactionId = generateTransactionId();
	ghiLichSu("Nap tien", soTien, transactionId);
	ghiLichSuATM("Nap tien", soTien, transactionId);
	ghiLichSuNganHang("Nap tien", soTien, transactionId);

	ghiThongTinKhachHang();

	capNhatSoDuATM();

	printReceipt("Nap tien", soTien, transactionId);
}

























































