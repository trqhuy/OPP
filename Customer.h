#ifndef CUSTOMER_H
#define CUSTOMER_H
using namespace std;
#include <string>

class Customer {
public:
    std::string soThe, tenChuThe, PIN;
    float soDu;

    Customer(std::string soThe, std::string tenChuThe, std::string pin, float soDu);
    
    std::string getSoThe();
    std::string getTenChuThe();
    std::string getPin();
    float getSoDu();
    void setSoDu(float newSoDu);
};

#endif
