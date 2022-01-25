//Anthony Franklin afranklin18@cnm.edu
//1/20/2020

//File: Date.h

#ifndef _DATE_H
#define _DATE_H

#include <chrono>
#include <string>
using namespace std::chrono;

class Date
{
private:
	year_month_day today = year_month_day{ floor<days>(system_clock::now()) };
	int yr{ static_cast<int>(today.year()) };
	unsigned mon{ static_cast<unsigned>(today.month()) };
	unsigned day{ static_cast<unsigned>(today.day()) };
	year_month_day ymd;
	std::string description {""};

public:
	Date();
	Date(std::string desc, int m, int d, int y); 

	void SetDesc(std::string d) { description = d; }
	void SetDate(int m, int d, int y);
	void SetDate(Date d);

	year_month_day GetYMD();
	bool ok() { return ymd.ok(); }
	std::string GetFormattedDate();
	int GetYear() { return yr; }
	int GetMonth() { return mon; }
	int GetDay() { return day; }
	std::string GetDescription() { return description; }

	//Overloading operators
	bool operator < (Date d);
	bool operator > (Date d);
	bool operator <= (Date d);
	bool operator >= (Date d);
	bool operator == (Date d);
};

#endif