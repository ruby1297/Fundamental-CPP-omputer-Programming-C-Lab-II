#ifndef TIME_H
#define TIME_H

#include <string>
using namespace std;

class Time{
	private:
		int Hour;
		int Minute;
		int Second;
	public:
		Time() : Hour(0), Minute(0), Second(0) {}; // hour = minute = second = 0
		Time(int hour, int minute, int second) : Hour(hour), Minute(minute), Second(second) {};
		int getHour()
		{
			return Hour;
		}
		int getMinute()
		{
			return Minute;
		}
		int getSecond()
		{
			return Second;
		}

		void setHour(int hour)
		{
			Hour = hour;
		}
		void setMinute(int minute)
		{
			Minute = minute;
		}
		void setSecond(int second)
		{
			Second = second;
		}
		void add(int amount, string unit)
		{
			if (unit == "second")
				Second += amount;

			else if (unit == "minute")
				Minute += amount;

			else if (unit == "hour")
				Hour += amount;

			if (Second >= 60)
			{
				Minute += Second / 60;
				Second %= 60;
			}
			else if (Second < 0)
			{
				Minute += Second / 60 - 1;
				Second = 60 + Second % 60;
			}
			if (Minute >= 60)
			{
				Hour += Minute / 60;
				Minute %= 60;
			}
			else if (Minute < 0)
			{
				Hour += Minute / 60 - 1;
				Minute = 60 + Minute % 60;
			}
			if (Hour >= 24)
			{
				Hour %= 24;
			}
			else if (Hour < 0)
			{
				Hour = 24 + Hour % 24;
			}
		}
		int duration(const Time& other) {
			int time1 = Hour * 3600 + Minute * 60 + Second;
			int time2 = other.Hour * 3600 + other.Minute * 60 + other.Second;
			return std::abs(time1 - time2);
		}

		bool operator<(const Time& other) const {
			return (Hour < other.Hour) ||
				(Hour == other.Hour && Minute < other.Minute) ||
				(Hour == other.Hour && Minute == other.Minute && Second < other.Second);
		}

		bool operator>(const Time& other) const {
			return other < *this;
		}

		bool operator==(const Time& other) const {
			return (Hour == other.Hour) && (Minute == other.Minute) && (Second == other.Second);
		}

		bool operator<=(const Time& other) const {
			return (*this < other) || (*this == other);
		}

		bool operator>=(const Time& other) const {
			return (*this > other) || (*this == other);
		}

		bool operator!=(const Time& other) const {
			return !(*this == other);
		}
		

		Time& operator++() {
			Second++;
			if (Second >= 60)
			{
				Minute += Second / 60;
				Second %= 60;
			}
			else if (Second < 0)
			{
				Minute += Second / 60 - 1;
				Second = 60 + Second % 60;
			}
			if (Minute >= 60)
			{
				Hour += Minute / 60;
				Minute %= 60;
			}
			else if (Minute < 0)
			{
				Hour += Minute / 60 - 1;
				Minute = 60 + Minute % 60;
			}
			if (Hour >= 24)
			{
				Hour %= 24;
			}
			else if (Hour < 0)
			{
				Hour = 24 + Hour % 24;
			}
			return *this;
		}

		Time operator++(int) {
			Time oldTime = *this;
			++(*this);
			return oldTime;
		}

		Time& operator--() {
			// Prefix decrement operator (--t)
			Second--;
			if (Second >= 60)
			{
				Minute += Second / 60;
				Second %= 60;
			}
			else if (Second < 0)
			{
				Minute += Second / 60 - 1;
				Second = 60 + Second % 60;
			}
			if (Minute >= 60)
			{
				Hour += Minute / 60;
				Minute %= 60;
			}
			else if (Minute < 0)
			{
				Hour += Minute / 60 - 1;
				Minute = 60 + Minute % 60;
			}
			if (Hour >= 24)
			{
				Hour %= 24;
			}
			else if (Hour < 0)
			{
				Hour = 24 + Hour % 24;
			}
			return *this;
		}

		Time operator--(int) {
			// Postfix decrement operator (t--)
			Time oldTime = *this;
			--(*this);
			return oldTime;
		}

		Time& operator+=(int seconds) {
			Second += seconds;
			if (Second >= 60)
			{
				Minute += Second / 60;
				Second %= 60;
			}
			else if (Second < 0)
			{
				Minute += Second / 60 - 1;
				Second = 60 + Second % 60;
			}
			if (Minute >= 60)
			{
				Hour += Minute / 60;
				Minute %= 60;
			}
			else if (Minute < 0)
			{
				Hour += Minute / 60 - 1;
				Minute = 60 + Minute % 60;
			}
			if (Hour >= 24)
			{
				Hour %= 24;
			}
			else if (Hour < 0)
			{
				Hour = 24 + Hour % 24;
			}
			return *this;
		}

		Time& operator-=(int seconds) {
			Second -= seconds;
			if (Second >= 60)
			{
				Minute += Second / 60;
				Second %= 60;
			}
			else if (Second < 0)
			{
				Minute += Second / 60 - 1;
				Second = 60 + Second % 60;
			}
			if (Minute >= 60)
			{
				Hour += Minute / 60;
				Minute %= 60;
			}
			else if (Minute < 0)
			{
				Hour += Minute / 60 - 1;
				Minute = 60 + Minute % 60;
			}
			if (Hour >= 24)
			{
				Hour %= 24;
			}
			else if (Hour < 0)
			{
				Hour = 24 + Hour % 24;
			}
			return *this;
		}

		int operator-(const Time& other) const {
			int time1 = Hour * 3600 + Minute * 60 + Second;
			int time2 = other.Hour * 3600 + other.Minute * 60 + other.Second;
			return time1 - time2;
		}

};
#endif
