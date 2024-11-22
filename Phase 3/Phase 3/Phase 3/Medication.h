#pragma once
#include<iostream>
#include<string>
#include"Date.h"
using namespace std;

class Medication {
private:
	string name_;
	string	description_;
	float price_;
	int quantity_;  // Quantity in Stock								
	string barcode_;
	int medicationID_;
	Date expiryDate_;// Expiry Date
	static int nextMedicationID;

public:
	//setters
	void setName(string name);
	void setDescreption(string description);
	void setPrice(float price);
	void setQuantity(int quantity);
	void setBarcode(string barcode);
	void setExpiryDate(int day, int month, int year);
	static void setNextMedicationID(int x);//used to set the starting value for the next Medication ID

	//getters
	int getMedicationID() const;
	string getName() const;
	string getDescreption() const;
	float getPrice() const;
	int getQuantity() const;
	Date getExpiryDate() const;
	string getBarcode() const;

	//Default Parametrized constructer (Defaulted) to initialize medication attributes
	Medication(string name = "No name", string description = "No description", float price = 0.0, int quantity = 0, int d = 0, int m = 0, int y = 0, string barcode = "0");

	//Display information about medication	
	void printMedicationInfo() const;

	// Destructor 
	~Medication();



};