#include"Menu.h"
using namespace std;

#include <conio.h> // Ch? s? d?ng trong m?t s? tr?nh bi�n d?ch
// Hàm chờ người dùng nhấn phím bất kì để tiếp tục
int wait() {
    cout << setw(60+27) << "--------------Nhan phim bat ki de thoat--------------\n";
    getch();
    return 0;
}

// Tạo dao diện
void weigh() {
	cout << "+";
	for(int i=0; i<118; i++) cout<<"=";
	cout << "+" << "\n";
}

//in menu
void Print_Menu() {
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "              QUAN LY ATM               " << (char)186 << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)204 << string(40, (char)205) << (char)185 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 1. Tao ngan hang moi                   " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 2. In lich su giao dich cua ngan hang  " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 3. Them tai khoan ngan hang            " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 4. Xoa tai khoan ngan hang             " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 5. Rut tien tu tai khoan               " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 6. Nap tien vao tai khoan              " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 7. Tao ATM                             " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 8. In danh sach ATM                    " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 0. Thoat                               " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) <<"|"<< "\n";
	weigh();
	cout <<"Nhap lua chon cua ban ->";
}

// Hàm tạo ngân hàng mới
void Oder_1(Admin admin) {
	system("cls");
	string idBank;
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "          TAO NGAN HANG MOI             " << (char)186   << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";
	weigh();
	cout <<"Nhap ID ngan hang can tao ->";
	cin >> idBank;
	admin.taoNganHang(idBank);
	wait();
}

// Hàm in lịch sử giao dịch của ngân hàng
void Oder_2(Admin admin) {
	system("cls");
	string idBank;
	cout << "Nhap ID ngan hang ->";
	cin >> idBank;
	admin.xemLichSuGiaoDich(idBank);
	wait();
}
// Hàm thêm tài khoảng ngân hàng mới
void Oder_3(Admin admin) {
	system("cls");
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "      TAO TAI KHOAN NGAN HANG MOI       " << (char)186   << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";
	weigh();
	
	string soThe, tenChuThe, pin;
	float soDu;
	cout << "Nhap so the (3 so dau se la ID ngan hang)->";
	cin >> soThe;
	cout << "Nhap ten chu the ->";
	cin.ignore();
	getline(cin, tenChuThe);
	cout << "Nhap ma PIN ->";
	cin >> pin;
	cout << "Nhap so du ->";
	cin >> soDu;

	Customer newCustomer(soThe, tenChuThe, pin, soDu);
	admin.themKhachHang(newCustomer);
	wait();
}

void Oder_4(Admin admin) {
	
	system("cls");
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 						<< setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)186 << "       XOA TAI KHOAN NAGN HANG          " << (char)186   << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 						<< setw(39) <<"|"<< "\n";
	weigh();
	
	string soThe;
	cout << "Nhap so the-> ";
	cin >> soThe;
	admin.xoaTaiKhoan(soThe);
	wait();
}

void Oder_5(Admin admin) {
	string soThe, PIN;
	float soTien;
	cout << "Nhap so the: ";
	cin >> soThe;
	cout << "Nhap ma PIN: ";
	cin >> PIN;

	ATM atm("", 0, "", false, "");
	admin.chonATM(atm);

	if (atm.timSTK(soThe) && atm.checkPIN(PIN)) {
		cout << "Nhap so tien can rut: ";
		cin >> soTien;
		atm.rutTien(soTien);
	} else {
		cout << "So the hoac PIN khong dung." << endl;
	}
	wait();
}

void Oder_6(Admin admin) {
	string soThe;
	float soTien;
	cout << "Nhap so the: ";
	cin >> soThe;

	cout << "Chon ATM:\n";
	admin.inDanhSachATM();
	int atmChoice;
	cout << "Lua chon ATM: ";
	cin >> atmChoice;

	if (atmChoice > 0 && atmChoice <= admin.danhSachATM.size()) {
		ATM& atm = admin.danhSachATM[atmChoice - 1];
		cout << "Nhap so tien can nap: ";
		cin >> soTien;
		if (atm.timSTK(soThe)) {
			atm.napTien(soTien);
		} else {
			cout << "So the khong dung." << endl;
		}
	} else {
		cout << "Lua chon ATM khong hop le." << endl;
	}
	wait();
}
// tạo và thêm một cây ATM mới vào danh sách quản lý
void Oder_7(Admin admin) {
	string idATM, diaChi, nganHangQuanLy;
	float soDuATM;
	bool trangThai;

	cout << "Nhap ID ATM: ";
	cin >> idATM;
	cout << "Nhap so du ATM: ";
	cin >> soDuATM;
	cout << "Nhap dia chi ATM: ";
	cin.ignore();
	getline(cin, diaChi);
	cout << "Nhap trang thai ATM (1 cho hoat dong, 0 cho khong hoat dong): ";
	cin >> trangThai;
	cout << "Nhap ID ngan hang quan ly: ";
	cin >> nganHangQuanLy;

	ATM newATM(idATM, soDuATM, diaChi, trangThai, nganHangQuanLy);
	admin.themATM(newATM);
	wait();
}

void Oder_8(Admin admin) {
	admin.inDanhSachATM();
	wait();
}
