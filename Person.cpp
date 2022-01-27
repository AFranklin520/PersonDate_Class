//Anthony Franklin afranklin18@cnm.edu
//1/27/2022

//Person.cpp

#include "Person.h"

Person::Person(string p, Date d)
{
    
    SetBirthday(d);
    name = p;
    bday.SetDesc(p);
    CalcAge();
}

Person::Person(string p, int m, int d, int y)
{
    name = p;
    SetBirthday(m, d, y); 
    CalcAge();
}
void Person::CalcAge()
{
    Date Today;
    ((Today.GetYear() < bday.GetYear()) || (Today.GetYear() == bday.GetYear()) && (Today.GetMonth() <= bday.GetMonth()) && (Today.GetDay() < bday.GetDay())) ? age = 0 : ((Today.GetMonth() <= bday.GetMonth()) && (Today.GetDay() < bday.GetDay())) ? age = (Today.GetYear() - bday.GetYear()-1) :  age = Today.GetYear() - bday.GetYear();
}
void Person::SetBirthday(int m, int d, int y)
{
    Date temp(m, d, y, name);
    if (temp.GetYearMonthDay().ok())
    {
        bday.SetDate(m, d, y,name);
        CalcAge();
    }
    else
    {
        Date defaultDate;
        bday = defaultDate;
        name = "INVALID BIRTHDATE ENTRY!";
        CalcAge();
    }
    
}

void Person::SetBirthday(Date d)
{
    if (d.GetYearMonthDay().ok())
    {
        bday = d;
        CalcAge();
    }
    else
    {
        Date defaultDate;
        bday = defaultDate;
        name = "INVALID BIRTHDATE ENTRY!";
        CalcAge();
    }
    
}

string Person::GetNameAge()
{
    return string(name + ' ' + to_string(age));
}

string Person::GetFullDesc()
{
    return string("\nName:" + name + "\nAge: " + to_string(age)+ "\nDate of Birth: " + bday.GetFormattedDate());
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
