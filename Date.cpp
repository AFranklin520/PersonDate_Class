//Anthony Franklin afranklin18@cnm.edu
//1/20/2020

//Date.cpp

#include "Date.h"

Date::Date()
{	//Set the Date variables to the computer's date.
	ymd = year_month_day{ floor<days>(system_clock::now()) };

	description = "Today's Date";
}
Date::Date(std::string desc, int m, int d, int y)
{
	description = desc;
	SetDate(m,d,y);

}
void Date::SetDate(int m, int d, int y)
{
	mon = m, day = d, yr = y;
	ymd = year{ y } / month{ static_cast<unsigned>(m) } / d;
}
void Date::SetDate(Date d)
{
	mon = d.mon;
	yr = d.yr;
	day = d.day;
	ymd = year{ static_cast<int>(d.yr) } / month{ static_cast<unsigned>(d.mon) } / d.day;
}
year_month_day Date::GetYMD()
{
	return ymd;
}
std::string Date::GetFormattedDate()
{
	std::ostringstream y;

	std::string monName[12] = { "January",	"February ","March",
		"April", "May", "June", "July", "August",
		"September", "October", "November", "December" };


	y << monName[mon-1] << " " << day
		<< ", " << yr;
	return y.str();
}

bool Date::operator<(Date d)
{
	return sys_days{ ymd } < sys_days{ d.GetYMD()};
}

bool Date::operator>(Date d)
{
	return sys_days{ ymd } > sys_days{ d.GetYMD() };
}

bool Date::operator<=(Date d)
{
	return sys_days{ ymd } <= sys_days{ d.GetYMD() };
}

bool Date::operator>=(Date d)
{
	return sys_days{ ymd } >= sys_days{ d.GetYMD() };
}

bool Date::operator==(Date d)
{
	return sys_days{ ymd } == sys_days{ d.GetYMD() };
}
