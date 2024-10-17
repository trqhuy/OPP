#ifndef ATM_H
#define ATM_H

#include "Customer.h"
#include <string>
#include <vector>

class ATM {
public:
    Customer Cust;
    std::string idATM;
    float soDuATM;
    std::string diaChi;
    bool trangThaiHoatDong;
    std::string nganHangQuanLy;

    ATM(std::string idATM, float soDuATM, std::string diaChi, bool trangThai, std::string nganHang);
    
    bool timSTK(std::string soThe);
    bool checkPIN(std::string PIN);
    void ghiLichSu(std::string action, float amount, const std::string& transactionId);
    void ghiLichSuNganHang(std::string action, float amount, const std::string& transactionId);
    void rutTien(float soTien);
    void napTien(float soTien);
    void ghiThongTinKhachHang();
    void ghiThongTinATM();
    std::string generateTransactionId();
    void printReceipt(const std::string& action, float amount, const std::string& transactionId);
    void capNhatSoDuATM();
};

#endif
