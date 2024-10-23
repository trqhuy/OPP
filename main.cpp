#include <iostream>
#include<windows.h>
#include "Admin.h"
#include "Customer.h"
#include "ATM.h"
#include "Menu.h"
using namespace std;

int main() {
	Admin admin;
	int choice;

	do {
		Print_Menu();
		cin >> choice;

		switch (choice) {
			case 1: {
				Oder_1(admin);
				system("cls");
				break;
			}
			case 2: {
				Oder_2(admin);
				system("cls");
				break;
			}
			case 3: {
				Oder_3(admin);
				system("cls");
				break;
			}
			case 4: {
				Oder_4(admin);
				system("cls");
				break;
			}
			case 5: {
				Oder_5(admin);
				system("cls");
				break;
			}

			case 6: {
				Oder_6(admin);
				system("cls");
				break;
			}
			case 7: {
				Oder_7(admin);
				system("cls");
				break;
			}
			case 8: {
				Oder_8(admin);
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
