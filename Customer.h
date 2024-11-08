#ifndef CUSTOMER_H
#define CUSTOMER_H
using namespace std;
#include <string>

class Customer {
	private:
		string soThe, tenChuThe, PIN;
		int soDu;
	public:

		Customer(string soThe, string tenChuThe, string pin, float soDu);
		
		string getSoThe();
		string getTenChuThe();
		string getPin();
		float getSoDu();
		void set_soThe(string So_The){
			soThe =So_The;
		}
		void set_tenChuThe(string TenChuThe){
			tenChuThe =TenChuThe;
		}
		void set_PIN(string pin){
			 PIN=pin;
		}
		void set_SoDu(int newSoDu);
};

#endif
