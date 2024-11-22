#include"OffTheShelf.h"
using namespace std;

//defaulted constructor
OffTheShelf::OffTheShelf(bool BOGOF, string name, string description, float price, int quantity, int day, int month, int year, string barcode)
	:Medication(name, description, price, quantity, day, month, year, barcode)
{
  setBOGOF(BOGOF);
  if (BOGOF) setOfferEnds(1, 4 + 3, 2024);
  else  setOfferEnds(1, 4, 2024 + 2);
}

//setters
void OffTheShelf::setBOGOF(bool x) {
	BOGOF_ = x;
}
void OffTheShelf::setOfferEnds(int day, int month, int year)
{
	OfferEnds_.setDay(day);
	OfferEnds_.setMonth(month);
	OfferEnds_.setYear(year);

}
//getters

bool OffTheShelf::getBOGOF()const { return BOGOF_	; }
Date OffTheShelf::getOfferEnds()const { return OfferEnds_; }

//Functions
void OffTheShelf::print()const {
	Medication::printMedicationInfo();
	cout << "Buy One Get One Free : ";
	if (BOGOF_ == 0)
		cout << " No" << endl;
	else {
		cout << "Yes" << endl;
		cout << "Offer Ends in ";
		OfferEnds_.printDate();
	}
}