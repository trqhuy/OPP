#ifndef ATM_H
#define ATM_H

#include "Customer.h"
#include <string>
#include <vector>

using namespace std;

class ATM {
	private:
		Customer Cust;
		string idATM;
		float soDuATM;
		string diaChi;
		bool trangThaiHoatDong;
		string nganHangQuanLy;
	public:
//		Customer Cust;
//		string idATM;
//		float soDuATM;
//		string diaChi;
//		bool trangThaiHoatDong;
//		string nganHangQuanLy;

		ATM(string idATM, float soDuATM, string diaChi, bool trangThai);
		

		bool timSTK(string soThe);
		bool checkPIN(string PIN);
		void ghiLichSuATM(string action, float amount, const string& transactionId);
		void ghiLichSu(string action, float amount, const string& transactionId);
		void ghiLichSuNganHang(string action, float amount, const string& transactionId);
		void rutTien(float soTien);
		void napTien(float soTien);
		void ghiThongTinKhachHang();
		void ghiThongTinATM();
		string generateTransactionId();
		void printReceipt(const string& action, float amount, const string& transactionId);
		void capNhatSoDuATM();
};

#endif
