#include<string>
using namespace std;

class Time {
private:
	int Hour;
	int Minute;
	int Second;
public:
	Time() {};
	Time(int hour, int minute, int second) : Hour(hour), Minute(minute), Second(second) {};
	
	int getHour() {
		return Hour;
	}
	
	void setHour(int hour){
		if (hour >= 0 && hour < 24)
			Hour = hour;
	}
	
	int getMinute() {
		return Minute;
	}
	
	void setMinute(int minute) {
		if (minute >= 0 && minute < 60)
			Minute = minute;
	}

	int getSecond() {
		return Second;
	}
	
	void setSecond(int second) {
		if (second >= 0 && second < 60)
			Second = second;
	}
	
	void add(int second) {
		Second += second;
		if (Second >= 60) {
			Minute += Second / 60;
			Second %= 60;
		}
		if (Minute >= 60) {
			Hour += Minute / 60;
			Minute %= 60;
		}
		if (Hour >= 24) 
			Hour %= 24;
		
	}
	
	void sub(int second) {
		Second -= second;
		if (Second < 0) {
			Minute += Second / 60;
			Second %= 60;
		}
		if (Minute < 0) {
			Hour += Minute / 60;
			Minute %= 60;
		}
		if (Hour < 0) 
			Hour %= 24;
	}
	
	string getTime() {
		return to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second); 
	}
	
	int compare(Time another) {
		if (Hour > another.Hour)
			return 1;
		else if (Hour < another.Hour)
			return -1;
		else if (Minute > another.Minute)
			return 1;
		else if (Minute < another.Minute)
			return -1;
		else if (Second > another.Second)
			return 1;
		else if (Second < another.Second)
			return -1;
		else
			return 0; 
	}
	
};