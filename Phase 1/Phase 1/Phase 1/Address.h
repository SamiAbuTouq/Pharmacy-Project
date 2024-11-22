#pragma once
#include<iostream>
using namespace std;

class Address {
private:
	string email_;
	string city_;
	string streetName_;
	long int mobileNo_;
	
public:
	//setters 
	void setEmail(string E);
	void setCity(string C);
	void setStreetName(string SN);
	void setMobileNo(long int MN);

	//getters
	string getEmail() const;
	string getCity() const ;
	string getStreetName() const ;
	long int getMobileNo() const ;
								 
	//constructer 
	//Deafuled constructer
	Address(string E ="Email was not provided" , string C= "City was not provided", string SN= "Street name was not provided", long int MN= 0000000000);

	//copy constructer
	Address(const Address& copy);

	//print function
	void printDate() const;

};
