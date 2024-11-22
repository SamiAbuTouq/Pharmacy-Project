#include"Customer.h"
#include<iostream>
#include <string>
using namespace std;
int Customer::count = 0;


// Deafault Parameterized constructor (Defaulted)
Customer::Customer(string x, string y, string z) :customerID(count + 10002000) {
	setCustomerName(x);
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



// Getters
string Customer::getCustomerName()const { return customerName; }
int Customer::getCustomerID()const { return customerID; }


int Customer::getcount() { return count; }


// Print customer information Function
void Customer::PrintCustomerInfo() const {
	cout << "****** Customer Info ******" << endl;
	cout << " Customer ID :" << customerID << endl;
	cout << " Customer Name : " << customerName << endl;
	cout << "Customer City : " << address.getCity() << endl;
	cout << "Customer street-Name : " << address.getStreetName() << endl;
	cout << "Customer mobile number : " << address.getMobileNo() << endl;
	cout << "Customer Email : " << address.getEmail();
}


// Destructor 
Customer::~Customer() {}

