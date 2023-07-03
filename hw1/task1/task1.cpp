#include <iostream>
#include "Student.cpp"

void print(Student s1) {
	cout << "ID: " << s1.getID() << "\nName: " << s1.getName()
		<< "\nScore: " << s1.getScore() << "\nGrade: " << s1.getGrage() << endl;
}

int main() {
	
	Student s1{ "111","AAA" };
	s1.setScore(8.5);
	print(s1);
	cout << endl;

	Student s2{ "222","BBB" };
	s2.setScore(6.5);
	print(s2);
	cout << endl;

	Student s3{ "333","CCC" };
	s3.setScore(15.4);
	print(s3);
	cout << endl;

	return 0;
}