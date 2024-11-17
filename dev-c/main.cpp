#include "Menu.h"

using namespace std;

int main() {
	Admin admin;
	int choice,choice1,choice2,choice3,check_login=2;

	//dang nhap vao phan mem
//	while(true) {
//		if(login()) {
//			system("cls");
//			break;
//		}
//		else if(check_login==0){
//			return 0;
//		}
//		else {
//			cout<<"Ban con "<<check_login<<" lan thu"<<endl;
//			check_login--;
//		}
//		system("cls");
//	}


	do {
		Print_Menu();
		cin >> choice;

		switch (choice) {
			//NGAN HANG
			case 1: {
				system("cls");
				do {
					Print_Menu_1();
					cin >> choice1;

					switch (choice1) {
						//TAO NGAN HANG
						case 1: {
							system("cls");
							Oder1_1(admin);
							system("cls");
							break;
						}
						//XOA NGAN HANG
						case 2: {
							system("cls");
							Oder1_2(admin);
							system("cls");
							break;
						}
						//IN LICH SU GIAO DICH CUA NGAN HANG
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
			//TAI KHON NGAN HANG
			case 2: {
				do {
					system("cls");
					Print_Menu_2();
					cin >> choice2;

					switch (choice2) {
						//TAO TAI KHOAN NGAN HANG
						case 1: {
							do {
								system("cls");
								Oder2_1(admin);
								cin >> choice1;

								switch (choice1) {
									case 1: {
										system("cls");
										Oder2_1_1(admin);
										system("cls");
										break;
									}
									case 2: {
										system("cls");
										Oder2_1_2(admin);
										system("cls");
										break;
									}
									case 3: {
										system("cls");
										Oder2_1_3(admin);
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
						//XOA TAI KHOAN NGAN HANG
						case 2: {
							do {
								system("cls");
								Oder2_2(admin);
								cin >> choice1;

								switch (choice1) {
									case 1: {
										system("cls");
										Oder2_2_1(admin);
										system("cls");
										break;
									}
									case 2: {
										system("cls");
										Oder2_2_2(admin);
										system("cls");
										break;
									}
									case 3: {
										system("cls");
										Oder2_2_3(admin);
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
						//RUT TIEN
						case 3: {
							system("cls");
							Oder2_3(admin);
							system("cls");
							break;
						}
						//NAP TIEN
						case 4: {
							system("cls");
							Oder2_4(admin);
							system("cls");
							break;
						}
						// IN LICH SU GIAO DICH CUA TAI KHOAN
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
			//ATM
			case 3: {
				do {
					system("cls");
					Print_Menu_3();
					cin >> choice3;

					switch (choice3) {
						//TAO ATM
						case 1: {
							Oder3_1(admin);
							system("cls");
							break;
						}
						//XOA ATM
						case 2: {
							Oder3_2(admin);
							system("cls");
							break;
						}
						//IN DANH SACH ATM
						case 3: {
							Oder3_3(admin);
							system("cls");
							break;
						}
						//IN LICH SUA GIAO DICH
						case 4: {
							Oder3_4(admin);
							system("cls");
							break;
						}
						//THAY DOI THONG TIN ATM
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
			//THOAT
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