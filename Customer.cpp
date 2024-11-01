#include "Customer.h"
using namespace std;
Customer::Customer(string soThe, string tenChuThe, string pin, float soDu)
    : soThe(soThe), tenChuThe(tenChuThe), PIN(pin), soDu(soDu) {}

string Customer::getSoThe() { //lay so the
    return soThe;
}

string Customer::getTenChuThe() { //lay ten chu the
    return tenChuThe;
}

string Customer::getPin() { //lay so pin
    return PIN;
}

float Customer::getSoDu() { //lay so du
    return soDu;
}

void Customer::setSoDu(float newSoDu) { //kiem tra so du
    soDu = newSoDu;
}

