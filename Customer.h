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
