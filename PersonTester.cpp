//Anthony Franklin afranklin18@cnm.edu
//1/20/2020

//PersonTester.cpp

#include "PersonTester.h"
#include <iostream>

void PersonTester::AskForBdayInfo(Person& p)
{
	Date today;
	string name;
	string m;
	string d;
	string y;
	bool isValid = false;
	cout << "\nPlease enter your name (Last, First format): \n" << endl;
	getline(cin, name);
	while (isValid == false)
	{
		cout << "\nPlease enter your date of birth (Format: \"mm/dd/yyyy\"): \n" << endl;
		getline(cin, m, '/');
		getline(cin, d, '/');
		getline(cin, y);
		Date date(name, static_cast<unsigned>(stoi(m)), static_cast<unsigned>(stoi(d)),  stoi(y));
		if (date.ok() && (date <= today)) 
		{
			isValid = true;
			p.SetName(name);
			p.SetBirthday(date);
			cout << "Success! " << p.GetFullDesc() << endl;
		}
		else {
			cout << "\nSorry, " << date.GetYMD() << " is an invalid date.Please try again.\n";
		}
	}
	
}
