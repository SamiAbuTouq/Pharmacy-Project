#pragma once
#include"Medication.h"
#include<string>
using namespace std;

class OffTheShelf :public Medication {
private:
	bool BOGOF_;
	Date OfferEnds_;

public:
	//defaulted constructor
	OffTheShelf(bool BOGOF=false,string name = "No name", string description = "No description", float price=0, int quantity=0, int day=0, int month=0, int year=0, string barcode="00");

	//setters
	void setBOGOF(bool x);
	void setOfferEnds(int day, int month, int year);

	//getters
	bool getBOGOF()const;
	Date getOfferEnds()const;

	//Functions
	void print()const;
};