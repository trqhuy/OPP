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


//#include "Customer.h"
//
//// Constructor definition
//Customer::Customer(string soThe, string tenChuThe, string pin, float soDu)
//    : soThe(soThe), tenChuThe(tenChuThe), PIN(pin), soDu(soDu) {}
//
//// Getter method for card number
//string Customer::getSoThe() const {
//    return soThe;
//}
//
//// Getter method for cardholder's name
//string Customer::getTenChuThe() const {
//    return tenChuThe;
//}
//
//// Getter method for PIN (be cautious with this in production)
//string Customer::getPin() const {
//    return PIN;
//}
//
//// Getter method for balance
//float Customer::getSoDu() const {
//    return soDu;
//}
//
//// Setter method for updating balance
//void Customer::setSoDu(float newSoDu) {
//    soDu = newSoDu;  // You can add validation here if needed (e.g., prevent negative balances)
//}