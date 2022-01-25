//Anthony Franklin afranklin18@cnm.edu
//1/20/2020

//FranklinP1
//Person Class, Date Class PersonTesterClass

#include <iostream>
#include <chrono>
#include <string>
#include "PersonTester.h"

using namespace std::chrono;

int main()
{
    Person newPerson("Franklin, Anthony", 05,20,1980);
    Date Today;
    cout << Today.GetFormattedDate() << "\n" << endl;
    cout << newPerson.GetFullDesc() << "\n" << newPerson.GetNameAge();
    return 0;
}