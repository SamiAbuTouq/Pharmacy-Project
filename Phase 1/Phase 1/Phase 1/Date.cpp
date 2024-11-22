#include<iostream>
#include"Date.h"
using namespace std;

	//setters
	 void Date::setDay(int d){ if (d > 0 && d < 32) day_ = d; else day_ = 0; }
	 void Date::setMonth(int m){ if (m > 0 && m < 13) month_ = m;  else month_ = 0; }
	 void Date::setYear(int y) { if (y > 1800) year_ = y; else year_ = 0; }

	 //getters
	 int Date::Date::getD() const { return day_; }
	 int Date::Date::getM() const { return month_; }
	 int Date::Date::getY() const { return year_; }

	 //constructer 
	 //Deafuled constructer
	 Date::Date (int d, int m ,int y){
		 day_ = d;
		 month_ = m;
		 year_ = y;}
	 //copy constructer
	 Date::Date(const Date& copy) {
		 day_ = copy.day_;
		 month_ = copy.month_;
		 year_ = copy.year_;
	 }

	 //print function
	 void Date::printDate()const {
		 cout << day_ << "\\" << month_ << "\\" << year_ << endl;
	 }