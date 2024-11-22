#include"Customer.h"
#include<iostream>
#include <string>
using namespace std;
int Customer::count = 0;


// Deafault Parameterized constructor (Defaulted)
Customer::Customer(string name, string email, string city, string stName, long int phNum) :customerID(count + 20041121) {
	setCustomerName(name);
	setCustomerAddress(email, city, stName, phNum);
	count++;
}


// Copy constructor
Customer::Customer(const Customer& copy) :customerID(copy.customerID), customerName(copy.customerName), address(copy.address) {
	count++;
}


// Setters 
void Customer::setCustomerName(string n) {
	while (n == "") { cout << "Error re-enter name" << endl;	cin >> n; }customerName = n;
}

void Customer::setCustomerAddress(string E, string C, string SN, long int phNum) {
	address.setEmail(E);
	address.setCity(C);
	address.setStreetName(SN);
	address.setMobileNo(phNum);
}

void Customer::setCustomerAddress(const Address& add) {
	address.setEmail(add.getEmail());
	address.setCity(add.getCity());
	address.setStreetName(add.getStreetName());
	address.setMobileNo(add.getMobileNo());
}



// Getters
string Customer::getCustomerName()const { return customerName; }
int Customer::getCustomerID()const { return customerID; }
Address Customer::getCustomerAddress()const { return address; }
int Customer::getcount() { return count; }


// Print Customer Information Function
void Customer::PrintCustomerInfo() const {
	cout << "****** Customer Info ******" << endl;
	cout << "\t Customer ID :" << customerID << endl;
	cout << "\t Customer Name : " << customerName << endl;
	address.printAddress();
}


// Destructor 
Customer::~Customer() {}

