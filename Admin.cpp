#include "Admin.h"
#include "ATM.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

void Admin::themATM(ATM atm) {
	danhSachATM.push_back(atm);
	atm.ghiThongTinATM();
	cout << "ATM " << atm.idATM << " da duoc tao." << endl;
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
		cout << "Them thong tin khach hang thanh cong." << endl;
	} else {
		cout << "Khong the mo file de ghi!" << endl;
	}
}

void Admin::taoNganHang(string idBank) {
	ofstream bankFile(idBank + "_information.txt");
	if (bankFile.is_open()) {
		cout << "Ngan hang " << idBank << " da duoc tao." << endl;
		bankFile.close();
	} else {
		cout << "Khong the tao ngan hang!" << endl;
	}
}

void Admin::xemLichSuGiaoDich(string idBank) {
	ifstream logFile(idBank + "_transaction_history.txt");
	if (logFile.is_open()) {
		string line;
		cout << "Lich su giao dich cua ngan hang " << idBank << ":" << endl;
		while (getline(logFile, line)) {
			cout << line << endl;
		}
		logFile.close();
	} else {
		cout << "Khong the mo file lich su giao dich!" << endl;
	}
}

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
		cout << "Khong the mo file de xoa!" << endl;
	}

	if (found) {
		cout << "Xoa tai khoan " << soThe << " thanh cong." << endl;
	} else {
		cout << "Tai khoan khong ton tai." << endl;
	}
}

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
