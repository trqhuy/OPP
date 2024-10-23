#ifndef ADMIN_H
#define ADMIN_H

#include "ATM.h"
#include "Customer.h"
#include <vector>

using namespace std;

class Admin {
public:
    vector<ATM> danhSachATM;

    void themATM(ATM atm);
    void inDanhSachATM();
    void themKhachHang(Customer& customer);
    void taoNganHang(string idBank);
    void xemLichSuGiaoDich(string idBank);
    void xemLichSuGiaoDichKhachHang(string soThe);
    void xoaTaiKhoan(string soThe);
    void chonATM(ATM& atm);
};

#endif

