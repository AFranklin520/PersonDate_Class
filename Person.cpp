//Anthony Franklin afranklin18@cnm.edu
//1/20/2020

//Person.cpp

#include "Person.h"

Person::Person(string p, Date d)
{
    name = p, bday = d;
    bday.SetDesc(name);
    CalcAge();
}

Person::Person(string p, int m, int d, int y)
{
    name = p;
    bday.SetDate(m, d, y);
    bday.SetDesc(name); 
    CalcAge();
}
void Person::CalcAge()
{
    Date Today;
    //I also code this to work like (Today < bday)? etc....
    ((Today.GetYear() < bday.GetYear()) || (Today.GetYear() == bday.GetYear()) && (Today.GetMonth() <= bday.GetMonth()) && (Today.GetDay() < bday.GetDay())) ? age = 0 : ((Today.GetMonth() <= bday.GetMonth()) && (Today.GetDay() < bday.GetDay())) ? age = (Today.GetYear() - bday.GetYear()-1) :  age = Today.GetYear() - bday.GetYear();
}
void Person::SetBirthday(int m, int d, int y)
{
    bday.SetDate(m,d,y);
    bday.SetDesc(name);
    CalcAge();
}

void Person::SetBirthday(Date d)
{
    bday.SetDate(d);
    bday.SetDesc(name);
    CalcAge();
}

string Person::GetNameAge()
{
    return string(name + ' ' + to_string(age));
}

string Person::GetFullDesc()
{
    return string("\nName:" + bday.GetDescription() + "\nAge: " + to_string(age)+ "\nDate of Birth: " + bday.GetFormattedDate());
}

Date Person::GetBirthDay()
{
    return bday;
}

bool Person::operator<(Person p)
{
    return name < p.name;
}

bool Person::operator>(Person p)
{
    return name > p.name;
}
