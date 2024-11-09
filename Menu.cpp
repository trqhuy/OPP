#include"Menu.h"
#include <conio.h>
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

void Print_Menu() {
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "              QUAN LY ATM               " << (char)186 << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)204 << string(40, (char)205) << (char)185 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 1. NGAN HANG                           " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 2. TAI KHOAN NGAN HANG                 " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 3. ATM                                 " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 0. Thoat                               " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) <<"|"<< "\n";
	weigh();
	cout <<"Nhap lua chon cua ban ->";
}

void Print_Menu_1() {//Ngan hang
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "               NGAN HANG                " << (char)186 << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)204 << string(40, (char)205) << (char)185 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 1. Tao ngan hang                       " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 2. Xoa Ngan Hang                       " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 3. In lich su giao dich cua ngan hang  " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 0. Thoat                               " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) <<"|"<< "\n";
	weigh();
	cout <<"Nhap lua chon cua ban ->";
}

void Print_Menu_2() {//Tai khoan ngan hang
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "         TAI KHOAN NGAN HANG            " << (char)186 << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)204 << string(40, (char)205) << (char)185 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 1. Tao tai khoan ngan hang             " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 2. Xoa tai khoan Ngan Hang             " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 3. Rut tien tu cay ATM                 " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 4. Nap tien tu cay ATM                 " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 5. In lich su giao dich cua tai khoan  " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 0. Thoat                               " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) <<"|"<< "\n";
	weigh();
	cout <<"Nhap lua chon cua ban ->";
}

void Print_Menu_3() {//ATM
	weigh();
	cout <<"|"<< setw(39) << (char)201 << string(40, (char)205) << (char)187 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << "                 ATM                    " << (char)186 << setw(39) <<"|"<< "\n";
	cout <<"|"<< setw(39) << (char)204 << string(40, (char)205) << (char)185 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 1. Tao cay ATM                         " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 2. Xoa cay ATM                         " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 3. In danh sach cac cay ATM            " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 4. In lich su giao dich cua ATM        " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 5. Thay doi thong tin cua ATM          " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)186 << " 0. Thoat                               " << (char)186 << setw(39) <<"|" << "\n";
	cout <<"|"<< setw(39) << (char)200 << string(40, (char)205) << (char)188 << setw(39) <<"|"<< "\n";
	weigh();
	cout <<"Nhap lua chon cua ban ->";
}


void Oder1_1(Admin admin) {//tao ngan hang
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


void Oder2_1(Admin admin) {//tao tai khoan ngan hang
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

void Oder2_2(Admin admin) {//xoa tai khoan ngan hang

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
	} 
	else if (atm.timSTK(soThe) && atm.checkPIN(PIN)) {
		cout << "Nhap so tien can rut: ";
		cin >> soTien;
		atm.rutTien(soTien);
	} else {
		cout << "So the hoac PIN khong dung." << endl;
	}
	wait();
}

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

void Oder3_1(Admin admin) {//tao cay ATM
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

























