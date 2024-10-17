#ifndef ADMIN_H
#define ADMIN_H

#include "ATM.h"
#include <vector>

class Admin {
public:
    std::vector<ATM> danhSachATM;

    void themATM(ATM atm);
    void inDanhSachATM();
    void themKhachHang(Customer& customer);
    void taoNganHang(std::string idBank);
    void xemLichSuGiaoDich(std::string idBank);
    void xemLichSuGiaoDichKhachHang(std::string soThe);
    void xoaTaiKhoan(std::string soThe);
    void chonATM(ATM& atm);
};

#endif

