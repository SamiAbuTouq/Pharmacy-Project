#include<iostream>
#include<string>
#include"Medication.h"
#include"Date.h"
using namespace std;
int Medication::medicationID = 0;


//setters
void Medication::setName(string name) { if (name != "")  name_ = name; else name_ = "No name"; }
void Medication::setDescreption(string description) { if (description != "") description_ = description; else description_ = "No description"; }
void Medication::setPrice(float price) { if (price > 0) price_ = price; else price_ = 0; }
void Medication::setQuantity(int quantity) { if (quantity >= 0)quantity_ = quantity; else quantity_ = 0; }
void Medication::setDate(int d, int m, int y) {
	if (d > 0 && d < 32) d_ = d; else d_ = 0;
	if (m > 0 && m < 13) m_ = m;  else m_ = 0;
	if (y > 1800) y_ = y; else y_ = 0;
}
void Medication::setBarcode(string barcode) { if (barcode != "")barcode_ = barcode; else barcode_ = "0"; }
void Medication::setMedicationId(int x) { if (x > 0) medicationID = x; }

//getters
string Medication::getName() const { return name_; }
string Medication::getDescreption() const { return description_; }
float Medication::getPrice() const { return price_; }
int Medication::getQuantity() const { return quantity_; }
int Medication::getD() const { return d_; }  //Date getters
int Medication::getM() const { return m_; }  //Date getters
int Medication::getY() const { return y_; }  //Date getters
string Medication::getBarcode() const { return barcode_; }
int Medication::getMedicationID() { return medicationID; }

// Parametrized constructer (Defaulted) to initialize medication attributes
Medication::Medication(string name, string description, float price, int quantity, int d, int m, int y, string barcode) {
	setName(name);
	setDescreption(description);
	setPrice(price);
	setQuantity(quantity);
	setDate(d, m, y);
	setBarcode(barcode);
}

//Display information about medication	
void Medication::printMedicationInfo() const {
	cout << "****** Medication Info ******" << endl;
	cout << "Medication Name : " << name_ << endl;
	cout << "Medication Description : " << description_ << endl;
	cout << "Medication Price : $" << price_ << endl;
	cout << "Quantity in Stock : " << quantity_ << endl;
	cout << "Expiry Date (d,m,y) : " << '(' << d_ << ',' << m_ << ',' << y_ << ')' << endl;
	cout << "Medication Barcode : " << barcode_ << endl << endl;
}



