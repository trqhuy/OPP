#ifndef ATM_H
#define ATM_H


#include "Customer.h"
#include <string>
#include <vector>//thư viện lấy vector
#include <fstream>//ham mo file
#include <sstream>//ham xu ly chuoi, dung de tach chuoi
#include <ctime>//ham lay thoi gian
#include <iostream>
#include <iomanip>//tao so ngau nhien
#include <cstdlib>
#include <windows.h>
#include <string.h>
//#include "Menu.h"


using namespace std;

void weigh1();


class ATM {
	private:
		Customer Cust;
		string idATM;
		int soDuATM;
		string diaChi;
		bool trangThaiHoatDong;
	public:
		// đoạn xử lý thông tin ATM
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
		
		
		// phương thức thực hiện chức năng ATM
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