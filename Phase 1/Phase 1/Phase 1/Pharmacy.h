#pragma once
#include<iostream>
#include"Medication.h"
#include"Customer.h"
using namespace std;
class Pharmacy {
    static int pharmacyIDCounter_;
    int pharmacyID_;
    string Pharmacyname_;
    Medication medications_[50];
    Customer customers_[50];
    int medicationCount_;
    int customerCount_;
public:
    Pharmacy(string = "No Name");
    void addMedication(const Medication&);
    void removeMedication(int);
    void addCustomer(const Customer&);
    int getpharmacyID()const;
    void printMedications() const;
    void printCustomers() const;
    bool compareByMedicationCount(const Pharmacy& other) const;
    bool compareByCustomerCount(const Pharmacy& other)const;
    long double Totalrevunue()const;
    bool compareByTotalRevenue(const Pharmacy& other) const;
};