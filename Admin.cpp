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

		weigh();
		cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|" << "\n";
		cout <<"|"<< setw(39) << (char)186 << "           DANH SACH CAY ATM            " << (char)186   << setw(39) <<"|"<< "\n";
		cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";

		weigh();
		cout << "|" << setw(8) << "STT" << setw(20) << "ID ATM"
		     << setw(20) << "So du ATM" << setw(30) << "Dia chi ATM"
		     << setw(30) << "Trang thai hoat dong" << setw(11) << "|" << "\n";
		cout << "|" << setfill('-') << setw(119) << "|" << setfill(' ') << "\n";

		while (getline(atmInfoFile, line)) {
			string ID, soDu, diaChi, trangThai;
			stringstream ss(line);

			getline(ss, ID, ',');
			getline(ss, soDu, ',');
			getline(ss, diaChi, ',');
			getline(ss, trangThai);

			cout << "|" << setw(8) << count << setw(20) << ID
			     << setw(20) << soDu << setw(30) << diaChi
			     << setw(30) << trangThai << setw(11) << "|" << "\n";

			count++;
		}


		weigh();
	} else {
		cout << "+======================================================================================================================+" << endl;
		cout << "|                                      ??????????????????????????????????????????                                      |" << endl;
		cout << "|                                      ?  KHONG THE MO FILE LICH SU GIAO DICH   ?                                      |" << endl;
		cout << "|                                      ??????????????????????????????????????????                                      |" << endl;
		cout << "+======================================================================================================================+" << endl;
	}
}


void Admin::themKhachHang(Customer& customer) {
	string idBank = customer.getSoThe().substr(0, 3);
//	string idBank = customer.getSoThe();
	ofstream outputFile(idBank + "_information.txt", ios::app);
	if (outputFile.is_open()) {
		outputFile << customer.getSoThe() << ","
		           << customer.getTenChuThe() << ","
		           << customer.getPin() << ","
		           << fixed << setprecision(0) << customer.getSoDu() << endl;
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

void Admin::xoaNganHang(string idBank) {
    system("cls");
    string fileName = idBank + "_information.txt";
    if (remove(fileName.c_str()) != 0) {
        cout << "!!!!!!!!Khong the xoa ngan hang!!!!!!!!" << endl;
    } else {
        weigh();
        cout << "|" << setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) << "|" << "\n";
        cout << "|" << setw(39) << (char)186 << "       NGAN HANG DA DUOC XOA          " << (char)186 << setw(39) << "|" << "\n";
        cout << "|" << setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) << "|" << "\n";
        weigh();
    }
}

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


void Admin::xemLichSuGiaoDichKhachHang(string soThe) {
	string idBank = soThe.substr(0, 3);
	string transactionFileName = idBank + "_" + soThe + "_transaction_history.txt";
	ifstream transactionFile(transactionFileName);
	if (transactionFile.is_open()) {
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

		while (getline(transactionFile, line)) {
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
			cout <<"|"<< setw(8)<< count << setw(20) <<transactionID <<setw(20) << soThe << setw(30)<< amount << setw(30) << date << setw(11) <<"|"<< "\n";
			cout <<"|"<< setw(119) <<"|"<< "\n";

			count++;
		}

		weigh();
		transactionFile.close();
	} else {
		cout << "+======================================================================================================================+" << endl;
		cout << "|                                      ??????????????????????????????????????????                                      |" << endl;
		cout << "|                                      ?  KHONG THE MO FILE LICH SU GIAO DICH   ?                                      |" << endl;
		cout << "|                                      ??????????????????????????????????????????                                      |" << endl;
		cout << "+======================================================================================================================+" << endl;
	}
}

void Admin::xemLichSuGiaoDichATM(string idATM) {
	ifstream logFile(idATM + "_transaction_history.txt");
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
			getline(ss, trangThaiStr, ',');
			if(trangThaiStr == "Hoat Dong") trangThaiHoatDong =true;
			getline(ss, nganHangQuanLy, ',');

			atm = ATM(idATM, soDuATM, diaChi, trangThaiHoatDong);
			break;
		}
		count++;
	}
}

void Admin::xoaATM() {
	inDanhSachATM();
	int atmChoice;
	cout << "Lua chon ATM: ";
	cin >> atmChoice;

	ifstream atmInfoFile("atm_info.txt");
	string line;
	int count = 1;
	bool atmFound = false;

	if (!atmInfoFile.is_open()) {
		cout << "!!!!!!!!Khong the mo file atm_info.txt!!!!!!!!" << endl;
		return;
	}

	ofstream tempFile("atm_temp.txt");

	while (getline(atmInfoFile, line)) {
		if (count == atmChoice) {
			atmFound = true;
		} else {
			tempFile << line << endl;
		}
		count++;
	}

	atmInfoFile.close();
	tempFile.close();

	if (atmFound) {
		remove("atm_info.txt");
		rename("atm_temp.txt", "atm_info.txt");
		weigh();
		cout << "|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) <<"|" << "\n";
		cout << "|"<< setw(39) << (char)186 << "       ATM DA DUOC XOA THANH CONG       " << (char)186 << setw(39) <<"|" << "\n";
		cout << "|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) <<"|" << "\n";
		weigh();
	} else {
		cout << "!!!!!!!!ATM khong ton tai!!!!!!!!" << endl;
	}
}

void Admin::thayDoiThongTinATM() {
    inDanhSachATM();
    int atmChoice;
    cout << "Lua chon ATM: ";
    cin >> atmChoice;
 
    ifstream atmInfoFile("atm_info.txt");
    if (!atmInfoFile.is_open()) {
        cout << "Khong the mo file atm_info.txt." << endl;
        return;
    }
 
    string line;
    int count = 1;
    bool atmFound = false;
    ATM atm("", 0.0, "", false);
 
    while (getline(atmInfoFile, line)) {
        if (count == atmChoice) {
            stringstream ss(line);
            string idATM, diaChi, trangThaiStr;
            float soDuATM;
            bool trangThaiHoatDong;
 
            getline(ss, idATM, ',');
            ss >> soDuATM;
            ss.ignore();
            getline(ss, diaChi, ',');
            getline(ss, trangThaiStr);
            trangThaiHoatDong = (trangThaiStr == "Hoat Dong");
 
            atm = ATM(idATM, soDuATM, diaChi, trangThaiHoatDong);
            atmFound = true;
            break;
        }
        count++;
    }
    atmInfoFile.close();
 
    if (!atmFound) {
        cout << "ATM khong ton tai!" << endl;
        return;
    }
 
    system("cls");
    cout << "Chon thong tin can thay doi:" << endl;
    cout << "1. So du\n2. Dia chi\n3. Trang thai\nLua chon: ";
    int luaChon;
    cin >> luaChon;
 
    switch (luaChon) {
        case 1: {
            cout << "Nhap so du moi: ";
            cin >> atm.soDuATM;
            break;
        }
        case 2: {
            cout << "Nhap dia chi moi: ";
            cin.ignore();
            getline(cin, atm.diaChi);
            break;
        }
        case 3: {
            cout << "Nhap trang thai moi (1 = Hoat Dong, 0 = Khong Hoat Dong): ";
            int trangThaiMoi;
            cin >> trangThaiMoi;
            atm.trangThaiHoatDong = (trangThaiMoi == 1);
            break;
        }
        default:
            cout << "Lua chon khong hop le!" << endl;
            return;
    }
 
    ifstream inputFile("atm_info.txt");
    ofstream tempFile("atm_temp.txt");
 
    if (!inputFile.is_open() || !tempFile.is_open()) {
        cout << "Khong the mo file de cap nhat thong tin ATM!" << endl;
        return;
    }
 
    count = 1;
    while (getline(inputFile, line)) {
        if (count == atmChoice) {
            string trangThaiStr = atm.trangThaiHoatDong ? "Hoat Dong" : "Khong Hoat Dong";
            tempFile << atm.idATM << "," << fixed << setprecision(0) << atm.soDuATM << "," << atm.diaChi << "," << trangThaiStr << endl;
        } else {
            tempFile << line << endl;
        }
        count++;
    }
 
    inputFile.close();
    tempFile.close();
 
    remove("atm_info.txt");
    rename("atm_temp.txt", "atm_info.txt");
 
    weigh();
    cout << "|" << setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) << "|" << "\n";
    cout << "|" << setw(39) << (char)186 << " THONG TIN ATM DUOC CAP NHAT THANH CONG " << (char)186 << setw(39) << "|" << "\n";
    cout << "|" << setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) << "|" << "\n";
    weigh();
}










































































































































































































































































































































































































































































































































































































































































