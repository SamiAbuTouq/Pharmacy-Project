#include<iostream>
#include"Address.h"
using namespace std;


//setters 
void Address::setEmail(string E) { if (E != "") email_ = E; else email_ = "Email was not provided"; }
void Address::setCity(string C) { if (C != "") city_ = C; else city_ = "City was not provided"; }
void Address::setStreetName(string SN) { if (SN != "") streetName_ = SN; else streetName_ = "Street name was not provided"; }
void Address::setMobileNo(long int MN) { if (MN > 0) mobileNo_ = MN; else mobileNo_ = 0000000000; }

//getters
string Address::getEmail() const { return email_; }
string Address::getCity() const { return city_; }
string Address::getStreetName() const { return streetName_; }
long int Address::getMobileNo() const { return mobileNo_; }

//constructer 
//Deafuled constructer
Address::Address(string E, string C, string SN, long int MN) {
	email_ = E;
	city_ = C;
	streetName_ = SN;
	mobileNo_ = MN;
}

//copy constructer
Address::Address(const Address& copy) {
	email_ = copy.email_;
	city_ = copy.city_;
	streetName_ = copy.streetName_;
	mobileNo_ = copy.mobileNo_;
}


//print function
void Address::printDate() const {
	cout << "**** Address **** " << endl;
	cout << "\t Email : " << email_ << endl;
	cout << "\t City : " << city_ << endl;
	cout << "\t Street Name : " << streetName_ << endl;
	cout << "\t Mobile Number : " << mobileNo_ << endl;
}

