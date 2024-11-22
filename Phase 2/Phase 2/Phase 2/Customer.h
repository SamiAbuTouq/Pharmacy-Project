#pragma once
#include<iostream>
#include <string>
#include"Address.h"

class Customer {
private:
	string customerName;
	const int customerID;
	Address address;
	static int count;


public:
	// Constructers
	Customer(string name = "No Name provided", string email = "No Email Provided", string city = "No City Provided", string stName = "No Street Name Provided", long int phNum =0000000000);
	Customer(const Customer& copy);



	// Setters
	void setCustomerName(string n);
	void setCustomerAddress(string E, string C, string SN, long int phNum);
	void setCustomerAddress(const Address& add);

	// Getters
	int getCustomerID()const;
	string getCustomerName()const;
	Address getCustomerAddress()const;
	static int getcount();


	// Print Customer Information Function
	void PrintCustomerInfo() const;

	// Destructor 
	~Customer();
};
