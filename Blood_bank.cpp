#include<iostream>
#include<map>
#include<unordered_map>
#include<string>

using namespace std;

class BloodBank {
	map<string, int>bloodType;
	map<string, int>name;
	int x = 0;

	string checkBloodType(string bloodTypeCT);
	int checkWithdrawAmount(int amo,string type);
	int checkBloodAmount(int amountCA);
	void donate();
	void withdraw();
	
public:
	BloodBank();
	void choose(int);
	void displayMenu(); // دالة جديدة لطباعة القائمة
};

BloodBank::BloodBank() {
}
void BloodBank :: displayMenu() {
	cout << R"(

========================================================
              BLOOD BANK MANAGEMENT SYSTEM
========================================================

        Welcome to the Blood Bank Service

                 Available Services

               [1] Donate Blood
               [2] Withdraw Blood
	       [3] Exit System

--------------------------------------------------------
          

)";
	cout << "Please choose a service(1, 2, or 3) :";

}
void BloodBank:: choose(int chose) {
	switch (chose) {
		case 1:{
			donate();
			break;
		}

		case 2:{
			withdraw();
			break;
		}
	
		default: {		
			cout << "\n  [!] Invalid Choice. Please try again." << endl;
			break;
		
		}
	}
}




int BloodBank::checkBloodAmount(int amount) {

	while (amount <= 100 || amount > 1500) {
		cout << "Please,enter valid amount of Blood(0 - 1500): ";
		cin >> amount;
		cout << endl;
	}
	return amount;
}

string BloodBank :: checkBloodType(string bloodType) {

	while (bloodType!= "A" && bloodType != "B" && bloodType != "AB" && bloodType != "O") {
		cout << "\nPlease,enter valid Type Blood { A , B , AB ,O }: ";
		cin >> bloodType;
		cout << endl;
	}
	return bloodType;
}

void BloodBank:: donate() {
	string nameD, bloodTypeD;
	int amountD;
	
	cout << "\n------------------- DONATION PROCESS -------------------" << endl;
	
	cin.ignore();
	cout << "Please enter your name: ";
	getline(cin, nameD);

	cout << "Please enter your Blood Type { A , B , AB ,O }: ";
	cin >> bloodTypeD;
	bloodTypeD = checkBloodType(bloodTypeD);

	cout << "  Please enter the amount of blood to donate (in ml): ";
	cin >> amountD;
	amountD = checkBloodAmount(amountD);
	
	bloodType[bloodTypeD]+=amountD;
	name[nameD] = ++x;

	cout << "\n  [SUCCESS] Donation completed! Thank you, " << nameD << "." << endl;
	cout << "  Your Donation ID is: " << x << endl;
	cout << "--------------------------------------------------------\n";

}

void BloodBank::withdraw() {
	string bloodTypeW;
	int amountW;

	cout << "\n------------------ WITHDRAWAL PROCESS ------------------" << endl;
	
	cout << "  Enter the required Blood Type { A , B , AB , O }: ";
	cin >> bloodTypeW;
	bloodTypeW = checkBloodType(bloodTypeW); // فحص الفصيلة المطلوبة للسحب أيضاً

	cout << "  Enter the amount to withdraw (in ml): ";
	cin >> amountW;
	
	if (amountW <= bloodType[bloodTypeW]) {
		cout << "\n  [SUCCESS] " << amountW << " units of type " << bloodTypeW << " successfully withdrawn." << endl;
		bloodType[bloodTypeW] -= amountW;
	}
	
	else {
		cout << "\n  [WARNING] Sorry, only " << bloodType[bloodTypeW] << " units are available in the bank." << endl;
		cout << "  Would you like to withdraw the available amount? (Yes / No): ";

		string yes;
		cin >> yes;
	
		if(yes == "Yes" || yes == "yes"){
			cout << "  Enter Amount (Max " << bloodType[bloodTypeW] << "): ";
			cin >> amountW;
			amountW = checkWithdrawAmount(amountW, bloodTypeW);
			bloodType[bloodTypeW] -= amountW;
			cout << "\n  [SUCCESS] Withdrawn successfully." << endl;
		}
		else cout << "\n  [INFO] Withdrawal cancelled." << endl;
	}
	cout << "--------------------------------------------------------\n";
}


int BloodBank:: checkWithdrawAmount(int amo, string type ) {
	while (amo > bloodType[type]) {
		cout << "  [!] Please enter a valid amount (1 - " << bloodType[type] << "): ";
		cin >> amo;
		cout << endl;
	}
	return amo;
}



int main() {
	BloodBank abod;
	
	int chose;
	while (true) {
		abod.displayMenu();
		cin >> chose;

		// شرط الخروج من البرنامج
		if (chose == 3) {
			cout << "\n========================================================" << endl;
			cout << "   Thank you for using the Blood Bank System. Goodbye!" << endl;
			cout << "========================================================\n" << endl;
			break; // هذه الكلمة تكسر حلقة الـ while وتنهي البرنامج
		}

		abod.choose(chose);
	}
}