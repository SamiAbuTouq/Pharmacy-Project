#include"Prescription.h"
using namespace std;

//default constructor
Prescription::Prescription() {
	FDAnumber = 0;
}

//Prametrized constructor
Prescription::Prescription(int FDA,Date AppDate, string name, string description, float price, int quantity, int day, int month, int year, string barcode)
	: Medication( name,  description,  price,  quantity,  day,  month,  year, barcode) {
	setFDA(FDA);
	setApprovalDate(AppDate.getD(), AppDate.getM(), AppDate.getY()); // Or simpliy ApprovalDate=AppDate;
}

//setters
void Prescription::setFDA(int FDANumber) {
	if (FDANumber > 0)
		this->FDAnumber = FDANumber;

}
void Prescription::setApprovalDate(int day, int month, int year) {
	ApprovalDate.setDay(day);
	ApprovalDate.setMonth(month);
	ApprovalDate.setYear(year);
}

//getters
int Prescription::getFDA() const { return FDAnumber; }
Date Prescription::getApprovalDate()  const { return ApprovalDate; }

//Functions
void Prescription::print() const {
	Medication::printMedicationInfo();
	cout << "FDANumber : " << FDAnumber << endl;
	cout << "ApprovalDate: ";
	ApprovalDate.printDate();

}