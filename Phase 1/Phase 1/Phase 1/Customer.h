#pragma once
#include<iostream>
#include <string>
#include"Address.h"
using namespace std;
class Customer {
private:
	string customerName;
	const int customerID;
	Address address;
	static int count;


public:
	// Constructers
	Customer(string = "No Name", string = "No Phone Number", string = "No Address");
	Customer(const Customer& copy);



	//setters
	void setCustomerName(string n);


	//getters
	int getCustomerID()const;
	string getCustomerName()const;


	static int getcount();

	void PrintCustomerInfo() const;

	// Destructor 
	~Customer();
};
