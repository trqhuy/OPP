#include <iostream>
#include<windows.h>
#include "Admin.h"
#include "Customer.h"
#include "ATM.h"
using namespace std;

int main() {
	Admin admin;
	int choice;

	do {
		cout << "Chon thao tac:\n";
		cout << "1. Tao ngan hang moi\n";
		cout << "2. In lich su giao dich cua ngan hang\n";
		cout << "3. Them tai khoan ngan hang\n";
		cout << "4. Xoa tai khoan ngan hang\n";
		cout << "5. Rut tien tu tai khoan\n";
		cout << "6. Nap tien vao tai khoan\n";
		cout << "7. Tao ATM\n";
		cout << "8. In danh sach ATM\n";
		cout << "0. Thoat\n";
		cout << "Lua chon: ";
		cin >> choice;

		switch (choice) {
			case 1: {
				string idBank;
				cout << "Nhap ID ngan hang: ";
				cin >> idBank;
				admin.taoNganHang(idBank);
				Sleep(3000);
    			system("cls");
				break;
			}
			case 2: {
				string idBank;
				cout << "Nhap ID ngan hang: ";
				cin >> idBank;
				admin.xemLichSuGiaoDich(idBank);
				Sleep(3000);
    			system("cls");
				break;
			}
			case 3: {
				string soThe, tenChuThe, pin;
				float soDu;
				cout << "Nhap so the: ";
				cin >> soThe;
				cout << "Nhap ten chu the: ";
				cin.ignore();
				getline(cin, tenChuThe);
				cout << "Nhap ma PIN: ";
				cin >> pin;
				cout << "Nhap so du: ";
				cin >> soDu;

				Customer newCustomer(soThe, tenChuThe, pin, soDu);
				admin.themKhachHang(newCustomer);
				break;
			}
			case 4: {
				string soThe;
				cout << "Nhap so the: ";
				cin >> soThe;
				admin.xoaTaiKhoan(soThe);
				Sleep(3000);
    			system("cls");
				break;
			}
			case 5: {
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
				Sleep(3000);
    			system("cls");
				break;
			}

			case 6: {
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
				Sleep(3000);
    			system("cls");
				break;
			}
			case 7: {
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
				Sleep(3000);
    			system("cls");
				break;
			}
			case 8: {
				admin.inDanhSachATM();
				Sleep(3000);
    			system("cls");
				break;
			}
			case 0:
				cout << "Thoat chuong trinh." << endl;
				break;
			default:
				cout << "Lua chon khong hop le. Vui long chon lai." << endl;
		}
		cout << endl;
	} while (choice != 0);

	return 0;
}
