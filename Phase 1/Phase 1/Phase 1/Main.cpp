#include<iostream>
#include"Medication.h"
#include "Customer.h"
using namespace std;
int x, option;

void printOption() {
	system("CLS");
	cout << "\t------- Pharmacy Management System ------- " << endl;
	cout << "\tSelect one of the following : " << endl;
	cout << "\t__________________________________________" << endl;
	cout << "\t|| 1- Add Medication	\t\t||" << endl;
	cout << "\t|| 2- Add Customer \t\t\t||" << endl;
	cout << "\t|| 3- Make a Purchase \t\t\t||" << endl;
	cout << "\t|| 4- Displaying Available Medications \t|| " << endl;
	cout << "\t|| 5- Calculate Total Sales and Profit \t||" << endl;
	cout << "\t|| 6- Exit \t\t\t\t||" << endl;
	cout << "\t------------------------------------------" << endl;
	cin >> x;
}

int  afterCase() {
	cout << endl << "If you want to do another operation enter : 1  " << endl; 
	cout << "If you want to exit the Pharmacy Management System enter : 2" << endl;
	cin >> option;
	while (option != 1 && option != 2) {
		cout << "Invaid option , Re-enter your choice (your choice must be 0 or 1) : ";
		cin >> option;
	}
	if (option == 2){cout << "Exiting the Pharmacy Management System" << endl; exit(0); }
	else if (option == 1) {
		cout << endl;
		printOption();
	}
}


int main() {
	Medication arrM[20];
	Customer arrC[20];
	int i = 0;
	int j = 0;
	float profit = 0;
	string buy;
	printOption();
	while (true) {
		switch (x)
		{
		case 1: {
			string name, description;
			float price;
			int quantity, d, m, y;
			string barcode;
			cout << "Enter Medication Name : " << endl;	cin >> name;
			cout << "Enter Medication Description (When you're done, enter a semicolon) : " << endl; cin.ignore(); getline(cin, description, ';');
			cout << "Enter Medication Price : $" << endl; cin >> price;
			cout << "Enter the Quantity : " << endl; cin >> quantity;
			cout << "Enter Expiry Date in the order of day, month, year : " << endl; cin >> d >> m >> y;
			cout << "Enter Medication Barcode : " << endl; cin >> barcode;
			arrM[i] = Medication(name, description, price, quantity, d, m, y, barcode); i++;
			cout << "Medication added successfully " << endl;
			afterCase();
			break; }



		case 2: { 
			string name, phoneNum, address;
			int id;
			cout << "Enter Customer Name : " << endl;	cin >> name;
			cout << "Enter Customer ID :   " << endl;  cin >> id;
			cout << "Enter Customer Phone Number : " << endl;	cin >> phoneNum;
			cout << "Enter Customer Address  (When you're done, enter a semicolon) : " << endl; cin.ignore(); getline(cin, address, ';');
			arrC[j].setCustomerName(name); 
			cout << "Customer added successfully " << endl;
			afterCase();
			break; }



		case 3: {
			cout << "Enter the name of the medicine you want to buy :" << endl;
			cin >> buy;
			for (int f = 0; f < i; f++) {
				if (arrM[f].getName() == buy && arrM[f].getQuantity() > 0) {
					arrM[f].setQuantity(arrM[f].getQuantity() - 1);
					profit += arrM[f].getPrice();
					cout << "The medicine was bought successfully" << endl; afterCase(); break;
				}
			}
			cout << "The medicine you want is not available" << endl; afterCase();  
			break;
		}


		case 4: {for (int f = 0; f < i; f++)arrM[f].printMedicationInfo(); afterCase(); break; }

		case 5: {cout << "Total Sales and Profit = " << profit << endl; afterCase(); break; }

		case 6: {cout << "Exiting the Pharmacy Management System" << endl; return 0; }

		default: {cout << "Invaid option , Re-enter your choice (your choice must be between 1 and 6) : "; afterCase(); }
		}
	}
	return 0;
}