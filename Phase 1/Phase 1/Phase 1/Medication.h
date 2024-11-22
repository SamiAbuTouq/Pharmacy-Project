#pragma once
#include<iostream>
#include<string>
#include"Date.h"
using namespace std;

class Medication {
private:
	string name_;
	string description_;
	float price_;
	int quantity_;  // Quantity in Stock								
	int d_, m_, y_; // Expiry Date 
	string barcode_;
	static int medicationID;
	Date exp;

public:
	//setters
	void setName(string name);
	void setDescreption(string description);
	void setPrice(float price);
	void setQuantity(int quantity);
	void setDate(int d, int m, int y);
	void setBarcode(string barcode);
	static void setMedicationId(int x);

	//getters
	string getName() const;
	string getDescreption() const;
	float getPrice() const;
	int getQuantity() const;
	int getD() const;
	int getM() const;
	int getY() const;
	string getBarcode() const;

	// Parametrized constructer (Defaulted) to initialize medication attributes
	Medication(string name = "No name", string description = "No description", float price = 0.0, int quantity = 0, int d = 0, int m = 0, int y = 0, string barcode = "0");
	//Display information about medication	
	void printMedicationInfo() const;
	static int getMedicationID();

	// Destructor 
	~Medication();



};