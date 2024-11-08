#ifndef CUSTOMER_H
#define CUSTOMER_H
using namespace std;
#include <string>

class Customer {
	private:
//		string soThe, tenChuThe, PIN;
//		float soDu;
	public:
		string soThe, tenChuThe, PIN;
		float soDu;

		Customer(string soThe, string tenChuThe, string pin, float soDu);

		string getSoThe();
		
		string getTenChuThe();
		
		string getPin();
		
		float getSoDu();
		
		void setSoDu(float newSoDu);
};

#endif

//#ifndef CUSTOMER_H
//#define CUSTOMER_H

//#include <string>
//using namespace std;
//
//class Customer {
//private:
//    string soThe;       // Card number
//    string tenChuThe;   // Cardholder's name
//    string PIN;         // Cardholder's PIN (Consider security)
//    float soDu;         // Balance
//
//public:
//    // Constructor
//    Customer(string soThe, string tenChuThe, string pin, float soDu);
//
//    // Getter methods
//    string getSoThe() const;
//    string getTenChuThe() const;
//    string getPin() const;
//    float getSoDu() const;
//
//    // Setter method
//    void setSoDu(float newSoDu);
//};
//
//#endif // CUSTOMER_H
