#include "Admin.h"
#include "ATM.h"
#include "Menu.h"
#include<windows.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

void Admin::themATM(ATM atm) {
	danhSachATM.push_back(atm);
	atm.ghiThongTinATM();
}

void Admin::inDanhSachATM() {
	ifstream atmInfoFile("atm_info.txt");
	if (atmInfoFile.is_open()) {
		string line;
		int count = 1;
		while (getline(atmInfoFile, line)) {
			cout << count << ". " << line << endl;
			count++;
		}
		atmInfoFile.close();
	} else {
		cout << "Khong the mo file de doc thong tin ATM!" << endl;
	}
}


void Admin::themKhachHang(Customer& customer) {
	string idBank = customer.getSoThe().substr(0, 3);
	ofstream outputFile(idBank + "_information.txt", ios::app);
	if (outputFile.is_open()) {
		outputFile << customer.getSoThe() << ","
		           << customer.getTenChuThe() << ","
		           << customer.getPin() << ","
		           << customer.getSoDu() << endl;
		outputFile.close();
		weigh();
		cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|" << "\n";
		cout <<"|"<< setw(39) << (char)186 << "       TAI KHOAN MOI DA DUOC TAO        " << (char)186   << setw(39) <<"|"<< "\n";
		cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";
		weigh();
	} else {
		cout << "!!!!!!!!Khong the tao tai khoan ngan hang!!!!!!!!" << endl;
	}
}

void Admin::taoNganHang(string idBank) {
	system("cls");
	ofstream bankFile(idBank + "_information.txt");
	if (bankFile.is_open()) {
		weigh();
		cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|" << "\n";
		cout <<"|"<< setw(39) << (char)186 << "       NGAN HANG MOI DA DUOC TAO        " << (char)186   << setw(39) <<"|"<< "\n";
		cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";
		weigh();
		bankFile.close();
	} else {
		cout << "!!!!!!!!Khong the tao ngan hang!!!!!!!!" << endl;
	}
}
//xem lich su giao dich
void Admin::xemLichSuGiaoDich(string idBank) {
	ifstream logFile(idBank + "_transaction_history.txt");
	if (logFile.is_open()) {

		int count=1;
		string temp;
		string line;

		weigh();
		cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|" << "\n";
		cout <<"|"<< setw(39) << (char)186 << "          LICH SU GIAO DICH             " << (char)186   << setw(39) <<"|"<< "\n";
		cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";
		weigh();

		cout <<"|"<< setw(119) <<"|"<< "\n";
		cout <<"|"<< setw(8)<< "STT" << setw(20) <<"Ma giao dich" <<setw(20) <<"Tai khoan" << setw(30)<< "So tien" << setw(30) <<"Ngay thuc hien" << setw(11) <<"|"<< "\n";
		cout <<"|"<< setw(119) <<"|"<< "\n";

		while (getline(logFile, line)) {
			string date, time, transactionID, amount, account;
			stringstream ss(line);

			getline(ss, date, ',');

			string temp;
			getline(ss, temp, ':');
			getline(ss, transactionID, ',');

			getline(ss, amount, ',');

			getline(ss, temp, ':');
			getline(ss, account);

			const int totalWidth = 120;

			cout <<"|"<< setw(119) <<"|"<< "\n";
			cout <<"|"<< setw(8)<< count << setw(20) <<transactionID <<setw(20) << account << setw(30)<< amount << setw(30) << date << setw(11) <<"|"<< "\n";
			cout <<"|"<< setw(119) <<"|"<< "\n";

			count++;
		}

		weigh();
		logFile.close();
	} else {
		cout << "+======================================================================================================================+" << endl;
		cout << "|                                      ??????????????????????????????????????????                                      |" << endl;
		cout << "|                                      ?  KHONG THE MO FILE LICH SU GIAO DICH   ?                                      |" << endl;
		cout << "|                                      ??????????????????????????????????????????                                      |" << endl;
		cout << "+======================================================================================================================+" << endl;
	}
}

// Xem lại lịch sử giao dịch
void Admin::xemLichSuGiaoDichKhachHang(string soThe) {
	string idBank = soThe.substr(0, 3);
	string transactionFileName = idBank + "_" + soThe + "_transaction_history.txt";
	ifstream transactionFile(transactionFileName);
	if (transactionFile.is_open()) {
		string line;
		cout << "Lich su giao dich cua tai khoan " << soThe << ":" << endl;
		while (getline(transactionFile, line)) {
			cout << line << endl;
		}
		transactionFile.close();
	} else {
		cout << "Khong the mo file lich su giao dich!" << endl;
	}
}

	void Admin::xoaTaiKhoan(string soThe) {
	string idBank = soThe.substr(0, 3);
	ifstream inputFile(idBank + "_information.txt");
	ofstream tempFile(idBank + "_temp.txt");
	bool found = false;

	if (inputFile.is_open() && tempFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			stringstream ss(line);
			string tk;
			getline(ss, tk, ',');
			if (tk != soThe) {
				tempFile << line << endl;
			} else {
				found = true;
			}
		}
		inputFile.close();
		tempFile.close();
		remove((idBank + "_information.txt").c_str());
		rename((idBank + "_temp.txt").c_str(), (idBank + "_information.txt").c_str());
	} else {
		cout << "!!!!!!!!Khong the mo file de xoa!!!!!!!!" << endl;
	}

	if (found) {
		weigh();
		cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|" << "\n";
		cout <<"|"<< setw(39) << (char)186 << "       TAI KHOAN DA DUOC TAO XOA        " << (char)186   << setw(39) <<"|"<< "\n";
		cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";
		weigh();
	} else {
		cout << "!!!!!!!!Tai khoan khong ton tai!!!!!!!!" << endl;
	}
}
// Chọn cây ATM
void Admin::chonATM(ATM& atm) {
	inDanhSachATM();
	int atmChoice;
	cout << "Lua chon ATM: ";
	cin >> atmChoice;

	ifstream atmInfoFile("atm_info.txt");
	string line;
	int count = 1;
	while (getline(atmInfoFile, line)) {
		if (count == atmChoice) {
			stringstream ss(line);
			string idATM, diaChi, nganHangQuanLy, trangThaiStr;
			float soDuATM;
			bool trangThaiHoatDong;

			getline(ss, idATM, ',');
			ss >> soDuATM;
			getline(ss, diaChi, ',');
			getline(ss, trangThaiStr, ',');
			trangThaiHoatDong = (trangThaiStr == "Hoat Dong");
			getline(ss, nganHangQuanLy, ',');

			atm = ATM(idATM, soDuATM, diaChi, trangThaiHoatDong, nganHangQuanLy);
			break;
		}
		count++;
	}
}
