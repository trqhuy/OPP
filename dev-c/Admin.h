#ifndef ADMIN_H
#define ADMIN_H

#include "ATM.h"
#include "Menu.h"
#include "Customer.h"

#include <vector>


using namespace std;

class Admin {
	private:
		vector <ATM> danhSachATM;
		
		bool isValidSoThe(const string& soThe);
        bool isValidTenChuThe(const string& tenChuThe);
        bool isValidPin(const string& pin);
        bool isValidSoDu(double soDu);
        
        bool isValidLaiSuat_TietKiem(float LaiSuat);
        bool isValidKiHan_TietKiem(int KiHan);
        bool isValidSoTien_VayVon(float SoTienVayVon);
        bool isValidLaiSuat_VayVon(double LaiSuat);
        

	public:

		void themATM(ATM atm);
		void inDanhSachATM();
		void chonATM(ATM& atm);
		void xoaATM();
		void thayDoiThongTinATM();
		
		
		void themKhachHang(Customer& customer);
		void xoaTaiKhoan(string soThe);
		void themKhachHangTietKiem(TaiKhoanTietKiem& TaiKhoanTietKiem);
		void xoaTaiKhoanTietKiem(string soThe);
		void themKhachHangVayVon(TaiKhoanVayVon& TaiKhoanVayVon);
		void xoaTaiKhoanVayVon(string soThe);
		
		
		void taoNganHang(string idBank);
		void xoaNganHang(string idBank);
		
		
		void xemLichSuGiaoDich(string idBank);
		void xemLichSuGiaoDichKhachHang(string soThe);
		void xemLichSuGiaoDichATM(string idATM);
};

#endif