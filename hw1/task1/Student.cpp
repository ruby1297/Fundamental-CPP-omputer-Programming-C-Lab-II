#include<string>
using namespace std;

class Student {
private:
	string ID;
	string Name;
	double Score;
public:
	Student(){};
	Student(string id, string name) :ID(id), Name(name) {};

	void setID(string id) {
		ID = id;
	}

	string getID() {
		return ID;
	}

	void setName(string name) {
		Name = name;
	}

	string getName() {
		return Name;
	}

	void setScore(double score) {
		if (score < 0)
			Score = 0;
		else if (score > 10)
			Score = 10;
		else
			Score = score;
	}

	double getScore() {
		return Score;
	}

	string getGrage() {
		if (Score >= 9.0)
			return "A";
		if (Score >= 8.0 && Score < 9.0)
			return "B+";
		if (Score >= 7.0 && Score < 8.0)
			return "B";
		if (Score >= 6.0 && Score < 7.0)
			return "C+";
		if (Score >= 5.0 && Score < 6.0)
			return "C";
		if (Score >= 4.0 && Score < 5.0)
			return "D+";
		if (Score >= 3.0 && Score < 4.0)
			return "D";
		if (Score < 4.0)
			return "F";
	}

};