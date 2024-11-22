#pragma once
#include<iostream>
using namespace std;

class Date {
private:
	int day_, month_, year_;

public:
	//setters 
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	//getters
	int getD() const ;
	int getM() const ;
	int getY() const ;

	//constructer 
	//Deafuled constructer
	Date(int d = 0, int m = 0, int y = 0);
	//copy constructer
	Date(const Date& copy);

	//print function
	void printDate() const ;
};
