//Anthony Franklin afranklin18@cnm.edu
//1/27/2022

//FranklinP1
//Person Class, Date Class PersonTesterClass

#include <iostream>
#include "Person.h"
#include "Date.h"

int main()
{
    //Generating People
    Date today;
    cout << today.GetFormattedDate() << "\n\n";
    Person personA("Franklin, Anthony", 05, 20, 1980);
    Person personB;
    Person personC("Future Person!", 12, 25, 2099);
    Person personD;

    //Generating Impossible Date
    Date wrongDate{ 35, 97, 2001 ,"Wrong Date" };
    //Testing Setters
    personB.SetName("Doe, John");
    personB.SetBirthday(03, 04, 2008);
    personD.SetBirthday(wrongDate);
    (personA < personB) ? cout << personA.GetName() << " comes before " << personB.GetName() << " alphabetically.\n\n" : cout << personB.GetName() << " comes before " << personA.GetName() << " alphabetically.\n\n";
    cout << personA.GetFullDesc() << "\n" << personA.GetNameAge() << "\n\n" << personB.GetFullDesc() << "\n" << personB.GetNameAge() << "\n" << endl;
    cout << personC.GetNameAge() << "\n" << endl;
    cout << "\nTesting person with impossible birthday (test before using SetName() method) - " << personD.GetFullDesc() << endl;
    personD.SetName("I have an impossible birthday!");
    cout << "\nTesting person with impossible birthday (test after using SetName() method): " << personD.GetFullDesc() << endl;

    return 0;
}