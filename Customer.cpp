#include "Customer.h"

Customer::Customer(std::string soThe, std::string tenChuThe, std::string pin, float soDu)
    : soThe(soThe), tenChuThe(tenChuThe), PIN(pin), soDu(soDu) {}

std::string Customer::getSoThe() {
    return soThe;
}

std::string Customer::getTenChuThe() {
    return tenChuThe;
}

std::string Customer::getPin() {
    return PIN;
}

float Customer::getSoDu() {
    return soDu;
}

void Customer::setSoDu(float newSoDu) {
    soDu = newSoDu;
}

