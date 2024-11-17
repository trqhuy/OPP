#include "Customer.h"


using namespace std;
Customer::Customer(string soThe, string tenChuThe, string pin, int soDu)
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

int Customer::getSoDu() {
	return soDu;
}

