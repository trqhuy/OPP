#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Customer {
public:
    string soThe, tenChuThe, PIN;
    float soDu;

    Customer(string soThe, string tenChuThe, string pin, float soDu) 
        : soThe(soThe), tenChuThe(tenChuThe), PIN(pin), soDu(soDu) {}

    string getSoThe() { return soThe; }
    string getTenChuThe() { return tenChuThe; }
    string getPin() { return PIN; }
    float getSoDu() { return soDu; }
    void setSoDu(float newSoDu) { soDu = newSoDu; }
};

class ATM {
public:
    Customer Cust;
    string idATM;
    float soDuATM;
    string diaChi;
    bool trangThaiHoatDong;
    string nganHangQuanLy;

    ATM(string idATM, float soDuATM, string diaChi, bool trangThai, string nganHang)
        : Cust("", "", "", 0), idATM(idATM), soDuATM(soDuATM), diaChi(diaChi), trangThaiHoatDong(trangThai), nganHangQuanLy(nganHang) {}

    bool timSTK(string soThe);
    bool checkPIN(string PIN);
    void ghiLichSu(string action, float amount, const string& transactionId);
    void ghiLichSuNganHang(string action, float amount, const string& transactionId);
    void rutTien(float soTien);
    void napTien(float soTien);
    void ghiThongTinKhachHang();
    void ghiThongTinATM();
    string generateTransactionId();
    void printReceipt(const string& action, float amount, const string& transactionId);
};

bool ATM::timSTK(string soThe) {
    string idBank = soThe.substr(0, 3);
    ifstream inputFile(idBank + "_information.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            stringstream ss(line);
            string tenChuThe, pin;
            float soDu;

            getline(ss, Cust.soThe, ',');
            getline(ss, Cust.tenChuThe, ',');
            getline(ss, Cust.PIN, ',');
            ss >> soDu;

            if (Cust.soThe == soThe) {
                Cust.soDu = soDu;
                return true;
            }
        }
    }
    return false; 
}

bool ATM::checkPIN(string PIN) {
    return Cust.PIN == PIN;
}

void ATM::ghiLichSu(string action, float amount, const string& transactionId) {
    string idBank = Cust.soThe.substr(0, 3);
    string transactionFileName = idBank + "_" + Cust.soThe + "_transaction_history.txt";
    ofstream logFile(transactionFileName, ios::app);
    if (logFile.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now);
        logFile << dt << ": " << action << " - " << amount << " VND, Transaction ID: " << transactionId << endl;
        logFile.close();
    } else {
        cout << "Khong the mo file lich su giao dich!" << endl;
    }
}

void ATM::ghiLichSuNganHang(string action, float amount, const string& transactionId) {
    string idBank = Cust.soThe.substr(0, 3);
    string bankTransactionFileName = idBank + "_transaction_history.txt";
    ofstream bankLogFile(bankTransactionFileName, ios::app);
    if (bankLogFile.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now);
        bankLogFile << dt << ": " << action << " - " << amount << " VND, Tai khoan: " << Cust.soThe << ", Transaction ID: " << transactionId << endl;
        bankLogFile.close();
    } else {
        cout << "Khong the mo file lich su giao dich ngan hang!" << endl;
    }
}

void ATM::ghiThongTinKhachHang() {
    string idBank = Cust.soThe.substr(0, 3);
    string customerFileName = idBank + "_information.txt";
    ifstream inputFile(customerFileName);
    ofstream tempFile(idBank + "_temp.txt");

    if (inputFile.is_open() && tempFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            stringstream ss(line);
            string tk;
            getline(ss, tk, ',');
            if (tk == Cust.soThe) {
                tempFile << Cust.soThe << "," << Cust.tenChuThe << "," << Cust.PIN << "," << Cust.soDu << endl;
            } else {
                tempFile << line << endl;
            }
        }
        inputFile.close();
        tempFile.close();
        remove(customerFileName.c_str());
        rename((idBank + "_temp.txt").c_str(), customerFileName.c_str());
    } else {
        cout << "Khong the mo file de ghi!" << endl;
    }
}

void ATM::ghiThongTinATM() {
    ofstream atmInfoFile(nganHangQuanLy + "_atm_info.txt", ios::app);
    if (atmInfoFile.is_open()) {
        atmInfoFile << idATM << "," << soDuATM << "," << diaChi << "," << (trangThaiHoatDong ? "Hoat Dong" : "Khong Hoat Dong") << "," << nganHangQuanLy << endl;
        atmInfoFile.close();
    } else {
        cout << "Khong the mo file de ghi thong tin ATM!" << endl;
    }
}

string ATM::generateTransactionId() {
    srand(static_cast<unsigned>(time(0)));
    stringstream ss;
    ss << "TX" << setw(6) << setfill('0') << rand() % 1000000;
    return ss.str();
}

void ATM::printReceipt(const string& action, float amount, const string& transactionId) {
    cout << "=== HOA DON GIAO DICH ===" << endl;
    cout << "Ma giao dich: " << transactionId << endl;
    cout << "Loai giao dich: " << action << endl;
    cout << "So tien: " << amount << " VND" << endl;
    cout << "So du sau giao dich: " << Cust.soDu << " VND" << endl;
    cout << "=========================" << endl;
}

void ATM::rutTien(float soTien) {
    if (soTien > Cust.soDu) {
        cout << "So tien rut vuot qua so du!" << endl;
        return;
    }
    Cust.setSoDu(Cust.soDu - soTien);
    string transactionId = generateTransactionId();
    ghiLichSu("Rut tien", soTien, transactionId);
    ghiLichSuNganHang("Rut tien", soTien, transactionId);
    ghiThongTinKhachHang();
    printReceipt("Rut tien", soTien, transactionId);
}

void ATM::napTien(float soTien) {
    Cust.setSoDu(Cust.soDu + soTien);
    string transactionId = generateTransactionId();
    ghiLichSu("Nap tien", soTien, transactionId);
    ghiLichSuNganHang("Nap tien", soTien, transactionId);
    ghiThongTinKhachHang();
    printReceipt("Nap tien", soTien, transactionId);
}

class Admin {
public:
    vector<ATM> danhSachATM;

    void themATM(ATM atm) {
        danhSachATM.push_back(atm);
        atm.ghiThongTinATM();
        cout << "ATM " << atm.idATM << " da duoc tao." << endl;
    }

    void inDanhSachATM() {
        for (size_t i = 0; i < danhSachATM.size(); i++) {
            cout << i + 1 << ". " << danhSachATM[i].idATM << " - " << danhSachATM[i].diaChi << endl;
        }
    }

    void themKhachHang(Customer& customer) {
        string idBank = customer.getSoThe().substr(0, 3);
        ofstream outputFile(idBank + "_information.txt", ios::app);
        if (outputFile.is_open()) {
            outputFile << customer.getSoThe() << "," 
                       << customer.getTenChuThe() << "," 
                       << customer.getPin() << "," 
                       << customer.getSoDu() << endl;
            outputFile.close();
            cout << "Them thong tin khach hang thanh cong." << endl;
        } else {
            cout << "Khong the mo file de ghi!" << endl;
        }
    }

    void taoNganHang(string idBank) {
        ofstream bankFile(idBank + "_information.txt");
        if (bankFile.is_open()) {
            cout << "Ngan hang " << idBank << " da duoc tao." << endl;
            bankFile.close();
        } else {
            cout << "Khong the tao ngan hang!" << endl;
        }
    }

    void xemLichSuGiaoDich(string idBank) {
        ifstream logFile(idBank + "_transaction_history.txt");
        if (logFile.is_open()) {
            string line;
            cout << "Lich su giao dich cua ngan hang " << idBank << ":" << endl;
            while (getline(logFile, line)) {
                cout << line << endl;
            }
            logFile.close();
        } else {
            cout << "Khong the mo file lich su giao dich!" << endl;
        }
    }

    void xemLichSuGiaoDichKhachHang(string soThe) {
        string idBank = soThe.substr(0, 3);
        string transactionFileName = idBank + "_" + soThe + "_transaction_history.txt";
        ifstream transactionFile(transactionFileName);
        if (transactionFile.is_open()) {
            string line;
            cout << "Lich su giao dich cua tai khoan " << soThe << ":" << endl;
            while (getline(transactionFile, line)) {
                cout << line << endl;
            }
            transactionFile.close();
        } else {
            cout << "Khong the mo file lich su giao dich!" << endl;
        }
    }

    void xoaTaiKhoan(string soThe) {
        string idBank = soThe.substr(0, 3);
        ifstream inputFile(idBank + "_information.txt");
        ofstream tempFile(idBank + "_temp.txt");
        bool found = false;

        if (inputFile.is_open() && tempFile.is_open()) {
            string line;
            while (getline(inputFile, line)) {
                stringstream ss(line);
                string tk;
                getline(ss, tk, ',');
                if (tk != soThe) {
                    tempFile << line << endl;
                } else {
                    found = true;
                }
            }
            inputFile.close();
            tempFile.close();
            remove((idBank + "_information.txt").c_str());
            rename((idBank + "_temp.txt").c_str(), (idBank + "_information.txt").c_str());
        } else {
            cout << "Khong the mo file de xoa!" << endl;
        }

        if (found) {
            cout << "Xoa tai khoan " << soThe << " thanh cong." << endl;
        } else {
            cout << "Tai khoan khong ton tai." << endl;
        }
    }
};

int main() {
    Admin admin;
    int choice;

    do {
        cout << "Chon thao tac:\n";
        cout << "1. Tao ngan hang moi\n";
        cout << "2. In lich su giao dich cua ngan hang\n";
        cout << "3. Them tai khoan ngan hang\n";
        cout << "4. Xoa tai khoan ngan hang\n";
        cout << "5. Rut tien tu tai khoan\n";
        cout << "6. Nap tien vao tai khoan\n";
        cout << "7. Tao ATM\n";  
        cout << "8. In danh sach ATM\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string idBank;
                cout << "Nhap ID ngan hang: ";
                cin >> idBank;
                admin.taoNganHang(idBank);
                break;
            }
            case 2: {
                string idBank;
                cout << "Nhap ID ngan hang: ";
                cin >> idBank;
                admin.xemLichSuGiaoDich(idBank);
                break;
            }
            case 3: {
                string soThe, tenChuThe, pin;
                float soDu;
                cout << "Nhap so the: ";
                cin >> soThe;
                cout << "Nhap ten chu the: ";
                cin.ignore();
                getline(cin, tenChuThe);
                cout << "Nhap ma PIN: ";
                cin >> pin;
                cout << "Nhap so du: ";
                cin >> soDu;

                Customer newCustomer(soThe, tenChuThe, pin, soDu);
                admin.themKhachHang(newCustomer);
                break;
            }
            case 4: {
                string soThe;
                cout << "Nhap so the: ";
                cin >> soThe;
                admin.xoaTaiKhoan(soThe);
                break;
            }
            case 5: {
                string soThe, PIN;
                float soTien;
                cout << "Nhap so the: ";
                cin >> soThe;
                cout << "Nhap ma PIN: ";
                cin >> PIN;

                // Hi?n th? danh sách ATM
                cout << "Chon ATM:\n";
                admin.inDanhSachATM();
                int atmChoice;
                cout << "Lua chon ATM: ";
                cin >> atmChoice;

                if (atmChoice > 0 && atmChoice <= admin.danhSachATM.size()) {
                    ATM& atm = admin.danhSachATM[atmChoice - 1];
                    if (atm.timSTK(soThe) && atm.checkPIN(PIN)) {
                        cout << "Nhap so tien can rut: ";
                        cin >> soTien;
                        atm.rutTien(soTien);
                    } else {
                        cout << "So the hoac PIN khong dung." << endl;
                    }
                } else {
                    cout << "Lua chon ATM khong hop le." << endl;
                }
                break;
            }
            case 6: {
                string soThe;
                float soTien;
                cout << "Nhap so the: ";
                cin >> soThe;

                // Hi?n th? danh sách ATM
                cout << "Chon ATM:\n";
                admin.inDanhSachATM();
                int atmChoice;
                cout << "Lua chon ATM: ";
                cin >> atmChoice;

                if (atmChoice > 0 && atmChoice <= admin.danhSachATM.size()) {
                    ATM& atm = admin.danhSachATM[atmChoice - 1];
                    cout << "Nhap so tien can nap: ";
                    cin >> soTien;
                    if (atm.timSTK(soThe)) {
                        atm.napTien(soTien);
                    } else {
                        cout << "So the khong dung." << endl;
                    }
                } else {
                    cout << "Lua chon ATM khong hop le." << endl;
                }
                break;
            }
            case 7: {  
                string idATM, diaChi, nganHangQuanLy;
                float soDuATM;
                bool trangThai;

                cout << "Nhap ID ATM: ";
                cin >> idATM;
                cout << "Nhap so du ATM: ";
                cin >> soDuATM;
                cout << "Nhap dia chi ATM: ";
                cin.ignore();
                getline(cin, diaChi);
                cout << "Nhap trang thai ATM (1 cho hoat dong, 0 cho khong hoat dong): ";
                cin >> trangThai;
                cout << "Nhap ID ngan hang quan ly: ";
                cin >> nganHangQuanLy;

                ATM newATM(idATM, soDuATM, diaChi, trangThai, nganHangQuanLy);
                admin.themATM(newATM); // Thêm ATM vào danh sách
                break;
            }
            case 8: {
                admin.inDanhSachATM(); // In danh sách ATM
                break;
            }
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }

        cout << endl; // Dùng ð? t?o kho?ng tr?ng
    } while (choice != 0);

    return 0;
}
