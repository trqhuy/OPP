#include"../header/Menu.h"

using namespace std;

int wait() {
	cout << setw(60+27) << "--------------Nhan phim bat ki de thoat--------------\n";
	getch();
	return 0;
}

void weigh() {
	cout << "+";
	for(int i=0; i<118; i++) cout<<"=";
	cout << "+" << "\n";
}

bool login() {
	int space = 0;
	string username;
	string password;
	int check = 0;
	char ch;

	while (true) {
		weigh();
		cout << "|" << setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) << "|" << "\n";
		cout << "|" << setw(39) << (char)186 << "               DANG NHAP                " << (char)186 << setw(39) << "|" << "\n";
		cout << "|" << setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) << "|" << "\n";
		weigh();

		// Nhập tên đăng nhập
		cout << "Enter username: ";
		getline(cin, username);

		// Nhập mật khẩu và thay thế bằng dấu '*'
		cout << "Enter password: ";
		while ((ch = _getch()) != '\r') {
			if (ch == '\b') {  // Xử lý nếu nhấn phím backspace
				if (!password.empty()) {
					cout << "\b \b";  // Xóa ký tự '*' cuối cùng
					password.pop_back();
				}
			} else {
				password.push_back(ch);
				cout << '*';
			}
		}
		cout<<endl;

		// Mở file chứa dữ liệu đăng nhập
		string Username, Password;
		ifstream inputFile("Admin_information.txt");
		if (inputFile.is_open()) {
			string line;
			while (getline(inputFile, line)) {
				stringstream ss(line);

				getline(ss, Username, ',');
				getline(ss, Password, ',');


				if (Username == username && Password == password) {
					return true;
				}
			}
		}
		return false;
	}
}

void Print_Menu() {
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "              QUAN LY ATM               " << (char)186 << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)204 << string(40, (char)205) << (char)185 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 1. NGAN HANG                           " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 2. TAI KHOAN NGAN HANG                 " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 3. ATM                                 " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 0. Thoat                               " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) <<"|"<< "\n";
	weigh();
	cout <<"Nhap lua chon cua ban ->";
}

void Print_Menu_1() {//Ngan hang
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "               NGAN HANG                " << (char)186 << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)204 << string(40, (char)205) << (char)185 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 1. Tao ngan hang                       " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 2. Xoa Ngan Hang                       " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 3. In lich su giao dich cua ngan hang  " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 0. Thoat                               " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) <<"|"<< "\n";
	weigh();
	cout <<"Nhap lua chon cua ban ->";
}

void Print_Menu_2() {//Tai khoan ngan hang
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "         TAI KHOAN NGAN HANG            " << (char)186 << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)204 << string(40, (char)205) << (char)185 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 1. Tao tai khoan ngan hang             " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 2. Xoa tai khoan Ngan Hang             " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 3. Rut tien tu cay ATM                 " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 4. Nap tien tu cay ATM                 " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 5. In lich su giao dich cua tai khoan  " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 0. Thoat                               " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) <<"|"<< "\n";
	weigh();
	cout <<"Nhap lua chon cua ban ->";
}

void Print_Menu_3() {//ATM
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                 ATM                    " << (char)186 << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)204 << string(40, (char)205) << (char)185 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 1. Tao cay ATM                         " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 2. Xoa cay ATM                         " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 3. In danh sach cac cay ATM            " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 4. In lich su giao dich cua ATM        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 5. Thay doi thong tin cua ATM          " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 0. Thoat                               " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) <<"|"<< "\n";
	weigh();
	cout <<"Nhap lua chon cua ban ->";
}


void Oder1_1(Admin admin) {// TAO NGAN HANG
	system("cls");
	string idBank;
	char choice;  // Biến lưu lựa chọn nhập lại hay thoát

	weigh();
	// In khung giao diện tạo ngân hàng mới
	cout << "|" << setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) << "|" << "\n";
	cout << "|" << setw(39) << (char)186 << "          TAO NGAN HANG MOI             " << (char)186 << setw(39) << "|" << "\n";
	cout << "|" << setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) << "|" << "\n";
	weigh();

	cout << "Nhap ID ngan hang can tao (ID phai la so va co it nhat 3 ki tu)->";

	while (true) {
		cin >> idBank;

		// Kiểm tra ID phải có ít nhất 3 ký tự và tất cả phải là số
		if (idBank.length() >= 3 && all_of(idBank.begin(), idBank.end(), ::isdigit)) {
			break;  // Nếu ID hợp lệ, thoát khỏi vòng lặp
		} else {
			cout << "ID ngan hang khong hop le! ID phai chua it nhat 3 so. Vui long nhap lai: ";
			cout << "Ban co muon nhap lai khong? (Y/N): ";
			cin >> choice;

			// Kiểm tra nếu người dùng muốn nhập lại hay thoát
			if (choice == 'Y' || choice == 'y') {
				cout << "Nhap ID ngan hang can tao ->";
				continue;
			} else if (choice == 'N' || choice == 'n') {
				cout << "Thoat khoi tao ngan hang." << endl;
				return;
			} else {
				cout << "Lua chon khong hop le. Vui long nhap Y de nhap lai hoac N de thoat." << endl;
			}
		}
	}

	admin.taoNganHang(idBank);

	wait();
}

void Oder1_2(Admin admin) {//xoa ngan hang
	system("cls");
	string idBank;
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "            XOA NGAN HANG               " << (char)186   << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";
	weigh();
	cout <<"Nhap ID ngan hang can xao ->";
	cin >> idBank;
	admin.xoaNganHang(idBank);
	wait();
}

void Oder1_3(Admin admin) {//in lich su giao dich cua ngan hang
	system("cls");
	string idBank;
	cout << "Nhap ID ngan hang ->";
	cin >> idBank;
	admin.xemLichSuGiaoDich(idBank);
	wait();
}


void Oder2_1(Admin admin) {
	system("cls");
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "      TAO TAI KHOAN NGAN HANG MOI       " << (char)186   << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)204 << string(40, (char)205) << (char)185 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 1. TAI KHOAN NGAN HANG                 " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 2. TAI KHOAN TIET KIEM                 " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 3. TAI KHOAN VAY VON                   " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 0. Thoat                               " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) <<"|"<< "\n";
	weigh();
	cout <<"Nhap lua chon cua ban ->";
}

void Oder2_1_1(Admin admin) {//tao tai khoan ngan hang
	system("cls");
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "      TAO TAI KHOAN NGAN HANG MOI       " << (char)186   << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";
	weigh();

	Customer newCustomer("", "", "", 0);
	admin.themKhachHang(newCustomer);
	wait();
}

void Oder2_1_2(Admin admin) {//tao tai khoan tiet kiem
	system("cls");
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "      TAO TAI KHOAN TIET KIEM MOI       " << (char)186   << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";
	weigh();
	int soDu;

	TaiKhoanTietKiem newTaiKhoanTietKiem("", "", "", 0, 0, 0);
	admin.themKhachHangTietKiem(newTaiKhoanTietKiem);
	wait();
}

void Oder2_1_3(Admin admin) {//tao tai khoan vay von
	system("cls");
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "       TAO TAI KHOAN VAY VON MOI        " << (char)186   << setw(39) <<"|"<< "\n";
	weigh();
	int soDu;

	TaiKhoanTietKiem newTaiKhoanTietKiem("", "", "", 0, 0, 0);
	admin.themKhachHangTietKiem(newTaiKhoanTietKiem);
	wait();
}


void Oder2_2(Admin admin) {
	system("cls");
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "        XOA TAI KHOAN NGAN HANG         " << (char)186   << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)204 << string(40, (char)205) << (char)185 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 1. TAI KHOAN NGAN HANG                 " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 2. TAI KHOAN TIET KIEM                 " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 3. TAI KHOAN VAY VON                   " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 0. Thoat                               " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                                        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) <<"|"<< "\n";
	weigh();
	cout <<"Nhap lua chon cua ban ->";
}

void Oder2_2_1(Admin admin) {//xoa tai khoan ngan hang

	system("cls");
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)186 << "       XOA TAI KHOAN NGAN HANG          " << (char)186   << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";
	weigh();

	string soThe;
	cout << "Nhap so the-> ";
	cin >> soThe;
	admin.xoaTaiKhoan(soThe);
	wait();
}

void Oder2_2_2(Admin admin) {//xoa tai khoan tiet kiem

	system("cls");
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)186 << "       XOA TAI KHOAN NGAN HANG          " << (char)186   << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";
	weigh();

	string soThe;
	cout << "Nhap so the-> ";
	cin >> soThe;
	admin.xoaTaiKhoanTietKiem(soThe);
	wait();
}

void Oder2_2_3(Admin admin) {//xoa tai khoan tiet kiem

	system("cls");
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)186 << "       XOA TAI KHOAN NGAN HANG          " << (char)186   << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";
	weigh();

	string soThe;
	cout << "Nhap so the-> ";
	cin >> soThe;
	admin.xoaTaiKhoanVayVon(soThe);
	wait();
}

void Oder2_3(Admin admin) {//rut tien tu cay ATM
	string soThe, PIN;
	float soTien;
	cout << "Nhap so the: ";
	cin >> soThe;
	cout << "Nhap ma PIN: ";
	cin >> PIN;

	ATM atm("", 0, "", false);
	admin.chonATM(atm);

	if(atm.get_trangThaiHoatDong() ==false) {
		cout << "ATM khong con hoat dong"<<endl;
	} else if (atm.timSTK(soThe) && atm.checkPIN(PIN)) {
//		cout << "So du hien tai: " << Cust.getSoDu() << " VND" << endl;
		cout << "Nhap so tien can rut: ";
		cin >> soTien;
		atm.rutTien(soTien);
	} else {
		cout << "So the hoac PIN khong dung." << endl;
	}
	wait();
}

//void Oder2_3(Admin admin) {//rut tien tu cay ATM
//	string soThe, PIN;
//	float soTien;
//	cout << "Nhap so the: ";
//	cin >> soThe;
//	cout << "Nhap ma PIN: ";
//	cin >> PIN;
//
//	ATM atm("", 0, "", false);
//	admin.chonATM(atm);
//
//	if(atm.get_trangThaiHoatDong() ==false) {
//		cout << "ATM khong con hoat dong"<<endl;
//	} else if (atm.timSTK(soThe) && atm.checkPIN(PIN)) {
//		//cout << "So du hien tai: " << Cust.getSoDu() << " VND" << endl;
//		cout << "Nhap so tien can rut: ";
//		cin >> soTien;
//		atm.rutTien(soTien);
//	} else {
//		cout << "So the hoac PIN khong dung." << endl;
//	}
//	wait();
//}


void Oder2_4(Admin admin) {//nap tien tu cay ATM
	string soThe, PIN;
	float soTien;
	cout << "Nhap so the: ";
	cin >> soThe;
	cout << "Nhap ma PIN: ";
	cin >> PIN;

	ATM atm("", 0.0, "", false);
	admin.chonATM(atm);

	if (atm.timSTK(soThe) && atm.checkPIN(PIN)) {
		cout << "Nhap so tien can nap: ";
		cin >> soTien;
		atm.napTien(soTien);
	} else {
		cout << "So the hoac PIN khong dung." << endl;
	}
	wait();
}

void Oder2_5(Admin admin) {//in lich su giao dich cua khach hang
	system("cls");
	string account;
	cout<<"Nhap so tai khoan kiem tra lich su gioa dich ->";
	cin>> account;
	admin.xemLichSuGiaoDichKhachHang(account);
	wait();
}


void Oder3_1(Admin admin) {
	string idATM, diaChi, nganHangQuanLy;
	float soDuATM;
	bool trangThai;
	char choice;

	// Kiểm tra ID ATM: phải có ít nhất 3 chữ số
	while (true) {
		cout << "Nhap ID ATM (toi thieu 3 so): ";
		cin >> idATM;

		// Kiểm tra ID ATM có ít nhất 3 ký tự và tất cả là chữ số
		if (idATM.length() >= 3 && all_of(idATM.begin(), idATM.end(), ::isdigit)) {
			break; // Nếu hợp lệ, thoát vòng lặp
		} else {
			cout << "ID ATM khong hop le! ID phai co it nhat 3 so. Vui long nhap lai." << endl;
			cout << "Ban co muon nhap lai? (Y/N): ";
			cin >> choice;
			if (choice == 'N' || choice == 'n') {
				return; // Nếu không muốn nhập lại, thoát khỏi hàm
			}
		}
	}

	// Kiểm tra số dư ATM: phải tối thiểu 1000
	while (true) {
		cout << "Nhap so du ATM (toi thieu 1000): ";
		cin >> soDuATM;

		if (soDuATM >= 1000) {
			break; // Nếu hợp lệ, thoát vòng lặp
		} else {
			cout << "So du ATM phai lon hon hoac bang 1000. Vui long nhap lai." << endl;
			cout << "Ban co muon nhap lai? (Y/N): ";
			cin >> choice;
			if (choice == 'N' || choice == 'n') {
				return;
			}
		}
	}

	// Kiểm tra địa chỉ ATM: phải chỉ chứa chữ cái và dấu cách
	while (true) {
		cout << "Nhap dia chi ATM: ";
		cin.ignore();  // Bỏ qua ký tự newline còn lại trong buffer
		getline(cin, diaChi);

		if (all_of(diaChi.begin(), diaChi.end(), [](char c) {
		return isalpha(c) || c == ' ';
		})) {
			break; // Nếu hợp lệ, thoát vòng lặp
		} else {
			cout << "Dia chi ATM khong hop le! Dia chi chi duoc chua chu cai va dau cach. Vui long nhap lai." << endl;
			cout << "Ban co muon nhap lai? (Y/N): ";
			cin >> choice;
			if (choice == 'N' || choice == 'n') {
				return;
			}
		}
	}

	// Kiểm tra trạng thái ATM
	while (true) {
		cout << "Nhap trang thai ATM (1 cho hoat dong, 0 cho khong hoat dong): ";
		cin >> trangThai;

		if (trangThai == 0 || trangThai == 1) {
			break; // Nếu hợp lệ, thoát vòng lặp
		} else {
			cout << "Trang thai khong hop le! Vui long nhap 1 cho hoat dong hoac 0 cho khong hoat dong." << endl;
			cout << "Ban co muon nhap lai? (Y/N): ";
			cin >> choice;
			if (choice == 'N' || choice == 'n') {
				return;
			}
		}
	}


	ATM newATM(idATM, soDuATM, diaChi, trangThai);
	admin.themATM(newATM);


	wait();
}

void Oder3_2(Admin admin) {//xoa cay ATM

	system("cls");

	admin.xoaATM();

	wait();
}

void Oder3_3(Admin admin) {//in danh sach cac cay ATM

	system("cls");

	admin.inDanhSachATM();

	wait();

}

void Oder3_4(Admin admin) {//in lich su giao dich cua ATM

	string idATM;

	cout << "Nhap ID ATM ->";

	cin >> idATM;

	admin.xemLichSuGiaoDichATM(idATM);

	wait();
}

void Oder3_5(Admin admin) {//thay doi thong tin ATM

	system("cls");

	admin.thayDoiThongTinATM();

	wait();
}
