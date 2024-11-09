#include "Customer.h"
using namespace std;
Customer::Customer(string soThe, string tenChuThe, string pin, float soDu)
	: soThe(soThe), tenChuThe(tenChuThe), PIN(pin), soDu(soDu) {}

string Customer::getSoThe() {
	return soThe;
}

string Customer::getTenChuThe() {
	return tenChuThe;
}

string Customer::getPin() {
	return PIN;
}

float Customer::getSoDu() {
	return soDu;
}

void Customer::set_SoDu(int newSoDu) {
	soDu = newSoDu;
}
















































































