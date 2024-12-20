#include "../header/Menu.h"
using namespace std;

void Admin::themATM(ATM atm) {
	danhSachATM.push_back(atm);
	atm.ghiThongTinATM();
}

void Admin::inDanhSachATM() {
	ifstream atmInfoFile("ATM/atm_info.txt");
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
		cout << "|                                      ?         KHONG THE MO FILE ATM          ?                                      |" << endl;
		cout << "|                                      ??????????????????????????????????????????                                      |" << endl;
		cout << "+======================================================================================================================+" << endl;
	}
}

bool Admin::isValidSoThe(const string& soThe) {
	// Kiểm tra số thẻ phải có đúng 9 ký tự và tất cả là chữ số
	return soThe.length() == 9 && all_of(soThe.begin(), soThe.end(), ::isdigit);
}

bool Admin::isValidTenChuThe(const string& tenChuThe) {
	// Kiểm tra tên chủ thẻ chỉ chứa chữ cái (không có ký tự đặc biệt hoặc số)
	return all_of(tenChuThe.begin(), tenChuThe.end(), [](unsigned char c) {
		return isalpha(c) || c == ' ';
	});
}

bool Admin::isValidPin(const string& pin) {
	// Kiểm tra mã PIN có ít nhất 4 ký tự số
	return pin.length() >= 4 && all_of(pin.begin(), pin.end(), ::isdigit);
}

bool Admin::isValidSoDu(double soDu) {
	// Kiểm tra số dư tài khoản không được dưới 50 VND
	return soDu >= 50;
}

bool Admin::isValidLaiSuat_TietKiem(float LaiSuat) {
    // Kiểm tra lãi suất có hợp lệ không (ví dụ: lãi suất từ 0.0 đến 100.0)
    return LaiSuat >= 0.0 && LaiSuat <= 100.0;
}

bool Admin::isValidKiHan_TietKiem(int KiHan) {
    // Kiểm tra kỳ hạn từ 1 đến 60 tháng
    return KiHan > 0 && KiHan <= 60;
}

bool Admin::isValidSoTien_VayVon(float SoTienVayVon) {
    // Kiểm tra số tiền vay vốn là số dương và nằm trong một giới hạn (ví dụ từ 1 đến 1 tỷ)
    return SoTienVayVon > 0 && SoTienVayVon <= 1000000000;
}

bool Admin::isValidLaiSuat_VayVon(double LaiSuat) {
    // Kiểm tra lãi suất vay vốn nằm trong khoảng từ 0.0% đến 100.0%
    return LaiSuat >= 0.0 && LaiSuat <= 100.0;
}

void Admin::themKhachHang(Customer& customer) {
	string soThe, tenChuThe, pin;
	double soDu;

	// Nhập và kiểm tra số thẻ
	do {
		cout << "Nhap so the (9 ky tu, chi chua so, 3 ky tu dau la id ngan hang): ";
		cin.ignore();
		getline(cin, soThe);
		if (!isValidSoThe(soThe)) {
			cout << "So the khong hop le. Vui long nhap lai (9 ky tu, chi chua so)." << endl;
		}
	} while (!isValidSoThe(soThe));
	customer.set_soThe(soThe);

	// Nhập và kiểm tra tên chủ thẻ
	do {
		cout << "Nhap ten chu the (chi chua chu cai): ";
		getline(cin, tenChuThe);
		if (!isValidTenChuThe(tenChuThe)) {
			cout << "Ten chu the khong hop le. Vui long nhap lai (chi chua chu cai, khong co so hoac ky tu dac biet)." << endl;
		}
	} while (!isValidTenChuThe(tenChuThe));
	customer.set_tenChuThe(tenChuThe);

	// Nhập và kiểm tra mã PIN
	do {
		cout << "Nhap ma PIN (toi thieu 4 ky tu): ";
		getline(cin, pin);
		if (!isValidPin(pin)) {
			cout << "Ma PIN khong hop le. Vui long nhap lai (toi thieu 4 ky tu, chi chua so)." << endl;
		}
	} while (!isValidPin(pin));
	customer.set_PIN(pin);

	// Nhập và kiểm tra số dư tài khoản
	do {
		cout << "Nhap so du tai khoan (50 VND hoac hon): ";
		cin >> soDu;
		if (!isValidSoDu(soDu)) {
			cout << "So du khong hop le. So du toi thieu la 50 VND." << endl;
		}
	} while (!isValidSoDu(soDu));
	customer.set_SoDu(soDu);

	// Tạo file lưu thông tin khách hàng
	string idBank = soThe.substr(0, 3); // lấy 3 ký tự đầu tiên của số thẻ
	string file = "Customer";
	ofstream outputFile( file +"/Bank_" + idBank + "_information.txt", ios::app);
	if (outputFile.is_open()) {
		outputFile << customer.getSoThe() << ","
		           << customer.getTenChuThe() << ","
		           << customer.getPin() << ","
		           << fixed << setprecision(0) << customer.getSoDu() << endl;
		outputFile.close();

		// Vẽ khung thông báo
		weigh();
		cout << "|" << setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) << "|" << "\n";
		cout << "|" << setw(39) << (char)186 << "       TAI KHOAN MOI DA DUOC TAO        " << (char)186 << setw(39) << "|" << "\n";
		cout << "|" << setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) << "|" << "\n";
		weigh();
	} else {
		cout << "!!!!!!!!Khong the tao tai khoan ngan hang!!!!!!!!" << endl;
	}
}

void Admin::themKhachHangTietKiem(TaiKhoanTietKiem& TaiKhoanTietKiem) {
	float laiSuat;
	int kyHan;
	string soThe, tenChuThe, pin;
	double soDu;

	// Nhập và kiểm tra số thẻ
	do {
		cout << "Nhap so the (9 ky tu, chi chua so, 3 ky tu dau la id ngan hang): ";
		cin.ignore();
		getline(cin, soThe);
		if (!isValidSoThe(soThe)) {
			cout << "So the khong hop le. Vui long nhap lai (9 ky tu, chi chua so)." << endl;
		}
	} while (!isValidSoThe(soThe));
	TaiKhoanTietKiem.set_soThe(soThe);

	// Nhập và kiểm tra tên chủ thẻ
	do {
		cout << "Nhap ten chu the (chi chua chu cai): ";
		getline(cin, tenChuThe);
		if (!isValidTenChuThe(tenChuThe)) {
			cout << "Ten chu the khong hop le. Vui long nhap lai (chi chua chu cai, khong co so hoac ky tu dac biet)." << endl;
		}
	} while (!isValidTenChuThe(tenChuThe));
	TaiKhoanTietKiem.set_tenChuThe(tenChuThe);

	// Nhập và kiểm tra mã PIN
	do {
		cout << "Nhap ma PIN (toi thieu 4 ky tu): ";
		getline(cin, pin);
		if (!isValidPin(pin)) {
			cout << "Ma PIN khong hop le. Vui long nhap lai (toi thieu 4 ky tu, chi chua so)." << endl;
		}
	} while (!isValidPin(pin));
	TaiKhoanTietKiem.set_PIN(pin);

	// Nhập và kiểm tra số dư tài khoản
	do {
		cout << "Nhap so du tai khoan (50 VND hoac hon): ";
		cin >> soDu;
		if (!isValidSoDu(soDu)) {
			cout << "So du khong hop le. So du toi thieu la 50 VND." << endl;
		}
	} while (!isValidSoDu(soDu));
	TaiKhoanTietKiem.set_SoDu(soDu);
	
	// Nhập và kiểm tra lai suat
	do {
		cout << "Nhap lai suat tiet kiem ( 0% - 100%  tren 1 thang ): ";
		cin >> laiSuat;
		if (!isValidLaiSuat_TietKiem(laiSuat)) {
			cout << "Lai suat tiet kiem khong hop le. Lai suat phai tu 0-100." << endl;
		}
	} while (!isValidLaiSuat_TietKiem(laiSuat));
	TaiKhoanTietKiem.setLaiSuat(laiSuat);
	
	// Nhập và kiểm tra ki han tiết kiệm 
	do {
		cout << "Nhap Ky han gui tiet kiem ( 0 - 60 thang ): ";
		cin >> kyHan;
		if (!isValidKiHan_TietKiem(kyHan)) {
			cout << "Ky han gui tiet kiem khong hop le. Ky han phai tu 0-60." << endl;
		}
	} while (!isValidKiHan_TietKiem(kyHan));
	TaiKhoanTietKiem.setKyHan(kyHan);

	// Tạo file lưu thông tin khách hàng
	string idBank = soThe.substr(0, 3); // lấy 3 ký tự đầu tiên của số thẻ
	string file = "Customer";
	ofstream outputFile(file +"/Bank_" + idBank + "_Tiet_Kiem_information.txt", ios::app);
	if (outputFile.is_open()) {
		outputFile << TaiKhoanTietKiem.getSoThe() << ","
		           << TaiKhoanTietKiem.getTenChuThe() << ","
		           << TaiKhoanTietKiem.getPin() << ","
		           << fixed << setprecision(0) << TaiKhoanTietKiem.getSoDu() << ","
		           << fixed << setprecision(2) << TaiKhoanTietKiem.getLaiSuat() << ","
		           << fixed << setprecision(0) << TaiKhoanTietKiem.getKyHan()
				   << endl;
		           
		outputFile.close();

		// Vẽ khung thông báo
		weigh();
		cout << "|" << setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) << "|" << "\n";
		cout << "|" << setw(39) << (char)186 << "       TAI KHOAN MOI DA DUOC TAO        " << (char)186 << setw(39) << "|" << "\n";
		cout << "|" << setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) << "|" << "\n";
		weigh();
	} else {
		cout << "!!!!!!!!Khong the tao tai khoan ngan hang!!!!!!!!" << endl;
	}
}

void Admin::themKhachHangVayVon(TaiKhoanVayVon& TaiKhoanVayVon) {
	float soTienVay;
	float laiSuatVay;
	string soThe, tenChuThe, pin;
	double soDu;

	// Nhập và kiểm tra số thẻ
	do {
		cout << "Nhap so the (9 ky tu, chi chua so, 3 ky tu dau la id ngan hang): ";
		cin.ignore();
		getline(cin, soThe);
		if (!isValidSoThe(soThe)) {
			cout << "So the khong hop le. Vui long nhap lai (9 ky tu, chi chua so)." << endl;
		}
	} while (!isValidSoThe(soThe));
	TaiKhoanVayVon.set_soThe(soThe);

	// Nhập và kiểm tra tên chủ thẻ
	do {
		cout << "Nhap ten chu the (chi chua chu cai): ";
		getline(cin, tenChuThe);
		if (!isValidTenChuThe(tenChuThe)) {
			cout << "Ten chu the khong hop le. Vui long nhap lai (chi chua chu cai, khong co so hoac ky tu dac biet)." << endl;
		}
	} while (!isValidTenChuThe(tenChuThe));
	TaiKhoanVayVon.set_tenChuThe(tenChuThe);

	// Nhập và kiểm tra mã PIN
	do {
		cout << "Nhap ma PIN (toi thieu 4 ky tu): ";
		getline(cin, pin);
		if (!isValidPin(pin)) {
			cout << "Ma PIN khong hop le. Vui long nhap lai (toi thieu 4 ky tu, chi chua so)." << endl;
		}
	} while (!isValidPin(pin));
	TaiKhoanVayVon.set_PIN(pin);

	// Nhập và kiểm tra số dư tài khoản
	do {
		cout << "Nhap so du tai khoan (50 VND hoac hon): ";
		cin >> soDu;
		if (!isValidSoDu(soDu)) {
			cout << "So du khong hop le. So du toi thieu la 50 VND." << endl;
		}
	} while (!isValidSoDu(soDu));
	TaiKhoanVayVon.set_SoDu(soDu);
	
	// Nhập và kiểm tra số tiền vay
	do {
		cout << "Nhap so tien vay von (0-1.000.000.000): ";
		cin >> soTienVay;
		if (!isValidSoTien_VayVon(soTienVay)) {
			cout << "So tien vay von khong hop le. So tien vay von phai tu 0-1,000,000,000." << endl;
		}
	} while (!isValidSoTien_VayVon(soTienVay));
	TaiKhoanVayVon.setSoTienVay(soTienVay);
	
	// Nhập và kiểm tra lai suất vay
	do {
		cout << "Nhap Ky han gui tiet kiem ( 0 - 60 thang ): ";
		cin >> laiSuatVay;
		if (!isValidLaiSuat_VayVon(laiSuatVay)) {
			cout << "Ky han gui tiet kiem khong hop le. Ky han phai tu 0-60." << endl;
		}
	} while (!isValidLaiSuat_VayVon(laiSuatVay));
	TaiKhoanVayVon.setLaiSuatVay(laiSuatVay);

	// Tạo file lưu thông tin khách hàng
	string idBank = soThe.substr(0, 3); // lấy 3 ký tự đầu tiên của số thẻ
	string file = "Customer";
	ofstream outputFile(file +"/Bank_" + idBank + "_Vay_Von_information.txt", ios::app);
	if (outputFile.is_open()) {
		outputFile << TaiKhoanVayVon.getSoThe() << ","
		           << TaiKhoanVayVon.getTenChuThe() << ","
		           << TaiKhoanVayVon.getPin() << ","
		           << fixed << setprecision(0) << TaiKhoanVayVon.getSoDu() << ","
		           << fixed << setprecision(0) << TaiKhoanVayVon.getSoTienVay() << ","
		           << fixed << setprecision(2) << TaiKhoanVayVon.getLaiSuatVay()
				   << endl;
		           
		outputFile.close();

		// Vẽ khung thông báo
		weigh();
		cout << "|" << setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) << "|" << "\n";
		cout << "|" << setw(39) << (char)186 << "       TAI KHOAN MOI DA DUOC TAO        " << (char)186 << setw(39) << "|" << "\n";
		cout << "|" << setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) << "|" << "\n";
		weigh();
	} else {
		cout << "!!!!!!!!Khong the tao tai khoan ngan hang!!!!!!!!" << endl;
	}
}


void Admin::taoNganHang(string idBank) {
	string file = "Bank";
	ofstream bankFile(file+"/Bank_" + idBank + "_information.txt");
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
	string file = "Bank";
    string fileName = file + "/Bank_" + idBank + "_information.txt";
	
    if (remove(fileName.c_str()) == 0) {
        weigh();
		cout << "|" << setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) << "|" << "\n";
		cout << "|" << setw(39) << (char)186 << "         NGAN HANG DA DUOC XOA          " << (char)186 << setw(39) << "|" << "\n";
		cout << "|" << setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) << "|" << "\n";
		weigh();
    } else {
        cout << "!!!!!!!!Khong the xoa ngan hang!!!!!!!!" << endl;
    }
}

void Admin::xemLichSuGiaoDich(string idBank) {
	ifstream logFile("Bank/Bank_" + idBank + "_transaction_history.txt");
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
	string transactionFileName = "Customer/Cust_" + soThe + "_transaction_history.txt";
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
	ifstream logFile("ATM/ATM_" + idATM + "_transaction_history.txt");
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
	string file = "Customer";
	ifstream inputFile( file +"/Bank_" + idBank + "_information.txt");
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
		remove(( file +"/Bank_" + idBank + "_information.txt").c_str());
		rename((idBank + "_temp.txt").c_str(), ( file +"/Bank_" + idBank + "_information.txt").c_str());
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

void Admin::xoaTaiKhoanTietKiem(string soThe) {
	string idBank = soThe.substr(0, 3);
	string file = "Customer";
	ifstream inputFile(file +"/Bank_" + idBank + "_Tiet_Kiem_information..txt");
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
		remove((file +"/Bank_" + idBank + "_Tiet_Kiem_information..txt").c_str());
		rename((idBank + "_temp.txt").c_str(), (file +"/Bank_" + idBank + "_Tiet_Kiem_information..txt").c_str());
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

void Admin::xoaTaiKhoanVayVon(string soThe) {
	string idBank = soThe.substr(0, 3);
	string file = "Customer";
	ifstream inputFile(file +"/Bank_" + idBank + "_Vay_Von_information.txt");
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
		remove((file +"/Bank_" + idBank + "_Vay_Von_information.txt").c_str());
		rename((idBank + "_temp.txt").c_str(), (file +"/Bank_" + idBank + "_Vay_Von_information.txt").c_str());
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

	ifstream atmInfoFile("ATM/atm_info.txt");
	if (!atmInfoFile.is_open()) {
		cerr << "Khong the mo file atm_info.txt" << endl;
		return;
	}

	string line;
	int count = 1;
	while (getline(atmInfoFile, line)) {
		if (count == atmChoice) {
			stringstream ss(line);
			string IdATM, DiaChi, NganHangQuanLy, trangThaiStr;
			int SoDuATM;
			bool TrangThaiHoatDong = false;

			getline(ss, IdATM, ',');
			ss >> SoDuATM;
			ss.ignore();
			getline(ss, DiaChi, ',');
			getline(ss, trangThaiStr, ',');
			getline(ss, NganHangQuanLy, ',');

			if (trangThaiStr == "Hoat Dong") TrangThaiHoatDong = true;

			atm = ATM(IdATM, SoDuATM, DiaChi, TrangThaiHoatDong);
			break;
		}
		count++;
	}
	atmInfoFile.close();
}


void Admin::xoaATM() {
	inDanhSachATM();
	int atmChoice;
	cout << "Lua chon ATM: ";
	cin >> atmChoice;

	ifstream atmInfoFile("ATM/atm_info.txt");
	string line;
	int count = 1;
	bool atmFound = false;

	if (!atmInfoFile.is_open()) {
		cout << "!!!!!!!!Khong the mo file atm_info.txt!!!!!!!!" << endl;
		return;
	}

	ofstream tempFile("ATM/atm_temp.txt");

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
		remove("ATM/atm_info.txt");
		rename("ATM/atm_temp.txt", "ATM/atm_info.txt");
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

	ifstream atmInfoFile("ATM/atm_info.txt");
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
			int so_du_moi;
			while (true) {
				cout << "Nhap so du moi (tối thiểu 1000): ";
				cin >> so_du_moi;

				// Kiểm tra số dư phải tối thiểu 1000
				if (so_du_moi >= 1000) {
					atm.set_soDuATM(so_du_moi);
					break;
				} else {
					cout << "So du ATM phai lon hon hoac bang 1000. Vui long nhap lai." << endl;
					cout << "Ban co muon nhap lai? (Y/N): ";
					char choice;
					cin >> choice;
					if (choice == 'N' || choice == 'n') {
						return;
					}
				}
			}
			break;
		}
		case 2: { // Thay đổi địa chỉ ATM
			string diaChi;
			while (true) {
				cout << "Nhap dia chi moi: ";
				cin.ignore();
				getline(cin, diaChi);

				// Kiểm tra địa chỉ chỉ chứa chữ cái và dấu cách
				if (all_of(diaChi.begin(), diaChi.end(), [](char c) {
				return isalpha(c) || c == ' ';
				})) {
					atm.set_diaChi(diaChi);
					break;
				} else {
					cout << "Dia chi ATM khong hop le! Dia chi chi duoc chua chu cai va dau cach. Vui long nhap lai." << endl;
					cout << "Ban co muon nhap lai? (Y/N): ";
					char choice;
					cin >> choice;
					if (choice == 'N' || choice == 'n') {
						return;
					}
				}
			}
			break;
		}
		case 3: { // Thay đổi trạng thái ATM
			int trangThaiMoi;
			while (true) {
				cout << "Nhap trang thai moi (1 = Hoat Dong, 0 = Khong Hoat Dong): ";
				cin >> trangThaiMoi;

				// Kiểm tra trạng thái phải là 0 hoặc 1
				if (trangThaiMoi == 0 || trangThaiMoi == 1) {
					bool trangThaiHoatDong = (trangThaiMoi == 1);
					atm.set_trangThaiHoatDong(trangThaiHoatDong);
					break;
				} else {
					cout << "Trang thai khong hop le! Vui long nhap 1 cho hoat dong hoac 0 cho khong hoat dong." << endl;
					cout << "Ban co muon nhap lai? (Y/N): ";
					char choice;
					cin >> choice;
					if (choice == 'N' || choice == 'n') {
						return;
					}
				}
			}
			break;
		}
		default:
			cout << "Lua chon khong hop le!" << endl;
			break;
	}

	ifstream inputFile("ATM/atm_info.txt");
	ofstream tempFile("ATM/atm_temp.txt");

	if (!inputFile.is_open() || !tempFile.is_open()) {
		cout << "Khong the mo file de cap nhat thong tin ATM!" << endl;
		return;
	}

	count = 1;
	while (getline(inputFile, line)) {
		if (count == atmChoice) {
			string trangThaiStr = atm.get_trangThaiHoatDong() ? "Hoat Dong" : "Khong Hoat Dong";
			tempFile << atm.get_idATM() << "," << fixed << setprecision(0) << atm.get_soDuATM()
			         << "," << atm.get_diaChi() << "," << trangThaiStr << endl;
		} else {
			tempFile << line << endl;
		}
		count++;
	}

	inputFile.close();
	tempFile.close();

	remove("ATM/atm_info.txt");
	rename("ATM/atm_temp.txt", "ATM/atm_info.txt");

	weigh();
	cout << "|" << setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) << "|" << "\n";
	cout << "|" << setw(39) << (char)186 << " THONG TIN ATM DUOC CAP NHAT THANH CONG " << (char)186 << setw(39) << "|" << "\n";
	cout << "|" << setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) << "|" << "\n";
	weigh();
}