#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// maximum
template <typename T>
T const &Max(T const &a, T const &b)
{
	return a < b ? b : a;
}

// minimum
template <typename T>
T const &Min(T const &a, T const &b)
{
	return a > b ? b : a;
}

// Find	the	smallest negative element in an array of type T
template <typename T>
T findSmallestNegative(const T *arr, size_t size)
{
	T smallestNegative = 0;

	for (size_t i = 0; i < size; ++i)
	{
		if (arr[i] < 0 && arr[i] < smallestNegative)
		{
			smallestNegative = arr[i];
		}
	}

	return smallestNegative;
}

// Find	the	largest positive element in an array of type T
template <typename T>
T findLargestPositive(const T *arr, size_t size)
{
	T largestPositive = 0;

	for (size_t i = 0; i < size; ++i)
	{
		if (arr[i] > 0 && arr[i] > largestPositive)
		{
			largestPositive = arr[i];
		}
	}

	return largestPositive;
}

// Sort	ascending array of type	T
template <typename T>
void Sort(T *arr, size_t size)
{
	sort(arr, arr + size);
}

int main()
{
	// test function main.cpp
	int i = 39;
	int j = 20;
	cout << "Max(i, j): " << Max(i, j) << endl;
	double f1 = 13.5;
	double f2 = 20.7;
	cout << "Max(f1, f2): " << Max(f1, f2) << endl;
	string s1 = "Hello";
	string s2 = "World";
	cout << "Max(s1, s2): " << Max(s1, s2) << endl;

	cout << "=================\n";

	int h = 39;
	int n = 20;
	cout << "Min(h,n): " << Min(h, n) << endl;
	double h1 = 13.5;
	double h2 = 20.7;
	cout << "Min(h1, h2): " << Min(h1, h2) << endl;
	string n1 = "Hello";
	string n2 = "World";
	cout << "Min(n1, n2): " << Min(s1, s2) << endl;

	cout << "=================\n";

	int arr[9] = {1, -8, 3, 2, -5, -6, 4, -7, -9};
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "orginal array: ";
	for (size_t i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	Sort(arr, size);
	cout << "sorting array: ";
	for (size_t i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	double arr1[9] = {1.0, -8.0, 3.1, 2.1, -5.0, -6.2, 4.3, -7.4, -9.5};
	double size1 = sizeof(arr1) / sizeof(arr1[0]);
	cout << "orginal arr1ay: ";
	for (size_t i = 0; i < size1; ++i)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;
	Sort(arr1, size1);
	cout << "sorting arr1ay: ";
	for (size_t i = 0; i < size1; ++i)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;

	cout << "=================\n";
	cout << "findSmallestNegative(arr): " << findSmallestNegative(arr, size) << endl;
	cout << "findLargestPositive(arr): " << findLargestPositive(arr, size) << endl;
	cout << "findSmallestNegative(arr): " << findSmallestNegative(arr1, size1) << endl;
	cout << "findLargestPositive(arr): " << findLargestPositive(arr1, size1) << endl;

	return 0;
}