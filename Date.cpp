//Anthony Franklin afranklin18@cnm.edu
//1/27/2022

//Date.cpp
#include <chrono>
#include "Date.h"

Date::Date()
{	//Set the Date variables to the computer's date.
	ymd = std::chrono::year_month_day{ std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()) };
	year = static_cast<int>(ymd.year());
	month = static_cast<unsigned>(ymd.month());
	day = static_cast<unsigned>(ymd.day());
	description = "Today's Date";
}
Date::Date(int m, int d, int y, string desc)
{
	description = desc;
	SetDate(m,d,y,desc);

}
void Date::SetDate(int m, int d, int y, string desc)
{
	description = desc;
	month = m, day = d, year = y;
	ymd = std::chrono::year{ y } / static_cast<unsigned>(m) / d;
}

std::string Date::GetFormattedDate()
{
	std::ostringstream y;

	std::string monName[12] = { "January",	"February ","March",
		"April", "May", "June", "July", "August",
		"September", "October", "November", "December" };


	y << monName[month-1] << " " << day
		<< ", " << year;
	return y.str();
}

