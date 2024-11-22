#include<iostream>
#include"Pharmacy.h"
using namespace std;
int Pharmacy::pharmacyIDCounter_ = 0;
int x, option;
string buy;
Pharmacy *arrP=NULL; //array to store pharmacies
int p = 0;  // a variable used to keep track of the number of pharmacies (Counter for pharmacies)
int index ;
int PharArrSize= 0; // a variable used to initalize the size of the Pharmacies's array

void printOption() {   
	system("CLS");
	cout << "\t--------------- Pharmacy Management System --------------- " << endl;
	cout << "\tSelect one of the following options : " << endl;
	cout << "\t__________________________________________________________" << endl;
	cout << "\t|| 1 - Add a New Pharmacy \t\t\t\t||" << endl;
	cout << "\t|| 2 - Add Medications for a Pharmacy \t\t\t||" << endl;
	cout << "\t|| 3 - Display List of Medications for a Pharmacy\t|| " << endl;
	cout << "\t|| 4 - Remove a Medication from a Pharmacy \t\t||" << endl;
	cout << "\t|| 5 - Add Customer to a Pharmacy\t\t\t||" << endl;
	cout << "\t|| 6 - Display List of Customers for a Pharmacy\t\t||" << endl;
	cout << "\t|| 7 - Make a Purchase \t\t\t\t\t||" << endl;
	cout << "\t----------------------------------------------------------" << endl;
	cout << "\t|| 8 - Compute Total Revenue for a Pharmacy\t\t||" << endl;
	cout << "\t|| 9 - Sort Medications by Name        \t\t\t||" << endl;
	cout << "\t|| 10- Search for Customer by ID       \t\t\t||" << endl;
	cout << "\t|| 11- Search for Medication by ID     \t\t\t||" << endl;
	cout << "\t|| 12- Display Expired Medication      \t\t\t||" << endl;
	cout << "\t|| 13- Remove Expired Medications      \t\t\t||" << endl;
	cout << "\t|| 14- Update Customer Information     \t\t\t||" << endl;
	cout << "\t|| 15- Update Medication Information   \t\t\t||" << endl;
	cout << "\t|| 16- Display Medications Running Low \t\t\t||" << endl;
	cout << "\t|| 17- Display general Pharmacy Information \t\t||" << endl;
	cout << "\t----------------------------------------------------------" << endl;
	cout << "\t|| 18- Compare 2 Pharmacies By Total Revenue  \t\t||" << endl;
	cout << "\t|| 19- Compare 2 Pharmacies By Customer Count \t\t||" << endl;
	cout << "\t|| 20- Compare 2 Pharmacies By All Medication Count \t||" << endl;
	cout << "\t|| 21- Resize the Array of Pharmacies           \t||" << endl;
	cout << "\t|| 22- Create 4 Objects of Type Medication      \t||" << endl;
	cout << "\t|| 23- Exit \t\t\t\t\t \t||" << endl;
	cout << "\t----------------------------------------------------------" << endl;
	cin >> x;
}
void validatePharmacyID() {
	cout << "Enter Pharmacy Index :" << endl; cin >> index;
	while (index < 0 || index>=p) { cout << "Enter Pharmacy Index :" << endl; cin >> index; }
}
void afterCase() {
	cout << endl << "If you want to do another operation enter : 1  " << endl;
	cout << "If you want to exit the Pharmacy Management System enter : 2" << endl;
	cin >> option;
	while (option != 1 && option != 2) {
		cout << "Invaid option , Re-enter your choice (your choice must be 0 or 1) : ";
		cin >> option;
	}
	if (option == 2) { cout << "Exiting the Pharmacy Management System" << endl; delete[]arrP; exit(0); }
	else if (option == 1) {
		cout << endl;
		printOption();
	}
}
void MakePurchase() {
	string buy;
	validatePharmacyID();
	int n;
	cout << "If you want to buy a Medication of type (Medication) enter : 1 " << endl;
	cout << "If you want to buy a Medication of type  (Prescription) enter : 2" << endl;
	cout << "If you want to buy a Medication of type (Off The Shelf) enter : 3" << endl;
	cin >> n;
	if (n != 1 && n != 2 && n != 3)cout << "Invalid Input";
	else {
		cout << "Enter the name of the medicine you want to buy :" << endl;
		cin >> buy;
		arrP[index].makePurchase(buy, n);
	}
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
void AddMedications(int n) {
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
	//Add a Medication
	if (n == 1) {
		Medication a(name, description, price, quantity, d, m, y, barcode);
		arrP[index].addMedication(a);
	}

	//Add a Medication of type Prescription
	if (n == 2) {
		int FDA, d1, m2, y3;
		cout << "Enter FDA : " << endl; cin >> FDA;
		cout << "Enter Approval Date in the order of day, month, year : " << endl; cin >> d1 >> m2 >> y3;
		Date AppDate(d1, m2, y3);
		Prescription a(FDA, AppDate, name, description, price, quantity, d, m, y, barcode);
		arrP[index].addPrescriptionMedication(a);
	}


	//Add a Medication of type Off The Shelf
	if (n == 3) {
		int  d1, m2, y3;
		bool BOGOF;
		cout << "Enter BOGOF (Is There an Offer ? ): " << endl; cin >> BOGOF;
		OffTheShelf a(BOGOF, name, description, price, quantity, d, m, y, barcode);
		arrP[index].addOffTheShelfMedication(a);
	}



	cout << "Medication added successfully " << endl;
}
void printPharmacyInformation() {
	cout << "If You Want to print the pharmacy Info by Entering it's Index Enter 1 " << endl;
	cout << "If You Want to print the pharmacy Info by Entering it's Name Enter 2 " << endl;
	int x = -1;
	cin >> x;
	do { cout << "Invalid Input , Re-Enter your choise " << endl; cin >> x; } while (x != 1 && x != 2);
	if (x == 1) {
		validatePharmacyID();
		arrP[index].printPharmacyInfo();
	}
	if (x == 2) {
		string s;
		bool a = true;
		while (a) {
			cout << "Enter Pharmacy's Name :";
			cin >> s;
			for (int i = 0; i < p; i++) {
				if (arrP[i].getPharmacyName() == s) {
					arrP[i].printPharmacyInfo(); a = false;
				}
			}
			if (a)cout << "Pharmacy not Founed , Re-Enter Pharmacy's Name" << endl;
		}
	}
}
Pharmacy* resizePharmacyArray() {
	int newSize;
	cout << "Enter the New Size of the Array of Pharmacies " << endl;
	cin >> newSize;
	Pharmacy* newArrP = new Pharmacy[newSize];
	int min = 0;
	if (newSize < PharArrSize)min = newSize;
	else min = PharArrSize;
	newArrP ->copyPharmacy(arrP, min);
	return arrP;

}




int main() {
	int pharmacyIndex = 0;

	printOption();
	while (true) {
		switch (x)
		{

			//Case 1 : Add a New Pharmacy to the Pharmacy Management System
		case 1: {
			if (PharArrSize == 0) {
				cout << "Enter The Number of Pharmacies" << endl;
				cin >> PharArrSize;
				arrP = new Pharmacy[PharArrSize];
			}
			if (p <= PharArrSize) {
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
			int n;
			cout << "If you want to add a medication enter 1 " << endl;
			cout << "If you want to add a medication of type (Prescription) enter 2" << endl;
			cout << "If you want to add a medication of type (Off The Shelf) enter 3" << endl;
			cin >> n;
			if (n != 1 && n != 2 && n != 3)cout << "Invalid Input";
			else AddMedications(n); afterCase(); break; }

			  //Case 3 : Display List of Medications for a Pharmacy
		case 3: {
			validatePharmacyID();
			int n;
			cout << "If you want to Display List of Medications for a Pharmacy : 1 " << endl;
			cout << "If you want to Display List of Medication of type (Prescription) enter : 2" << endl;
			cout << "If you want to Display List of Medication of type (Off The Shelf) enter : 3" << endl;
			cin >> n;
			if (n != 1 && n != 2 && n != 3) cout << "Invalid Input";
			else {
				if (n == 1)arrP[index].printMedications();
				if (n == 2)arrP[index].printPrescriptMedications();
				if (n == 3)arrP[index].printOffTheShelfMedications();
			}
			afterCase(); break;
		}

			  //Case 4 : Remove a Medication from a Pharmacy  
					  // A- Remove a Medication from a Pharmacy by Pharmacy ID and Medication ID 
					  // B- Remove a Medication from a Pharmacy by Pharmacy Name and Medication Name
					  // C- Remove a Medication of type (Prescription) from a Pharmacy by Pharmacy ID and (Prescription) ID 
					  // D- Remove a Medication of type (Prescription) from a Pharmacy by Pharmacy Name and (Prescription) Name
					  // E- Remove a Medication of type (Off The Shelf) from a Pharmacy by Pharmacy ID and (Off The Shelf) ID 
					  // F- Remove a Medication of type (Off The Shelf) from a Pharmacy by Pharmacy Name and (Off The Shelf) Name
		case 4: {

			char d;
			cout << " ******* Select one of the following (using upper case) ******* " << endl;
			cout << " A- Remove a Medication from a Pharmacy by Pharmacy ID and Medication ID " << endl;
			cout << " B- Remove a Medication from a Pharmacy by Pharmacy Name and Medication Name" << endl;
			cout << " C- Remove a Medication of type (Prescription) from a Pharmacy by Pharmacy ID and (Prescription) ID " << endl;
			cout << " D- Remove a Medication of type (Prescription) from a Pharmacy by Pharmacy Name and (Prescription) Name" << endl;
			cout << " E- Remove a Medication of type (Off The Shelf) from a Pharmacy by Pharmacy ID and (Off The Shelf) ID " << endl;
			cout << " F- Remove a Medication of type (Off The Shelf) from a Pharmacy by Pharmacy Name and (Off The Shelf) Name" << endl;
			cin >> d;
			switch (d)
			case 'A':{
			int medID;
			validatePharmacyID();
			cout << "Enter Medication ID :" << endl;
			cin >> medID;
			arrP[index].removeMedicationByID(medID);
			afterCase(); break;
		}
			case 'B':{
			string pharName, medName;
			bool flag = false;
			cout << "Enter Pharmacy Name :" << endl;
			cin >> pharName;
			for (int i = 0; i < p; i++) {
				if (arrP[i].getPharmacyName() == pharName) {
					flag = true;
					cout << "Enter Medication Name :" << endl;
					cin >> medName;
					arrP[i].removeMedicationByName(medName);
				}
			}
			if (!flag) { cout << "Pharmacy Not Found :" << endl; }
			afterCase(); break;
		}
			case 'C':{
			int pharmacyID=0, prescreptionID=0;
			validatePharmacyID();
			cout << "Enter pharmacy ID :" << endl;
			cin >> pharmacyID;
			for (int i = 0; i < p; i++) {
				if (arrP[i].getPharmacyID() == pharmacyID)
					arrP[i].removePrescriptionByID(pharmacyID);
				if (prescreptionID == arrP[i].getPharmacyID())
					arrP[i].removePrescriptionByID(prescreptionID);
			}
			afterCase(); break;
		}
			case 'D':{
			validatePharmacyID();
			string pharmacyName, prescriptionName;
			cout << "Enter pharmacy Name :" << endl;
			cin >> pharmacyName;
			for (int i = 0; i < p; i++) {
				if (arrP[i].getPharmacyName() == pharmacyName)
					cout << "Enter prescription ID:" << endl;
				arrP[i].removePrescriptionByName(prescriptionName);
			}
			break;
		}
			case 'E':{
			int pharmacyID=0, ofTheShelfID=0;
			validatePharmacyID();
			cout << "Enter pharmacy ID:" << endl;
			cin >> pharmacyID;
			for (int i = 0; i < p; i++) {
				if (pharmacyID == arrP[i].getPharmacyID())
					cout << "Enter ID of of the sheld :" << endl;
				arrP[i].removeOffTheShelfByID(ofTheShelfID);
			}
			afterCase(); break;

		}
			case 'F':{
			string pharmacyName, offTheShelfName;
			validatePharmacyID();
			cout << "Enter pharmacy name :" << endl;
			cin >> pharmacyName;
			for (int i = 0; i < p; i++) {
				if (pharmacyName == arrP[i].getPharmacyName())
					cout << "Enter ID of of the sheld :" << endl;
				arrP[i].removeOffTheShelfByName(offTheShelfName);
				}
			afterCase(); break;
			}
		}
	
			 //Case 5 : Add Customer to a Pharmacy
		case 5: {
			AddCustomer(); afterCase(); break; }

			 //Case 6 : Display List of Customers for a Pharmacy
		case 6: {
			validatePharmacyID();
			arrP[index].printCustomers();
			afterCase(); break;
		}

			 //Case 7 : Buy a Medicine from a Pharmacy (Make Purchase)
		case 7: {
			MakePurchase(); afterCase(); break;
		}

			 //Case 8 : Compute Total Revenue for a Pharmacy
		case 8: {
			validatePharmacyID();
			cout << " Total Revenue for a Pharmacy " << arrP[index].getPharmacyName() << "   " << arrP[index].getPharmacyID() << " = " << arrP[index].TotalRevenue();
			afterCase(); break;
		}

			 //Case 9 : Sort Medications of type (Medication) for a Pharmacy by Name 
		case 9: {
			validatePharmacyID();
			arrP[index].sortMedicationsByName();
			afterCase(); break;
		}

			 //Case 10: Search for Customer by ID in a Pharmacy and Print his Information if Found
		case 10: {
			int id;
			validatePharmacyID();
			cout << "Enter Customer ID :" << endl;
			cin >> id;
			arrP[index].findCustomerID(id);
			afterCase(); break;
		}

			 //Case 11: Search for Medication by ID in a Pharmacy and Print his Information if Found
		case 11: {
			int id;
			validatePharmacyID();
			int n;
			cout << "Search for Medication by ID in (Medication) enter : 1 " << endl;
			cout << "Search for Medication by ID in (Prescription) enter : 2" << endl;
			cout << "Search for Medication by ID in (Off The Shelf) enter : 3" << endl;
			cin >> n;
			if (n != 1 && n != 2 && n != 3) {
				cout << "Invalid Input"; afterCase(); break;
			}
			cout << "Enter Medication ID :" << endl;
			cin >> id;
			arrP[index].findMedicationID(id,n);
			afterCase(); break;
		}

			 //Case 12: Display Expired Medication for a Pharmacy
		case 12: {
			int d, m, y;
			validatePharmacyID();
			int n;
			cout << "If you want to Display Expired Medication of type (Medication) enter : 1 " << endl;
			cout << "If you want to Display Expired Medication of type (Prescription) enter : 2" << endl;
			cout << "If you want to Display Expired Medication of type (Off The Shelf) enter : 3" << endl;
			cin >> n;
			if (n != 1 && n != 2 && n != 3) { cout << "Invalid Input"; afterCase(); break; }
			cout << "Enter the current date --> day , month and year" << endl;
			cin >> d >> m >> y;
			Date a(d, m, y);
			arrP[index].displayExpiredMedications(a,n);
			afterCase(); break;
		}

			 //Case 13: Remove Expired Medications for a Pharmacy
		case 13: {
			int d, m, y;
			validatePharmacyID();
			int n;
			cout << "If you want to Remove Expired Medication of type (Medication) : 1 " << endl;
			cout << "If you want to Remove Expired Medication of type (Prescription) enter : 2" << endl;
			cout << "If you want to Remove Expired Medication of type (Off The Shelf) enter : 3" << endl;
			cin >> n;
			if (n != 1 && n != 2 && n != 3) { cout << "Invalid Input"; afterCase(); break; }
			cout << "Enter the current date --> day , month and year" << endl;
			cin >> d >> m >> y;
			Date a(d, m, y);
			arrP[index].removeExpiredMedications(a,n);
			afterCase(); break;
		}

			 //Case 14: Update Customer Information (the function will update the name and the address of the customer and it's ID will stay the same)
		case 14: {
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

			 //Case 15: Update Medication Information
		case 15: {
			int ID;
			validatePharmacyID();
			int n;
			cout << "If you want to Update Medication Info of type (Medication) enter : 1 " << endl;
			cout << "If you want to Update Medication Info of type (Prescription) enter : 2" << endl;
			cout << "If you want to Update Medication Info of type (Off The Shelf) enter : 3" << endl;
			cin >> n;
			if (n != 1 && n != 2 && n != 3) { cout << "Invalid Input"; afterCase(); break;}
			
			else {
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

				if (n == 1) {
					arrP[index].updateMedication(ID, Medication(name, description, price, quantity, d, m, y, barcode));
					afterCase(); break;
				}

				else if (n == 2) {
					int FDA, d1, m2, y3;
					cout << "Enter FDA : " << endl; cin >> FDA;
					cout << "Enter Approval Date in the order of day, month, year : " << endl; cin >> d1 >> m2 >> y3;
					Date AppDate(d1, m2, y3);
					Prescription a(FDA, AppDate, name, description, price, quantity, d, m, y, barcode);
					arrP[index].updatePrescriptionMedication(ID, a);
					afterCase(); break;
				}
				else if (n == 3) {
					int  d1, m2, y3;
					bool BOGOF;
					cout << "Enter BOGOF (Is There an Offer ? ): " << endl; cin >> BOGOF;
					OffTheShelf a(BOGOF, name, description, price, quantity, d, m, y, barcode);
					arrP[index].updateOffTheShelMedication(ID, a);
					afterCase(); break;
				}
			}	
		}

			 //Case 16: Display Medications Running Low in Stock
		case 16: {
			validatePharmacyID();
			arrP[index].runningLow();
			afterCase(); break;
		}

			 //Case 17: Print Pharmacy Information
		case 17: {
			printPharmacyInformation();	afterCase(); break;	}

			 //Case 18: Compare 2 Pharmacies By Total Revenue  
		case 18: {
			int ind_1 = -1, ind_2 = -1;
			while (ind_1 < 0 || ind_1>p && ind_2 < 0 || ind_2>p) { cout << "Enter Pharmacy Index for a Two Pharmacies :" << endl;	cin >> ind_1 >> ind_2; }
			arrP[ind_1].compareByTotalRevenue(arrP[ind_2]);
			afterCase(); break;
		}

			 //Case 19: Compare 2 Pharmacies By Customer Count 
		case 19: {
			int ind_1 = -1, ind_2 = -1;
			while (ind_1 < 0 || ind_1>p && ind_2 < 0 || ind_2>p) { cout << "Enter Pharmacy Index for a Two Pharmacies :" << endl;	cin >> ind_1 >> ind_2; }
			arrP[ind_1].compareByCustomerCount(arrP[ind_2]);
			afterCase(); break;
		}

			 //Case 20: Compare 2 Pharmacies By All Medication Count
		case 20: {
			int ind_1 = -1, ind_2 = -1;
			while (ind_1 < 0 || ind_1>p && ind_2 < 0 || ind_2>p) { cout << "Enter Pharmacy Index for a Two Pharmacies :" << endl;	cin >> ind_1 >> ind_2; }
			arrP[ind_1].compareByMedicationCount(arrP[ind_2]);
			afterCase(); break;
		}

			 //Case 21 : Resize the Array of Pharmacis
		case 21:{
			resizePharmacyArray(); afterCase(); break;
			}

			  //Case 22 : create 4 objects including both sub-types ( Prescription - OffTheShelf )
		case 22: {
			
			cout << "midA – An object in static memory with attributes in static memory" << endl;
			cout << "midB – An object in static memory with attributes in dynamic memory" << endl;
			cout << "midC – An object in dynamic memory with attributes in static memory" << endl;
			cout << "midD – An object in dynamic memory with attributes in dynamic memory" << endl;

			//creating objects
			Prescription midA;
			Prescription midB;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			OffTheShelf midC;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			OffTheShelf midD;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//printing its information
			cout << endl << "If you want to print a medication Info enter its name" << endl;
			cout << "If you want to print all medications Info enter 1 " << endl;
			cout << " else enter 0" << endl << endl;
			string x;
			cin >> x;
			while (x != "midA" && x != "midB" && x != "midC" && x != "midD" && x != "0" && x != "1") {
				cout << "Invalid Input Re-enter Your choice : " << endl;
				cin >> x;
			}
			if (x != "0" && x != "1") {
				if (x == "midA") midA.printMedicationInfo();
				if (x == "midB") midB.printMedicationInfo();
				if (x == "midC") midC.printMedicationInfo();
				if (x == "midD") midD.printMedicationInfo();
				}

			if (x == "1") {
				midA.printMedicationInfo();
				midB.printMedicationInfo();
				midC.printMedicationInfo();
				midD.printMedicationInfo();
			}
		}

			 //Case 23: Exiting the Pharmacy Management System
		case 23: {
			cout << "Exiting the Pharmacy Management System" << endl; delete[]arrP; return 0; }

			 //Case 24: (Default Case) It prompts the user to re-enter their choice within the valid range (between 1 and 22)
		default: {
			cout << "Invaid option , Re-enter your choice (your choice must be between 1 and 22) : "; afterCase(); }

		}
	}
	return 0;
}

