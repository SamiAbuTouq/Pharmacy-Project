#include<iostream>
#include<string>
#include"Medication.h"
using namespace std;
int Medication::nextMedicationID = 1;

//setters
void Medication::setName(string name) { if (name != "")  name_ = name; else name_ = "No name"; }
void Medication::setDescreption(string description) { if (description != "") description_ = description; else description_ = "No description"; }
void Medication::setPrice(float price) { if (price > 0) price_ = price; else price_ = 0; }
void Medication::setQuantity(int quantity) { if (quantity >= 0)quantity_ = quantity; else quantity_ = 0; }
void Medication::setExpiryDate(int day, int month, int year) {expiryDate_.setDay(day); expiryDate_.setMonth(month); expiryDate_.setYear(year);}
void Medication::setBarcode(string barcode) { if (barcode != "")barcode_ = barcode; else barcode_ = "0"; }
void Medication::setNextMedicationID(int x) { if (x > 0) nextMedicationID = x; }//used to set the starting value for the next Medication ID


//getters
int Medication::getMedicationID() const { return medicationID_; }
string Medication::getName() const { return name_; }
string Medication::getDescreption() const { return description_; }
float Medication::getPrice() const { return price_; }
int Medication::getQuantity() const { return quantity_; }
Date Medication::getExpiryDate() const { return expiryDate_	; }
string Medication::getBarcode() const { return barcode_; }


//Default Parametrized constructer (Defaulted) to initialize medication attributes
Medication::Medication(string name, string description, float price, int quantity, int day, int month, int year, string barcode) {
	medicationID_ = nextMedicationID++;
	setName(name);
	setDescreption(description);
	setPrice(price);
	setQuantity(quantity);
	setExpiryDate(day, month, year);
	setBarcode(barcode);
}

//Display information about medication	
void Medication::printMedicationInfo() const {
	cout << "****** Medication Info ******" << endl;
	cout << "Medication ID : " << medicationID_ << endl;
	cout << "Medication Name : " << name_ << endl;
	cout << "Medication Description : " << description_ << endl;
	cout << "Medication Price : $" << price_ << endl;
	cout << "Quantity in Stock : " << quantity_ << endl;
	cout << "Expiry Date : "; expiryDate_.printDate();
	cout << "Medication Barcode : " << barcode_ << endl << endl;
}


// Destructor 
Medication::~Medication() {}



