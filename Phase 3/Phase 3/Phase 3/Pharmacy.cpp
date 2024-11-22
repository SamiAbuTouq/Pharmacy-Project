#include"Pharmacy.h"
#include<iostream>
using namespace std;

//Defaulted Constructor
Pharmacy::Pharmacy(string name, int medSize, int custSize, int preMidSize, int shelfMidSize)
	:PharmacyName_(name), pharmacyID_(pharmacyIDCounter_++), medicationCount_(0), customerCount_(0), offTheShelfCount_(0), prescriptionCount_(0)
{
    if (medSize > 0) medications_ = new Medication[medSize];
	else medications_ = NULL;

	if (custSize > 0) customers_ = new Customer[custSize];
	else customers_ = NULL;

	if (preMidSize > 0) prescriptionMid_ = new Prescription[preMidSize];
	else prescriptionMid_ = NULL;

	if (shelfMidSize > 0) offTheShelfMid_ = new OffTheShelf[shelfMidSize];
	else offTheShelfMid_ = NULL;

}
//Copy Constructor
Pharmacy::Pharmacy(const Pharmacy& C) : PharmacyName_(C.PharmacyName_), pharmacyID_(C.pharmacyID_),
medicationCount_(C.medicationCount_), prescriptionCount_(C.prescriptionCount_),
offTheShelfCount_(C.offTheShelfCount_), customerCount_(C.customerCount_) {

	//copy medications
	medications_ = new Medication[medicationCount_];
	for (int i = 0; i < medicationCount_; ++i) {
		medications_[i] = C.medications_[i];
	}

	//copy prescription medications
	prescriptionMid_ = new Prescription[prescriptionCount_];
	for (int i = 0; i < prescriptionCount_; ++i) {
		prescriptionMid_[i] = C.prescriptionMid_[i];
	}

	//copy off the shelf medications
	offTheShelfMid_ = new OffTheShelf[offTheShelfCount_];
	for (int i = 0; i < offTheShelfCount_; ++i) {
		offTheShelfMid_[i] = C.offTheShelfMid_[i];
	}

	//copy customers
	customers_ = new Customer[customerCount_];
	for (int i = 0; i < customerCount_; ++i) {
		customers_[i] = C.customers_[i];
	}

}

// Getters 
int Pharmacy::getPharmacyID()const { return pharmacyID_; }
string Pharmacy::getPharmacyName()const { return PharmacyName_; }
// Setters 
void Pharmacy::setPharmacyName(string name) { if (PharmacyName_ != "")PharmacyName_ = name; }

Prescription* Pharmacy::getPrescription() {
	return prescriptionMid_;
}

// Private member function to resize Medications array
void Pharmacy::resizeMedications(int change) {
	int newCapacity = medicationCount_ + change;
	Medication* newMedications = new Medication[newCapacity];
	for (int i = 0; i < medicationCount_; i++)
		newMedications[i] = medications_[i];

	delete[] medications_;
	medications_ = newMedications;
}
// Private member function to resize medication array for Prescript
void Pharmacy::resizePrescript(int change) {
	int newCapacity = prescriptionCount_ + change;
	Prescription* newPrescriptions = new Prescription[newCapacity];

	for (int i = 0; i < prescriptionCount_; i++)
		newPrescriptions[i] = prescriptionMid_[i];

	delete[] prescriptionMid_;
	prescriptionMid_ = newPrescriptions;
}
// Private member function to resize medication array for off the shelf
void Pharmacy::resizeoffTheShelf(int change) {
	int newCapacity = offTheShelfCount_ + change;
	OffTheShelf* newOffTheShelfMeds = new OffTheShelf[newCapacity];

	for (int i = 0; i < offTheShelfCount_; i++)
		newOffTheShelfMeds[i] = offTheShelfMid_[i];

	delete[] offTheShelfMid_;
	offTheShelfMid_ = newOffTheShelfMeds;
}
// Private member function to resize customers array
void Pharmacy::resizeCustomers	(int change) {
	int newCapacity = customerCount_ + change;
	Customer* newCustomers = new Customer[newCapacity];

	for (int i = 0; i < customerCount_; i++) 
		newCustomers[i] = customers_[i];
	
	delete[] customers_;
	customers_ = newCustomers;
}


// Adding Medication Function
void Pharmacy::addMedication(const Medication& medication) {
	resizeMedications(1);
	medications_[medicationCount_++] = medication;
}
// Adding Prescription Medication Function
void Pharmacy::addPrescriptionMedication(const Prescription& prescription) {
	resizePrescript(1);
	prescriptionMid_[medicationCount_++] = prescription;
}
// Adding Off-the-Shelf Medication Function
void Pharmacy::addOffTheShelfMedication(const OffTheShelf& offTheShelf) {
	resizeoffTheShelf(1);
	offTheShelfMid_[medicationCount_++] = offTheShelf;
}
//Adding Customer Function
void Pharmacy::addCustomer(const Customer& customer) {
	resizeCustomers(1);
	customers_[customerCount_++] = customer;	
}


//Removing Medication By Medication ID Function
void Pharmacy::removeMedicationByID(int medicationID) {
	int index = -1;
	for (int i = 0; i < medicationCount_; ++i) {
		if (medications_[i].getMedicationID() == medicationID) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		// Move all elements after the removed one by one position back
		for (int j = index; j < medicationCount_ - 1; ++j)
			medications_[j] = medications_[j + 1];

		// Resize the array to make it smaller by 1
		medicationCount_--;
		resizeoffTheShelf(-1);

		cout << "Medication with ID " << medicationID << " removed successfully" << endl;
	}
	else {
		cout << "Medication with ID " << medicationID << " not found" << endl;
	}
}
//Removing Medication By Medication Name Function
void Pharmacy::removeMedicationByName(string medicationName) {
	int index = -1;
	for (int i = 0; i < medicationCount_; ++i) {
		if (medications_[i].getName() == medicationName) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		// Move all elements after the removed one by one position back
		for (int j = index; j < medicationCount_ - 1; ++j)
			medications_[j] = medications_[j + 1];

		// Resize the array to make it smaller by 1
		medicationCount_--;
		resizeMedications(-1);

		cout << "Medication with name " << medicationName << " removed successfully" << endl;
	}
	else {
		cout << "Medication with name " << medicationName << " not found" << endl;
	}
}
//Removing (Prescription) Medication By ID Function
void Pharmacy::removePrescriptionByID(int ID) {
	int index = -1;
	for (int i = 0; i < prescriptionCount_; ++i) {
		if (prescriptionMid_[i].getMedicationID() == ID) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		// Move all elements after the removed one by one position back
		for (int j = index; j < prescriptionCount_ - 1; ++j)
			prescriptionMid_[j] = prescriptionMid_[j + 1];

		// Resize the array to make it smaller by 1
		prescriptionCount_--;
		resizePrescript(-1);

		cout << "Prescription Medication with ID " << ID << " removed successfully" << endl;
	}
	else {
		cout << "Prescription Medication with ID " << ID << " not found" << endl;
	}
}
//Removing (Prescription) Medication By Name Function
void Pharmacy::removePrescriptionByName(string name) {
	int index = -1;
	for (int i = 0; i < prescriptionCount_; ++i) {
		if (prescriptionMid_[i].getName() == name) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		// Move all elements after the removed one by one position back
		for (int j = index; j < prescriptionCount_ - 1; ++j)
			prescriptionMid_[j] = prescriptionMid_[j + 1];

		// Resize the array to make it smaller by 1
		prescriptionCount_--;
		resizePrescript(-1);

		cout << "Prescription Medication with name " << name << " removed successfully" << endl;
	}
	else {
		cout << "Prescription Medication with name " << name << " not found" << endl;
	}

}
//Removing (Off The Shelf) Medication By ID Function
void Pharmacy::removeOffTheShelfByID(int ID) {
	int index = -1;
	for (int i = 0; i < offTheShelfCount_; ++i) {
		if (offTheShelfMid_[i].getMedicationID() == ID) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		// Move all elements after the removed one by one position back
		for (int j = index; j < offTheShelfCount_ - 1; ++j)
			offTheShelfMid_[j] = offTheShelfMid_[j + 1];

		// Resize the array to make it smaller by 1
		offTheShelfCount_--;
		resizeoffTheShelf(-1);

		cout << "Off The Shelf Medication with ID " << ID << " removed successfully" << endl;
	}
	else {
		cout << "Off The Shelf Medication with ID " << ID << " not found" << endl;
	}

}
//Removing (Off The Shelf) Medication By Name Function
void Pharmacy::removeOffTheShelfByName(string name) {
	int index = -1;
	for (int i = 0; i < offTheShelfCount_; ++i) {
		if (offTheShelfMid_[i].getName() == name) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		// Move all elements after the removed one by one position back
		for (int j = index; j < offTheShelfCount_ - 1; ++j)
			offTheShelfMid_[j] = offTheShelfMid_[j + 1];

		// Resize the array to make it smaller by 1
		offTheShelfCount_--;
		resizeoffTheShelf(-1);

		cout << "Off The Shelf Medication with name " << name << " removed successfully" << endl;
	}
	else {
		cout << "Off The Shelf Medication with name " << name << " not found" << endl;
	}
}
//Removing Customer By Name Function
void Pharmacy::removeCustomerByName(string name) {
	int index = -1;
	for (int i = 0; i < customerCount_; ++i) {
		if (customers_[i].getCustomerName() == name) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		// Move all elements after the removed one by one position back
		for (int j = index; j < customerCount_ - 1; ++j) 
			customers_[j] = customers_[j + 1];
		

		// Resize the array to make it smaller by 1
		customerCount_--;
		resizeCustomers(-1);

		cout << "Customer with name " << name << " removed successfully" << endl;
	}
	else {
		cout << "Customer with name " << name << " not found" << endl;
	}
}


//Print Medications for a Pharmacy Function
void Pharmacy::printMedications() const {
	cout << "Medications for Pharmacy " << PharmacyName_ << "  " << pharmacyID_ << endl;
	for (int i = 0; i < medicationCount_; ++i)
		medications_[i].printMedicationInfo();
}
//Print Prescription Medications for a Pharmacy Function
void Pharmacy::printPrescriptMedications() const {
	cout << "Prescription Medications for Pharmacy " << PharmacyName_ << "  " << pharmacyID_ << endl;
	for (int i = 0; i < prescriptionCount_; ++i)
		prescriptionMid_[i].printMedicationInfo();
}
//Print Off The Shelf Medications for a Pharmacy Function
void Pharmacy::printOffTheShelfMedications() const {
	cout << "Off The Shelf Medications for Pharmacy " << PharmacyName_ << "  " << pharmacyID_ << endl;
	for (int i = 0; i < offTheShelfCount_; ++i)
		offTheShelfMid_[i].printMedicationInfo();
}
//Print Customers for a Pharmacy Function
void Pharmacy::printCustomers() const {
	cout << "Customers for Pharmacy " << PharmacyName_ << "  " << pharmacyID_ << endl;
	for (int i = 0; i < customerCount_; ++i)
		customers_[i].PrintCustomerInfo();
}


//Compare 2 Pharmacies By All Medication Count Function
bool Pharmacy::compareByMedicationCount(const Pharmacy& other) const {
	return medicationCount_ + prescriptionCount_ + offTheShelfCount_ < other.medicationCount_ + other.prescriptionCount_ + other.offTheShelfCount_;
}
//Compare 2 Pharmacies By Customer Count Function
bool Pharmacy::compareByCustomerCount(const Pharmacy& other) const {
	return customerCount_ < other.customerCount_;
}
//Compare 2 Pharmacies By Total Revenue Function
bool Pharmacy::compareByTotalRevenue(const Pharmacy& other) const {
	return TotalRevenue() < other.TotalRevenue();
}
//Compute Total Revenue for a Pharmacy Function
long double Pharmacy::TotalRevenue() const {
	long double total = 0;

	// Sum the prices of regular medications
	for (int i = 0; i < medicationCount_; i++) {
		total += ((long double)medications_[i].getPrice()) * ((long double)medications_[i].getQuantity());
	}

	// Sum the prices of prescription medications
	for (int i = 0; i < prescriptionCount_; i++) {
		total += ((long double)prescriptionMid_[i].getPrice())* ((long double)prescriptionMid_[i].getQuantity());
	}

	// Sum the prices of off-the-shelf medications
	for (int i = 0; i < offTheShelfCount_; i++) {
		total += ((long double)offTheShelfMid_[i].getPrice()) * ((long double)offTheShelfMid_[i].getQuantity());
	}

	return total;
}


//Return the Number of Customers in the Pharmacy
int Pharmacy::getCustomerCount() const {
	return customerCount_;
}
//Return Total number of medications in the Pharmacy
int Pharmacy::getMidecationCount()const {
	return  medicationCount_ + prescriptionCount_ + offTheShelfCount_;
}


//Display Expired Medications for a Pharmacy 
void Pharmacy::displayExpiredMedications(Date& a, int n) const {
	int x = 0;
	cout << "Expired Medications:" << endl;
	//Display Expired Medications
	if (n == 1) {
		for (int i = 0; i < medicationCount_; ++i) {
			if (medications_[i].getExpiryDate().getD() == a.getD() && medications_[i].getExpiryDate().getM() == a.getM() && medications_[i].getExpiryDate().getY() == a.getY()) {
				x++; medications_[i].printMedicationInfo();
			}
		}
	}

	//Display Expired Prescription Medications
	else if (n == 2) {
		for (int i = 0; i < prescriptionCount_; ++i) {
			if (prescriptionMid_[i].getExpiryDate().getD() == a.getD() && prescriptionMid_[i].getExpiryDate().getM() == a.getM() && prescriptionMid_[i].getExpiryDate().getY() == a.getY()) {
				x++; prescriptionMid_[i].printMedicationInfo();
			}
		}
	}

	//Display Expired Off The Shelf Medications
	else if (n == 3) {
		for (int i = 0; i < offTheShelfCount_; ++i) {
			if (offTheShelfMid_[i].getExpiryDate().getD() == a.getD() && offTheShelfMid_[i].getExpiryDate().getM() == a.getM() && offTheShelfMid_[i].getExpiryDate().getY() == a.getY()) {
				x++; offTheShelfMid_[i].printMedicationInfo();
			}
		}
	}
	else cout << "Invalid Input" << endl;

	if (x == 0 && (n == 1 || n == 2 || n == 3))cout << "There is no Expired Medications " << endl;;
}
//Remove Expired Medications for a Pharmacy
void Pharmacy::removeExpiredMedications(Date& a, int n) {
	//Remove Expired Medications
	if (n == 1) {
		for (int i = 0; i < medicationCount_; ++i) {
			if (medications_[i].getExpiryDate().getD() == a.getD() && medications_[i].getExpiryDate().getM() == a.getM() && medications_[i].getExpiryDate().getY() == a.getY()) {
				removeMedicationByID(medications_[i].getMedicationID());
			}
		}
		cout << "Expired Medications Removed Successfully" << endl;
	}


	//Remove Expired Prescription Medications
	if (n == 2) {
		for (int i = 0; i < prescriptionCount_; ++i) {
			if (prescriptionMid_[i].getExpiryDate().getD() == a.getD() && prescriptionMid_[i].getExpiryDate().getM() == a.getM() && prescriptionMid_[i].getExpiryDate().getY() == a.getY()) {
				removePrescriptionByID(prescriptionMid_[i].getMedicationID());
			}
		}
		cout << "Expired Medications of Type Removed Prescription Successfully" << endl;
	}


	//Remove Expired Off The Shelf Medications
	if (n == 3) {
		for (int i = 0; i < offTheShelfCount_; ++i) {
			if (offTheShelfMid_[i].getExpiryDate().getD() == a.getD() && offTheShelfMid_[i].getExpiryDate().getM() == a.getM() && offTheShelfMid_[i].getExpiryDate().getY() == a.getY()) {
				removeOffTheShelfByID(offTheShelfMid_[i].getMedicationID());
			}
		}
		cout << "Expired Medications of Type Off The Shelf Removed Successfully" << endl;
	}
	else cout << "Invalid Input" << endl;

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
//Update Prescription Medication Information
void Pharmacy::updatePrescriptionMedication(int ID, const Prescription& newM) {
	for (int i = 0; i < prescriptionCount_; ++i) {
		if (prescriptionMid_[i].getMedicationID() == ID) {
			prescriptionMid_[i] = newM;
			cout << "Medication (Prescription) information updated successfully" << endl;
			return;
		}
	}
	cout << "Medication (Prescription) ID not found " << endl;
}
//Update Off The Shelf Medication Information
void Pharmacy::updateOffTheShelMedication(int ID, const OffTheShelf& newM) {
	for (int i = 0; i < offTheShelfCount_; ++i) {
		if (offTheShelfMid_[i].getMedicationID() == ID) {
			offTheShelfMid_[i] = newM;
			cout << "Medication (Off The Shelf) information updated successfully" << endl;
			return;
		}
	}
	cout << "Medication (Off The Shelf) ID not found " << endl;
}


//Search for Medication by ID 
void Pharmacy::findMedicationID(int id, int n)const {
	if (n == 1) {
		for (int i = 0; i < medicationCount_; i++)
			if (medications_[i].getMedicationID() == id) {
				medications_[i].printMedicationInfo();
				return;
			}
		cout << "Medication ID Not Found" << endl;
	}

	else if (n == 2) {
		for (int i = 0; i < prescriptionCount_; i++)
			if (prescriptionMid_[i].getMedicationID() == id) {
				prescriptionMid_[i].printMedicationInfo();
				return;
			}
		cout << "Medication (Prescription) ID Not Found" << endl;
	}

	else if (n == 3) {
		for (int i = 0; i < offTheShelfCount_; i++)
			if (offTheShelfMid_[i].getMedicationID() == id) {
				offTheShelfMid_[i].printMedicationInfo();
				return;
			}
		cout << "Medication (Off The Shelf) ID Not Found" << endl;
	}
	else cout << "Invalid Input" << endl;
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


//Update Customer Information (the function will update the name and the address of the customer and it's ID will stay the same)
void Pharmacy::updateCustomer(int ID, const Customer& newC) {
	for (int i = 0; i < customerCount_; ++i) {
		if (customers_[i].getCustomerID() == ID) {
			customers_[i] = newC;
			cout << "Customer information updated successfully" << endl;
			return;
		}
	}
	cout << "Customer ID not Found" << endl;
}
//Buy a Medicine from a Pharmacy (Make Purchase)
void Pharmacy::makePurchase(string mid_name, int n) {
	bool flag = false;
	//Buy a Medicine from a Pharmacy
	if (n == 1) {
		for (int i = 0; i < medicationCount_; ++i) {
			if (medications_[i].getName() == mid_name) {
				flag = true;
				medications_[i].setQuantity(medications_[i].getQuantity() - 1);
				cout << "The medicine was bought successfully" << endl;
			}
		}
		if (!flag)cout << "Medication not found " << endl;
	}

	//Buy a Medicine of type (Prescription) from a Pharmacy
	else if (n == 2) {
		for (int i = 0; i < prescriptionCount_; ++i) {
			if (prescriptionMid_[i].getName() == mid_name) {
				flag = true;
				prescriptionMid_[i].setQuantity(prescriptionMid_[i].getQuantity() - 1);
				cout << "The medicine of type (Prescription) was bought successfully" << endl;
			}
		}
		if (!flag)cout << "Medication not found " << endl;
	}

	//Buy a Medicine of type (Off The Shelf) from a Pharmacy
	else if (n == 3) {
		for (int i = 0; i < offTheShelfCount_; ++i) {
			if (offTheShelfMid_[i].getName() == mid_name) {
				flag = true;
				offTheShelfMid_[i].setQuantity(offTheShelfMid_[i].getQuantity() - 1);
				cout << "The medicine of type (Off The Shelf) was bought successfully" << endl;
			}
		}
		if (!flag)cout << "Medication not found " << endl;
	}

	else cout << "Invalid Input" << endl;
}
//Display Medications Running Low in a Pharmacy
void Pharmacy::runningLow() const {
	int x = 0;
	cout << "Medications Running Low in Stock :" << endl;
	for (int i = 0; i < medicationCount_; ++i) {
		if (medications_[i].getQuantity() < 4) {
			medications_[i].printMedicationInfo(); x++;
		}
	}
	for (int i = 0; i < prescriptionCount_; ++i) {
		if (prescriptionMid_[i].getQuantity() < 4) {
			prescriptionMid_[i].printMedicationInfo(); x++;
		}
	}
	for (int i = 0; i < offTheShelfCount_; ++i) {
		if (offTheShelfMid_[i].getQuantity() < 4) {
			offTheShelfMid_[i].printMedicationInfo(); x++;
		}
	}
	if (x == 0)cout << "There is no Medications Running Low in Stock " << endl;
}
//Sort Medecations by Name
void Pharmacy::sortMedicationsByName() {
	for (int i = 0; i < medicationCount_; i++) 
		for (int j = 0; j < medicationCount_ - 1 - i; j++) {
			Medication temp = medications_[j];
			medications_[j] = medications_[j + 1];
			medications_[j + 1] = temp;
		}
	

	for (int i = 0; i < prescriptionCount_; i++) 
		for (int j = 0; j < prescriptionCount_ - 1 - i; j++) {
			Prescription temp = prescriptionMid_[j];
			prescriptionMid_[j] = prescriptionMid_[j + 1];
			prescriptionMid_[j + 1] = temp;
		}
	

	for (int i = 0; i < offTheShelfCount_; i++) 
		for (int j = 0; j < offTheShelfCount_ - 1 - i; j++) {
			OffTheShelf temp = offTheShelfMid_[j];
			offTheShelfMid_[j] = offTheShelfMid_[j + 1];
			offTheShelfMid_[j + 1] = temp;
		}
	
}
//Print Pharmacy Information
void Pharmacy::printPharmacyInfo() const {
	cout << "Pharmacy Information for ID " << pharmacyID_ << ":" << endl;
	cout << "Number of Medications: " << medicationCount_ << endl;
	cout << "Number of Medications of Type (Prescription): " << prescriptionCount_ << endl;
	cout << "Number of Medications of Type (Off The Shelf): " << offTheShelfCount_ << endl;
	cout << "Total Number of Medications: " << medicationCount_ + prescriptionCount_ + offTheShelfCount_ << endl;
	cout << "Number of Customers: " << customerCount_ << endl;
	cout << "Total Revenue: $" << TotalRevenue() << endl;
}





Medication* medications_;
Prescription* prescriptionMid_;
OffTheShelf* offTheShelfMid_;
Customer* customers_;





//Copy Pharmacies information to another Pharmacies (it's return type is a pointer to array of type Pharmacy)


Pharmacy* Pharmacy::copyPharmacy(Pharmacy* oldArr, int size) {
	Pharmacy* newArr = new Pharmacy[size];
	for (int i = 0; i < size; ++i) {
		newArr[i] = Pharmacy(oldArr[i]); 
	}
	return newArr;
}



//Destructor
Pharmacy::~Pharmacy() {
	delete[]customers_;
	delete[]medications_;
	delete[] prescriptionMid_;
	delete[] offTheShelfMid_;
}
