#include <iostream>
#include<windows.h>
#include "Admin.h"
#include "Customer.h"
#include "ATM.h"
#include "Menu.h"
using namespace std;

int main() {
	Admin admin;
	int choice,choice1,choice2,choice3;

	do {
		Print_Menu();
		cin >> choice;

		switch (choice) {
			case 1: {
				system("cls");
				do {
					Print_Menu_1();
					cin >> choice1;

					switch (choice1) {
						case 1: {
							system("cls");
							Oder1_1(admin);
							system("cls");
							break;
						}
						case 2: {
							system("cls");
							Oder1_2(admin);
							system("cls");
							break;
						}
						case 3: {
							system("cls");
							Oder1_3(admin);
							system("cls");
							break;
						}
						case 0: {
							cout << "Thoat chuong trinh." << endl;
							system("cls");
							break;
						}
						default:
							cout << "Lua chon khong hop le. Vui long chon lai." << endl;
							system("cls");
					}
					cout << endl;
				} while (choice1 != 0);
				break;
			}
			case 2: {
				do {
					system("cls");
					Print_Menu_2();
					cin >> choice2;

					switch (choice2) {
						case 1: {
							system("cls");
							Oder2_1(admin);
							system("cls");
							break;
						}
						case 2: {
							system("cls");
							Oder2_2(admin);
							system("cls");
							break;
						}
						case 3: {
							system("cls");
							Oder2_3(admin);
							system("cls");
							break;
						}
						case 4: {
							system("cls");
							Oder2_4(admin);
							system("cls");
							break;
						}
						case 5: {
							system("cls");
							Oder2_5(admin);
							system("cls");
							break;
						}
						case 0: {
							cout << "Thoat chuong trinh." << endl;
							system("cls");
							break;
						}
						default:
							cout << "Lua chon khong hop le. Vui long chon lai." << endl;
							system("cls");
					}
					cout << endl;
				} while (choice2 != 0);
				break;
			}
			case 3: {
				do {
					system("cls");
					Print_Menu_3();
					cin >> choice3;

					switch (choice3) {
						case 1: {
							Oder3_1(admin);
							system("cls");
							break;
						}
						case 2: {
							Oder3_2(admin);
							system("cls");
							break;
						}
						case 3: {
							Oder3_3(admin);
							system("cls");
							break;
						}
						case 4: {
							Oder3_4(admin);
							system("cls");
							break;
						}
						case 5: {
							Oder3_5(admin);
							system("cls");
							break;
						}
						case 0: {
							cout << "Thoat chuong trinh." << endl;
							system("cls");
							break;
						}
						default:
							cout << "Lua chon khong hop le. Vui long chon lai." << endl;
							system("cls");
					}
					cout << endl;
				} while (choice3 != 0);
				break;
			}
			case 0:
				cout << "Thoat chuong trinh." << endl;
				system("cls");
				break;
			default:
				cout << "Lua chon khong hop le. Vui long chon lai." << endl;
				system("cls");
		}
		cout << endl;
	} while (choice != 0);
	return 0;
}























































