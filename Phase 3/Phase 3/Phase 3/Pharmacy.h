#pragma once
#include<iostream>
#include"Medication.h"
#include"Customer.h"
#include"OffTheShelf.h"
#include"Prescription.h"

using namespace std;
class Pharmacy {
	string PharmacyName_;
	static int pharmacyIDCounter_;
    int pharmacyID_;

	// 4 arrays attributes
	Medication* medications_;
	Prescription* prescriptionMid_;
	OffTheShelf* offTheShelfMid_;
	Customer* customers_;

	//Counters
	int medicationCount_;
	int prescriptionCount_;
	int offTheShelfCount_;
	int customerCount_;

	//Resizing functions
	void resizeCustomers(int change);
	void resizeMedications(int change);
	void resizePrescript(int change);
	void resizeoffTheShelf(int change);

public:
	//Defaulted Constructor
	Pharmacy(string = "No Name", int medSize = 0, int custSize = 0, int preMidSize = 0, int shelfMidSize = 0);
	//copy Constructor
	Pharmacy(const Pharmacy&C);
	//Setters
	void setPharmacyName(string name);
	//Getters
	int getPharmacyID()const;
	string getPharmacyName()const;
	//Adding Medication Function
	void addMedication(const Medication&);
	// Adding Prescription Medication Function
	void addPrescriptionMedication(const Prescription& prescription);
	// Adding Off-the-Shelf Medication Function
	void addOffTheShelfMedication(const OffTheShelf& offTheShelf);
	//Removing Medication By Medication ID Function
	void removeMedicationByID(int);
	//Removing Medication By Medication Name Function
	void removeMedicationByName(string);
	//Removing (Prescription) Medication By ID Function
	void removePrescriptionByID(int);
	//Removing (Prescription) Medication By Name Function
	void removePrescriptionByName(string name);
	//Removing (Off The Shelf) Medication By ID Function
	void removeOffTheShelfByID(int);
	//Removing (Off The Shelf) Medication By Name Function
	void removeOffTheShelfByName(string name);
	//Removing Customer By Name Function
	void removeCustomerByName(string name);
	//Adding Customer Function
	void addCustomer(const Customer&);
	//Print Medications for a Pharmacy Function
	void printMedications() const;
	//Print Prescription Medications for a Pharmacy Function
	void printPrescriptMedications() const;
	//Print Off The Shelf Medications for a Pharmacy Function
	void printOffTheShelfMedications() const;
	//Print Customers for a Pharmacy Function
	void printCustomers() const;
	//Compare 2 Pharmacies By All Medication Count Function
	bool compareByMedicationCount(const Pharmacy& other) const;
	//Compare 2 Pharmacies By Customer Count Function
	bool compareByCustomerCount(const Pharmacy& other)const;
	//Compute Total Revenue for a Pharmacy Function
	long double TotalRevenue()const;
	//Compare 2 Pharmacies By Total Revenue Function
	bool compareByTotalRevenue(const Pharmacy& other) const;
	//Return the Number of Medications in the Pharmacy
	int getMidecationCount()const;
	//Return the Number of Customers in the Pharmacy
	int getCustomerCount() const;
	//Print Pharmacy Information 
	void printPharmacyInfo() const;
	//Buy a Medicine from a Parmacy (Make Purchase)
	void makePurchase(string mid_name,int n);
	//Sort Midecations by Name
	void sortMedicationsByName();
	//Search for Medication by ID 
	void findMedicationID(int id, int n)const;
	//Search for Customer by ID :
	void findCustomerID(int id)const;
	//Display Expired Medications for a Pharmacy 
	void displayExpiredMedications(Date& a,int n)const;
	//Remove Expired Medications for a Pharmacy 
	void removeExpiredMedications(Date& a, int n);
	//Display Medications Running Low in a Pharmacy
	void runningLow()const;
	//Update Customer Information (the function will update the name and the address of the customer and it's ID will stay the same)
	void updateCustomer(int ID, const Customer& newC);
	//Update Medication Information
	void updateMedication(int ID, const Medication& newM);
	//Update Off The Shelf Medication Information
	void updateOffTheShelMedication(int ID, const OffTheShelf& newM);
	//Update Prescription Medication Information
	void updatePrescriptionMedication(int ID, const Prescription& newM);
	//Copy Pharmacies information to another Pharmacies (it's return type is a pointer to array of type Pharmacy)
	static Pharmacy* copyPharmacy( Pharmacy* oldArr, int min);
	//get Prescription
	Prescription* getPrescription();
	//Destructor
	~Pharmacy();
};
