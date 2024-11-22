#pragma once
#include<iostream>
#include"Medication.h"
#include"Customer.h"

using namespace std;
class Pharmacy {
	string PharmacyName_;
	static int pharmacyIDCounter_;
	const int pharmacyID_;
	Medication medications_[50];
	Customer customers_[50];
	int medicationCount_;
	int customerCount_;
public:
	//Constructor
	Pharmacy(string = "No Name");
	//Setters
	void setPharmacyName(string name);
	//Getters
	int getPharmacyID()const;
	string getPharmacyName()const;
	//Adding Medication Function
	void addMedication(const Medication&);
	//Removing Medication By Medication ID Function
	void removeMedicationByID(int);
	//Removing Medication By Medication Name Function
	void removeMedicationByName(string name);
	//Adding Customer Function
	void addCustomer(const Customer&);
	//Print Medications for a Pharmacy Function
	void printMedications() const;
	//Print Customers for a Pharmacy Function
	void printCustomers() const;
	//Compare 2 Pharmacies By Medication Count Function
	bool compareByMedicationCount(const Pharmacy& other) const;
	//Compare 2 Pharmacies By Customer Count Function
	bool compareByCustomerCount(const Pharmacy& other)const;
	//Compute Total Revenue for a Pharmacy Function
	long double TotalRevunue()const;
	//Compare 2 Pharmacies By Total Revenue Function
	bool compareByTotalRevenue(const Pharmacy& other) const;
	//Check if the Pharmacy Inventory Full
	bool isFull()const;
	//Return the Number of Medications in the Pharmacy
	int getMidecationCount()const;
	//Return the Number of Customers in the Pharmacy
	int getCustomerCount() const;
	//Print Pharmacy Information 
	void printPharmacyInfo() const;
	//Buy a Medicine from a Parmacy (Make Purchase)
	void makePurchase(string mid_name);
	//Sort Midecations by Name
	void sortMedicationsByName();
	//Search for Medication by ID 
	void findMedicationID(int id)const;
	//Search for Customer by ID :
	void findCustomerID(int id)const;
	//Display Expired Medications for a Pharmacy 
	void displayExpiredMedications(Date& a)const;
	//Remove Expired Medications for a Pharmacy 
	void removeExpiredMedications(Date& a);
	//Display Medications Running Low in a Pharmacy
	void runningLow()const;
	//Update Customer Information (the function will update the name and the address of the customer and it's ID will stay the same)
	void updateCustomer(int ID, const Customer& newC);
	//Update Medication Information
	void updateMedication(int ID, const Medication& newM);

};
