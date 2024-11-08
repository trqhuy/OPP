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
		int soDuATM;
		string diaChi;
		bool trangThaiHoatDong;
	public:
		ATM(string IdATM, int SoDuATM, string DiaChi, bool TrangThai);
		
		void set_soDuATM(int so_du_moi){
			soDuATM =so_du_moi;
		}
		void set_diaChi(string DiaChi) {
			diaChi =DiaChi;
		}
		void set_trangThaiHoatDong(bool trang_Thai_Moi) {
			trangThaiHoatDong =trang_Thai_Moi;
		}
		
		bool get_trangThaiHoatDong(){
			return this->trangThaiHoatDong;
		}
		string get_idATM(){
			return idATM;
		}
		int get_soDuATM(){
			return soDuATM;
		} 
		string get_diaChi(){
			return diaChi;
		} 

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

//#ifndef ATM_H
//#define ATM_H
//
//#include "Customer.h"
//#include <string>
//#include <vector>
//#include <fstream>
//#include <sstream>
//#include <ctime>
//#include <iomanip>
//using namespace std;
//
//class ATM {
//private:
//    Customer Cust;
//    string idATM;
//    float soDuATM;
//    string diaChi;
//    bool trangThaiHoatDong;
//public:
//    ATM(string idATM, float soDuATM, string diaChi, bool trangThai);
//    bool timSTK(string soThe);
//    bool checkPIN(string PIN);
//    void ghiLichSu(string action, float amount, const string& transactionId);
//    void ghiLichSuATM(string action, float amount, const string& transactionId);
//    void ghiLichSuNganHang(string action, float amount, const string& transactionId);
//    void rutTien(float soTien);
//    void napTien(float soTien);
//    void ghiThongTinKhachHang();
//    void ghiThongTinATM();
//    string generateTransactionId();
//    void printReceipt(const string& action, float amount, const string& transactionId);
//    void capNhatSoDuATM();
//};
//
//#endif
