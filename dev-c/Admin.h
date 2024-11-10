#ifndef ADMIN_H
#define ADMIN_H

#include "ATM.h"


using namespace std;

class Admin {
	private:
		vector<ATM> danhSachATM;
		
		bool isValidSoThe(const string& soThe);
        bool isValidTenChuThe(const string& tenChuThe);
        bool isValidPin(const string& pin);
        bool isValidSoDu(double soDu);

	public:

		void themATM(ATM atm);
		void inDanhSachATM();
		void themKhachHang(Customer& customer);
		void taoNganHang(string idBank);
		void xemLichSuGiaoDich(string idBank);
		void xemLichSuGiaoDichKhachHang(string soThe);
		void xemLichSuGiaoDichATM(string idATM);
		void xoaTaiKhoan(string soThe);
		void chonATM(ATM& atm);
		void xoaATM();
		void thayDoiThongTinATM();
		void xoaNganHang(string idBank);
		
		
};

#endif












































































