#ifndef DATE_H
#define DATE_H

#include <cmath>
#include<string>
#include"Time.cpp"
#include<iostream>

using namespace std;

class DateTime {
private:
	int date;
	int month;
	int year;
	Time time;
    
public:
	DateTime()
		: date(1), month(1), year(1900), time() {};
	DateTime(int date, int month, int year)
		: date(date), month(month), year(year), time() {};
	DateTime(int date, int month, int year, const Time& time)
		: date(date), month(month), year(year), time(time) {};
	DateTime(int date, int month, int year, int hour, int min, int second)
		: date(date), month(month), year(year), time(hour, min, second) {};

	int getDate()
	{
		return date;
	}

	int getMonth()
	{
		return month;
	}

	int getYear() 
	{
		return year;
	}

	int getSecond()
	{
		return time.getSecond();
	}

	int getMinute() 
	{
		return time.getMinute();
	}

	int getHour()
	{
		return time.getHour();
	}

	void setDate(int date) 
	{
		this->date = date;
	}

	void setMonth(int month) 
	{
		this->month = month;
	}

	void setYear(int year)
	{
		this->year = year;
	}

	void setSecond(int second) 
	{
		time.setSecond(second);
	}

	void setMinute(int minute)
	{
		time.setMinute(minute);
	}

	void setHour(int hour) 
	{
		time.setHour(hour);
	}

	void add(int amount, string unit) {
		if (unit == "second")
			time.add(amount, unit);
		else if (unit == "minute")
			time.add(amount, unit);
		else if (unit == "hour")
			time.add(amount, unit);
		else if (unit == "date")
			date += amount;
		else if (unit == "week")
			date += amount * 7;
		else if (unit == "month") 
			month += amount;
		
		else if (unit == "year")
			year += amount;
			
		
		if (month > 12) {
			year += month / 12;
			month %= 12;
		}
		else if (month < 1) {
			year += month / 12 - 1;
			month = 12 + month % 12;
		}

	}

	int dateOfMonth() {
		if (month == 2)
		{
			if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
				return 29;
			else
				return 28;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
			return 30;
		else
			return 31;
	}

	int dateOfYear()
	{
		int day = 0;
		
		day += getDate();

		for (int i = 1; i < month; i++) {
			int temp = 0;
			if (i == 2)
			{
				if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
					temp = 29;
				else
					temp = 28;
			}
			else if (i == 4 || i == 6 || i == 9 || i == 11)
				temp = 30;
			else
				temp = 31;
			day += temp;
		}
		
		return day;
	
	}
	

	string dateOfWeek() {
		int day = dateOfYear();

		switch ((day + 5) % 7) {// Adjust the calculation to start from Monday (0)
		case 0:
			return "Monday";
		case 1:
			return "Tuesday";
		case 2:
			return "Wednesday";
		case 3:
			return "Thursday";
		case 4:
			return "Friday";
		case 5:
			return "Saturday";
		case 6:
			return "Sunday";
		}

	}


	int weekOfYear() {
		int day = dateOfYear();

		int Offset = (((day + 5) % 7) < 4) ? 1 - ((day + 5) % 7) : 8 - ((day + 5) % 7); // Adjust the calculation to start from Monday (0)

		day += Offset;

		// Calculate the ISO week number
		int weekNumber = day / 7 + 1;
		if (weekNumber == 53) {
			int daysInYear = dateOfMonth() * 12;
			if (daysInYear - day < 4)
				weekNumber = 1;
		}

		return weekNumber;
	}


	int quaterOfYear() {
		return (month - 1) / 3 + 1;
	}

	bool operator<(const DateTime& other) const {
		if (year != other.year)
			return year < other.year;
		if (month != other.month)
			return month < other.month;
		if (date != other.date)
			return date < other.date;
		return time < other.time;
	}

	bool operator>(const DateTime& other) const {
		return other < *this;
	}

	bool operator==(const DateTime& other) const {
		return year == other.year && month == other.month && date == other.date && time == other.time;
	}

	bool operator<=(const DateTime& other) const {
		return *this < other || *this == other;
	}

	bool operator>=(const DateTime& other) const {
		return *this > other || *this == other;
	}

	bool operator!=(const DateTime& other) const {
		return !(*this == other);
	}

	DateTime& operator++() {
		add(1, "date");
		return *this;
	}

	DateTime operator++(int) {
		DateTime temp(*this);
		operator++();
		return temp;
	}

	DateTime& operator--() {
		add(-1, "date");
		return *this;
	}

	DateTime operator--(int) {
		DateTime temp(*this);
		operator--();
		return temp;
	}

	//calculate	the	time difference	of	two	DateTime objects in	units of days
	float duration(DateTime& other) {
		int seconds1 = getYear() * 31536000 + dateOfYear() * 86400 + 
					   time.getHour() * 3600 + time.getMinute() * 60 + time.getSecond();
		
		int seconds2 = other.getYear() * 31536000 + other.dateOfYear() * 86400 + 
					   other.time.getHour() * 3600 + other.time.getMinute() * 60 + other.time.getSecond();
		
		return (abs(seconds2 - seconds1)/86400.0);
	
	}

	float operator-(DateTime& other) {
		if (*this > other)
			return duration(other);
		else
			return -duration(other);
	}
};
#endif
