#include "Customer.h"
#include"Medication.h"
#include"Pharmacy.h"
#include<iostream>
using namespace std;

Pharmacy::Pharmacy(string name) :Pharmacyname_(name), pharmacyID_(pharmacyIDCounter_++), medicationCount_(0), customerCount_(0) {}
void Pharmacy::addMedication(const Medication& medication) {
    if (medicationCount_ < 50)
        medications_[medicationCount_++] = medication;
    else
        cout << "Cannot add more medications. Pharmacy is full." << endl;
}
int Pharmacy::getpharmacyID()const {
    return pharmacyID_;
}
void Pharmacy::removeMedication(int medicationID) {
    for (int i = 0; i < medicationCount_; ++i) {
        if (medications_[i].getMedicationID() == medicationID) {

            for (int j = i; j < medicationCount_ - 1; ++j) {
                medications_[j] = medications_[j + 1];
            }
            --medicationCount_;
            return;
        }
    }
    cout << "Medication ID not found." << endl;
}
void Pharmacy::addCustomer(const Customer& customer) {
    if (customerCount_ < 50) {

        //customers_[customerCount_] = customer;//////////////////////////////////////////////////////
        customerCount_++;
    }
    else {
        cout << "Cannot add more customers. Pharmacy is full.\n";
    }
}
void Pharmacy::printMedications() const {
    cout << "Medications for Pharmacy " << pharmacyID_ << endl;
    for (int i = 0; i < medicationCount_; ++i)
        medications_[i].printMedicationInfo();

}
void Pharmacy::printCustomers() const {
    cout << "Customers for Pharmacy " << pharmacyID_ << endl;
    for (int i = 0; i < customerCount_; ++i) {
        customers_[i].PrintCustomerInfo();
    }
}
bool Pharmacy::compareByMedicationCount(const Pharmacy& other) const {
    return medicationCount_ < other.medicationCount_;
}


bool Pharmacy::compareByCustomerCount(const Pharmacy& other) const {
    return customerCount_ < other.customerCount_;
}
long double Pharmacy::Totalrevunue()const {
    long double total = 0;
    for (int i = 0; i < medicationCount_; i++) {
        total = total + (medications_[i].getPrice() * medications_[i].getQuantity());
    }
    return total;
}
bool Pharmacy::compareByTotalRevenue(const Pharmacy& other) const {

    return Totalrevunue() < other.Totalrevunue();
}

