#include<iostream>
#include"Medication.h"
#include "Customer.h"
#include"Pharmacy.h"
using namespace std;
int x, option;
string buy;

Pharmacy arrP[10]; //array to store pharmacies
int p = 0;  //Counter for pharmacies
int index = -1;


void printOption() {
	system("CLS");
	cout << "\t--------------- Pharmacy Management System --------------- " << endl;
	cout << "\tSelect one of the following options : " << endl;
	cout << "\t__________________________________________________________" << endl;
	cout << "\t|| 1 - Add a New Pharmacy \t\t\t\t||" << endl;
	cout << "\t|| 2 - Add Medications for a Pharmacy \t\t\t||" << endl;
	cout << "\t|| 3 - Display List of Medications for a Pharmacy\t|| " << endl;
	cout << "\t|| 4 - Remove a Medication from a Pharmacy by Index\t||" << endl;
	cout << "\t|| 5 - Remove a Medication from a Pharmacy by Name \t||" << endl;
	cout << "\t|| 6 - Add Customer to a Pharmacy\t\t\t||" << endl;
	cout << "\t|| 7 - Display List of Customers for a Pharmacy\t\t||" << endl;
	cout << "\t|| 8 - Make a Purchase \t\t\t\t\t||" << endl;
	cout << "\t----------------------------------------------------------" << endl;
	cout << "\t|| 9 - Compute Total Revenue for a Pharmacy\t\t||" << endl;
	cout << "\t|| 10- Sort Medications by Name        \t\t\t||" << endl;
	cout << "\t|| 11- Search for Customer by ID       \t\t\t||" << endl;
	cout << "\t|| 12- Search for Medication by ID     \t\t\t||" << endl;
	cout << "\t|| 13- Display Expired Medication      \t\t\t||" << endl;
	cout << "\t|| 14- Remove Expired Medications      \t\t\t||" << endl;
	cout << "\t|| 15- Update Customer Information     \t\t\t||" << endl;
	cout << "\t|| 16- Update Medication Information   \t\t\t||" << endl;
	cout << "\t|| 17- Display Medications Running Low \t\t\t||" << endl;
	cout << "\t|| 18- Print Pharmacy Information      \t\t\t||" << endl;
	cout << "\t----------------------------------------------------------" << endl;
	cout << "\t|| 19- Compare 2 Pharmacies By Total Revenue  \t\t||" << endl;
	cout << "\t|| 20- Compare 2 Pharmacies By Customer Count \t\t||" << endl;
	cout << "\t|| 21- Compare 2 Pharmacies By Medication Count \t||" << endl;
	cout << "\t|| 22- Exit \t\t\t\t\t \t||" << endl;
	cout << "\t----------------------------------------------------------" << endl;
	cin >> x;
}	

void validatePharmacyID() {
	cout << "Enter Pharmacy Index :" << endl; cin >> index;
	while (index < 0 || index>9) { cout << "Enter Pharmacy Index :" << endl; cin >> index; }
}
void afterCase() {
	cout << endl << "If you want to do another operation enter : 1  " << endl;
	cout << "If you want to exit the Pharmacy Management System enter : 2" << endl;
	cin >> option;
	while (option != 1 && option != 2) {
		cout << "Invaid option , Re-enter your choice (your choice must be 0 or 1) : ";
		cin >> option;
	}
	if (option == 2) { cout << "Exiting the Pharmacy Management System" << endl; exit(0); }
	else if (option == 1) {
		cout << endl;
		printOption();
	}
}
void MakePurchase() {
	string buy;
	validatePharmacyID();
	cout << "Enter the name of the medicine you want to buy :" << endl;
	cin >> buy;
	arrP[index].makePurchase(buy);
}
void AddCustomer() {
	validatePharmacyID();
	string name, address, email, city, stName;
	long int phoneNum;
	cout << "Enter Customer Name : " << endl;	cin >> name;
	cout << "Enter Customer email :   " << endl;  cin >> email;
	cout << "Enter Customer City Name  : " << endl; cin >> city;
	cout << "Enter Street Name : " << endl;	cin >> stName;
	cout << "Enter Customer Phone Number : " << endl;	cin >> phoneNum;
	arrP[index].addCustomer(Customer(name, email, city, stName, phoneNum));
}
void AddMedications() {
	validatePharmacyID();
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
	Medication a(name, description, price, quantity, d, m, y, barcode);
	arrP[index].addMedication(a);
	cout << "Medication added successfully " << endl;
}
void printPharmacyInformation() {
	cout << "If You Want to print the pharmacy Info by Entering it's Index  1 " << endl;
	cout << "If You Want to print the pharmacy Info by Entering it's Name Enter 2 " << endl;
	int x = -1;
	cin >> x;
	do { cout << "Invalid Input , Re-Enter your choise " << endl; cin >> x; } while (x != 1 && x != 2);
	if (x == 1) {
		cout << "Enter the pharmacy Index :";
		arrP[x].printPharmacyInfo();
	}
	if (x == 2) {
		string s;
		bool a = true;
		while (a) {
			cout << "Enter Pharmacy's Name :";
			cin >> s;
			for (int i = 0; i < 10; i++) {
				if (arrP[i].getPharmacyName() == s) {
					arrP[i].printPharmacyInfo(); a = false;
				}
			}
			if (a)cout << "Pharmacy not Founed , Re-Enter Pharmacy's Name" << endl;
		}
	}
}



int main() {
	int pharmacyIndex = 0;
	
	printOption();
	while (true) {
		switch (x)
		{
			
		//Case 1 : Add a New Pharmacy to the Pharmacy Management System
		case 1: {
			if (p <= 10) {
				string pharmacyName;
				cout << "Enter Pharmacy Name (When you're done, enter a semicolon) : " << endl;
				cin.ignore();
				getline(cin, pharmacyName, ';');
				arrP[p].setPharmacyName(pharmacyName);
				cout << "Pharmacy added successfully" << endl;
				p++;
			}
			else cout << "Maximum number of pharmacies reached " << endl;
			afterCase(); break;
		}

		//Case 2 : Add a Medication to a Pharmacy
		case 2: {
			AddMedications(); afterCase(); break; } 

		//Case 3 : Display List of Medications for a Pharmacy
		case 3: {
			validatePharmacyID();
			arrP[index].printMedications();
		    afterCase(); break;
		}

		//Case 4 : Remove a Medication from a Pharmacy by Pharmacy's ID and Medication's ID
		case 4: {
			int medID;
			validatePharmacyID();
			cout << "Enter Medication ID :" << endl;
			cin >> medID;
			arrP[index].removeMedicationByID(medID);
			afterCase(); break;
		}	

		//Case 5 : Remove a Medication from a Pharmacy by Pharmacy's Name and Medication's Name
		case 5: {
			string pharName, medName;
			bool flag = false;
			cout << "Enter Pharmacy Name :" << endl;
			cin >> pharName;
			for (int i = 0; i < 10; i++) {
				if (arrP[i].getPharmacyName() == pharName) {
					flag = true;
					cout << "Enter Medication Name :" << endl;
					cin >> medName;
					arrP[i].removeMedicationByName(medName);
				}
			}
			if (!flag){cout << "Pharmacy Not Found :" << endl;}
			afterCase(); break;
		}

		//Case 6 : Add Customer to a Pharmacy
		case 6: {
			AddCustomer(); afterCase(); break; }

		//Case 7 : Display List of Customers for a Pharmacy
		case 7: {
			validatePharmacyID();
			arrP[index].printCustomers();
			afterCase(); break;
		}

		//Case 8 : Buy a Medicine from a Parmacy (Make Purchase)
		case 8: {
			MakePurchase(); afterCase(); break;
		}

		//Case 9 : Compute Total Revenue for a Pharmacy
		case 9: {
			validatePharmacyID();
			cout << " Total Revenue for a Pharmacy " << arrP[index].getPharmacyName() << "   " << arrP[index].getPharmacyID() << " = " << arrP[index].TotalRevunue();
			afterCase(); break;
		}

		//Case 10: Sort Medications for a Pharmacy by Name 
		case 10:{
			validatePharmacyID();
			arrP[index].sortMedicationsByName();
			afterCase(); break;
		}

		//Case 11: Search for Customer by ID in a Pharmacy and Print his Information if Found
		case 11:{
			int id;
			validatePharmacyID();
			cout << "Enter Customer ID :" << endl;
			cin >> id;
			arrP[index].findCustomerID(id);
			afterCase(); break;
		}

		//Case 12: Search for Medication by ID in a Pharmacy and Print his Information if Found
		case 12:{
			int id;
			validatePharmacyID();
			cout << "Enter Medication ID :" << endl;
			cin >> id;
			arrP[index].findMedicationID(id);
			afterCase(); break;
		}

		//Case 13: Display Expired Medication for a Pharmacy
		case 13:{
			int d, m, y;
			validatePharmacyID();
			cout << "Enter the current date --> day , month and year" << endl;
			cin >> d >> m >> y;
			Date a(d, m, y);
			arrP[index].displayExpiredMedications(a);
			afterCase(); break;
		}

		//Case 14: Remove Expired Medications for a Pharmacy
		case 14:{
			int d, m, y;
			validatePharmacyID();
			cout << "Enter the current date --> day , month and year" << endl;
			cin >> d >> m >> y;
			Date a(d, m, y);
			arrP[index].removeExpiredMedications(a);
			afterCase(); break;
		}

		//Case 15: Update Customer Information (the function will update the name and the address of the customer and it's ID will stay the same)
		case 15:{
			int ID;
			validatePharmacyID();
			cout << "Enter the customer ID You Want to Update his Information : " << endl;
			cin >> ID;
			string name, address, email, city, stName;
			long int phoneNum;
			cout << "Enter Customer Name : " << endl;	cin >> name;
			cout << "Enter Customer email :   " << endl;  cin >> email;
			cout << "Enter Customer City Name  : " << endl; cin >> city;
			cout << "Enter Street Name : " << endl;	cin >> stName;
			cout << "Enter Customer Phone Number : " << endl;	cin >> phoneNum;
			arrP[index].updateCustomer(ID, Customer(name, email, city, stName, phoneNum));
			afterCase(); break;
		}

		//Case 16: Update Medication Information
		case 16:{
			int ID;
			validatePharmacyID();
			cout << "Enter the Medication ID You Want to Update it's Information : " << endl;
			cin >> ID;
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
			arrP[index].updateMedication(ID, Medication(name, description, price, quantity, d, m, y, barcode));
			afterCase(); break;
		}

		//Case 17: Display Medications Running Low in Stock
		case 17:{
			validatePharmacyID();
			arrP[index].runningLow();
			afterCase(); break;
		}

		//Case 18: Print Pharmacy Information
		case 18:{ 
			printPharmacyInformation();	afterCase(); break;	} 

		//Case 19: Compare 2 Pharmacies By Total Revenue  
		case 19:{
			int ind_1 = -1, ind_2 = -1;
			while (ind_1 < 0 || ind_1>9 && ind_2<0 || ind_2>9) { cout << "Enter Pharmacy Index for a Two Pharmacies :" << endl;	cin >> ind_1 >> ind_2;}
			arrP[ind_1].compareByTotalRevenue(arrP[ind_2]);
			afterCase(); break;
		}

		//Case 20: Compare 2 Pharmacies By Customer Count 
		case 20:{
			int ind_1 = -1, ind_2 = -1;
			while (ind_1 < 0 || ind_1>9 && ind_2 < 0 || ind_2>9) { cout << "Enter Pharmacy Index for a Two Pharmacies :" << endl;	cin >> ind_1 >> ind_2; }
			arrP[ind_1].compareByCustomerCount(arrP[ind_2]);
			afterCase(); break;
		}

		//Case 21: Compare 2 Pharmacies By Medication Count
		case 21:{
			int ind_1 = -1, ind_2 = -1;
			while (ind_1 < 0 || ind_1>9 && ind_2 < 0 || ind_2>9) { cout << "Enter Pharmacy Index for a Two Pharmacies :" << endl;	cin >> ind_1 >> ind_2; }
			arrP[ind_1].compareByMedicationCount(arrP[ind_2]);
			afterCase(); break;
		}

		//Case 22: Exiting the Pharmacy Management System
		case 22:{
			cout << "Exiting the Pharmacy Management System" << endl; return 0; } 

		//Case 23: (Default Case) It prompts the user to re-enter their choice within the valid range (between 1 and 22)
		default:{
			cout << "Invaid option , Re-enter your choice (your choice must be between 1 and 22) : "; afterCase(); } 

		}
	}
	return 0;
}

		