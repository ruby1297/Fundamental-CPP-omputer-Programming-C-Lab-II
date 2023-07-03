#include<iostream>
#include"Math.cpp"

using namespace std;

int main(void) {
	static double a = -6, b = 8, c[10] = { 1,-2,8,-5,12,9,7,-4,3,-6 };
	int n = 5;

	cout << "PI: " << Math::getPI() << endl;
	cout << "Absolute of A: " << Math::abs(a) << endl;
	cout << "Addition of A and B: " << Math::add(a, b) << endl;
	cout << "Subtraction of A and B: " << Math::sub(a, b) << endl;
	cout << "Minimum of A and B: " << Math::min(a, b) << endl;
	cout << "Maximum of A and B: " << Math::max(a, b) << endl;
	cout << "Average of A and B: " << Math::avg(a, b) << endl;
	cout << "A to the power of n is: " << Math::pow(a, n) << endl;
	cout << "Minimum of array C: " << Math::min(c) << endl;
	cout << "Maximum of array C: " << Math::max(c) << endl;
	cout << "Average of array C: " << Math::avg(c) << endl;

	return 0;
}