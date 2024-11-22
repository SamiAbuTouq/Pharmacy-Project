#pragma once
#include"Medication.h"

class Prescription :public Medication {
private:
	int FDAnumber;
	Date ApprovalDate;

public:
	//default constructor
	Prescription();

	//Prametrized constructor
	Prescription(int FDA, Date AppDate, string name, string description, float price, int quantity, int day, int month, int year, string barcode);


	//setters
	void setFDA(int FDANumber);
	void setApprovalDate(int day, int month, int year);

	//getters
	int getFDA() const;
	Date getApprovalDate() const;

	//Fucntions
	void print()const;
};