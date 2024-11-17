#ifndef CUSTOMER_H
#define CUSTOMER_H

using namespace std;
#include <string>

class Customer {
	private:
		string soThe, tenChuThe, PIN;
		int soDu;
	public:

		Customer(string soThe, string tenChuThe, string pin, int soDu);

		string getSoThe();
		string getTenChuThe();
		string getPin();
		int getSoDu();

		void set_soThe(string So_The) {
			soThe =So_The;
		}
		void set_tenChuThe(string TenChuThe) {
			tenChuThe =TenChuThe;
		}
		void set_PIN(string pin) {
			PIN=pin;
		}
		void set_SoDu(int newSoDu) {
			soDu=newSoDu;
		}
};

class TaiKhoanTietKiem : public Customer {
	private:
		float laiSuat;
		int kyHan;
	public:
		TaiKhoanTietKiem(string soThe, string tenChuThe, string pin, float soDu, float laiSuat, int kyHan)
			: Customer(soThe, tenChuThe, pin, soDu), laiSuat(laiSuat), kyHan(kyHan) {}

		float getLaiSuat() {
			return laiSuat;
		}
		int getKyHan() {
			return kyHan;
		}

		void setLaiSuat(float newLaiSuat) {
			laiSuat = newLaiSuat;
		}
		void setKyHan(int newKyHan) {
			kyHan = newKyHan;
		}
};

class TaiKhoanVayVon : public Customer {
	private:
		float soTienVay;
		float laiSuatVay;
	public:
		TaiKhoanVayVon(string soThe, string tenChuThe, string pin, float soDu, float soTienVay, float laiSuatVay)
			: Customer(soThe, tenChuThe, pin, soDu), soTienVay(soTienVay), laiSuatVay(laiSuatVay) {}

		float getSoTienVay() {
			return soTienVay;
		}
		float getLaiSuatVay() {
			return laiSuatVay;
		}

		void setSoTienVay(float newSoTienVay) {
			soTienVay = newSoTienVay;
		}
		void setLaiSuatVay(float newLaiSuatVay) {
			laiSuatVay = newLaiSuatVay;
		}
};

#endif