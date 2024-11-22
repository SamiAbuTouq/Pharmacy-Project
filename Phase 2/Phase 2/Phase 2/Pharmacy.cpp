#include"Pharmacy.h"
#include<iostream>
int Pharmacy::pharmacyIDCounter_ = 0;
using namespace std;

//Constructor
Pharmacy::Pharmacy(string name) :PharmacyName_(name), pharmacyID_(pharmacyIDCounter_++), medicationCount_(0), customerCount_(0) {}

//Getters
int Pharmacy::getPharmacyID()const { return pharmacyID_; }
string Pharmacy::getPharmacyName()const { return PharmacyName_; }

//Setters
void Pharmacy::setPharmacyName(string name) { if (PharmacyName_!="")PharmacyName_ = name; }

//Adding Medication Function
void Pharmacy::addMedication(const Medication& medication) {
	if (medicationCount_ < 50)
		medications_[medicationCount_++] = medication;
	else cout << "Cannot add more medications. Pharmacy is full." << endl;
}

//Removing Medication By Medication ID Function
void Pharmacy::removeMedicationByID(int medicationID) {
	for (int i = 0; i < medicationCount_; ++i) {
		if (medications_[i].getMedicationID() == medicationID) {

			for (int j = i; j < medicationCount_ - 1; ++j) {
				medications_[j] = medications_[j + 1];
			}
			--medicationCount_;
			cout << "Medication had been removed successfully " << endl;
			return;
		}
	}
	cout << "Medication ID not found " << endl;
}

//Removing Medication By Medication Name Function
void Pharmacy::removeMedicationByName(string medicationName) {
	for (int i = 0; i < medicationCount_; ++i) {
		if (medications_[i].getName() == medicationName) {

			for (int j = i; j < medicationCount_ - 1; ++j) {
				medications_[j] = medications_[j + 1];
			}
			--medicationCount_;
			cout << "Medication had been removed successfully " << endl;
			return;
		}
	}
	cout << "Medication Name not found " << endl;
}

//Adding Customer Function
void Pharmacy::addCustomer(const Customer& customer) {
	if (customerCount_ < 50) {
		customers_[customerCount_].setCustomerName(customer.getCustomerName());
		customers_[customerCount_].setCustomerAddress(customer.getCustomerAddress());
		customerCount_++;
		cout << "Customer added successfully " << endl;
	}
	else cout << "Cannot add more customers. Pharmacy is full.\n";
	
}

//Print Medications for a Pharmacy Function
void Pharmacy::printMedications() const {
	cout << "Medications for Pharmacy " << PharmacyName_ << "  " << pharmacyID_ << endl;
	for (int i = 0; i < medicationCount_; ++i)
		medications_[i].printMedicationInfo();
}

//Print Customers for a Pharmacy Function
void Pharmacy::printCustomers() const {
	cout << "Customers for Pharmacy " << PharmacyName_ << "  " << pharmacyID_ << endl;
	for (int i = 0; i < customerCount_; ++i)
		customers_[i].PrintCustomerInfo();
}

//Compare 2 Pharmacies By Medication Count Function
bool Pharmacy::compareByMedicationCount(const Pharmacy& other) const {
	return medicationCount_ < other.medicationCount_;
	       
}

//Compare 2 Pharmacies By Customer Count Function
bool Pharmacy::compareByCustomerCount(const Pharmacy& other) const {
	return customerCount_ < other.customerCount_;
}

//Compute Total Revenue for a Pharmacy Function
long double Pharmacy::TotalRevunue()const {
	long double total = 0;
	for (int i = 0; i < medicationCount_; i++) {
		total = total + medications_[i].getPrice() * medications_[i].getQuantity();
	}
	return total;
}

//Compare 2 Pharmacies By Total Revenue Function
bool Pharmacy::compareByTotalRevenue(const Pharmacy& other) const {
	return TotalRevunue() < other.TotalRevunue();
}

//Check if the Pharmacy Inventory Full
bool Pharmacy::isFull()const {
	return medicationCount_ == 50; }

//Return the Number of Medications in the Pharmacy
int Pharmacy::getMidecationCount()const {
	return medicationCount_; }

//Return the Number of Customers in the Pharmacy
int Pharmacy::getCustomerCount() const {
	return customerCount_; }

//Print Pharmacy Information
void Pharmacy::printPharmacyInfo() const {
	cout << "Pharmacy Information for ID " << pharmacyID_ << ":" << endl;
	cout << "Number of Medications: " << medicationCount_ << endl;
	cout << "Number of Customers: " << customerCount_ << endl;
	cout << "Total Revenue: $" << TotalRevunue() << endl;
}

//Buy a Medicine from a Parmacy (Make Purchase)
void Pharmacy::makePurchase(string mid_name) {
	bool flag = false;
	for (int i = 0; i < medicationCount_; ++i) {
		if (medications_[i].getName() == mid_name) {
			flag = true;
			medications_[i].setQuantity(medications_[i].getQuantity() - 1);
			cout << "The medicine was bought successfully" << endl;
		}
	}
	if (!flag)cout << "Medication not found " << endl;

}

//Sort Midecations by Name
void Pharmacy::sortMedicationsByName() {
	for (int i = 0; i < medicationCount_; i++) {
		for (int j = 0; j < medicationCount_ - 1 - i; j++) {
			Medication temp = medications_[j];
			medications_[j] = medications_[j + 1];
			medications_[j + 1]=temp;
		}

	}

}

//Search for Medication by ID 
void Pharmacy::findMedicationID(int id)const {
	for (int i = 0; i < medicationCount_; i++) {
		if (medications_[i].getMedicationID() == id) {
			medications_[i].printMedicationInfo();
			return;
		}
	}
	cout << "Medication ID Not Found" << endl;
}

//Search for Customer by ID 
void Pharmacy::findCustomerID(int id)const {
	for (int i = 0; i < customerCount_; i++) {
		if (customers_[i].getCustomerID() == id)
			customers_[i].PrintCustomerInfo();
		return;

	}
	cout << "Customer ID Not Found" << endl;
}

//Display Expired Medications for a Pharmacy 
void Pharmacy::displayExpiredMedications(Date& a) const {
	int x = 0;
	cout << "Expired Medications:" << endl;
	for (int i = 0; i < medicationCount_; ++i) {
		if (medications_[i].getExpiryDate().getD()==a.getD()  &&  medications_[i].getExpiryDate().getM()==a.getM()  &&  medications_[i].getExpiryDate().getY()==a.getY()) {
			x++; medications_[i].printMedicationInfo();
		}
	}
	if (x == 0)cout << "There is no Expired Medications " << endl;
}

//Remove Expired Medications for a Pharmacy 
void Pharmacy::removeExpiredMedications(Date& a) {
	for (int i = 0; i < medicationCount_; ++i) {
		if (medications_[i].getExpiryDate().getD() == a.getD() && medications_[i].getExpiryDate().getM() == a.getM() && medications_[i].getExpiryDate().getY() == a.getY()) {
			for (int j = i; j < medicationCount_ - 1; ++j) {
				medications_[j] = medications_[j + 1];
			}
			--medicationCount_;
		}
	}
	cout << "Expired Medications Removed Successfully" << endl;
}

//Display Medications Running Low in a Pharmacy
void Pharmacy::runningLow() const {
	int x = 0;
	cout << "Medications Running Low in Stock :" << endl;
	for (int i = 0; i < medicationCount_; ++i) {
		if (medications_[i].getQuantity() < 4) {
		medications_[i].printMedicationInfo();x++;
		}
	}
	if (x == 0)cout << "There is no Medications Running Low in Stock " << endl;
}

//Update Customer Information (the function will update the name and the address of the customer and it's ID will stay the same)
void Pharmacy::updateCustomer(int ID, const Customer& newC) {
	for (int i = 0; i < customerCount_; ++i) {
		if (customers_[i].getCustomerID() == ID) {
			customers_[i].setCustomerName(newC.getCustomerName());
			customers_[i].setCustomerAddress(newC.getCustomerAddress());
			cout << "Customer information updated successfully" << endl;
			return;
		}
	}
	cout << "Customer ID not Found" << endl;
}

//Update Medication Information
void Pharmacy::updateMedication(int ID, const Medication& newM) {
	for (int i = 0; i < medicationCount_; ++i) {
		if (medications_[i].getMedicationID() == ID) {
			medications_[i] = newM;
			cout << "Medication information updated successfully" << endl;
			return;
		}
	}
	cout << "Medication ID not found " << endl;
}


