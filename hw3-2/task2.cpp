#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//using vector to store the data
template<typename T>
void ascendingSort(vector<T>& numbers) {
    sort(numbers.begin(), numbers.end());
}

template<typename T>
void descendingAbsSort(vector<T>& numbers) {
    sort(numbers.begin(), numbers.end(), [](T a, T b) {
        return std::abs(a) > std::abs(b);
        });
}

template<typename T>
void evenOddSort(vector<T>& numbers) {
    sort(numbers.begin(), numbers.end(), [](T a, T b) {
        if (a % 2 == 0 && b % 2 == 0) {  // both even
            return a < b;
        }
        else if (a % 2 != 0 && b % 2 != 0) {  // both odd
            return a > b;
        }
        else if (a % 2 == 0 && b % 2 != 0) {  // a even, b odd
            return true;
        }
        else {  // a odd, b even
            return false;
        }
        });
}

template<typename T>
void customSort(vector<T>& numbers) {
    sort(numbers.begin(), numbers.end(), [](T a, T b) {
        if (a < 0 && b < 0) {  // both negative
            return a > b;
        }
        else if (a >= 0 && b >= 0) {  // both positive
            return a < b;
        }
        else if (a < 0 && b >= 0) {  // a negative, b positive
            return true;
        }
        else {  // a positive, b negative
            return false;
        }
        });
}

int main() {


    // Ascending sort
    vector<int> numbers1 = { 5, 2, 8, 3, 1 };
    ascendingSort(numbers1);
    cout << "Ascending Sort: ";
    for (int num : numbers1) {
        cout << num << " ";
    }
    cout << endl;

    // Descending sort of absolute value
    vector<int> numbers2 = { -5, 2, -8, 3, -1 };
    descendingAbsSort(numbers2);
    cout << "Descending Sort of Absolute Value: ";
    for (int num : numbers2) {
        cout << num << " ";
    }
    cout << endl;

    // Even numbers ascending, odd numbers descending
    vector<int> numbers3 = { 5, 2, 8, 3, 1 };
    evenOddSort(numbers3);
    cout << "Even Numbers Ascending, Odd Numbers Descending: ";
    for (int num : numbers3) {
        cout << num << " ";
    }
    cout << endl;

    // Negative numbers descending, positive numbers ascending
    vector<int> numbers4 = { -5, 2, -8, 3, -1 };
    customSort(numbers4);
    cout << "Negative Numbers Descending, Positive Numbers Ascending: ";
    for (int num : numbers4) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

//using array to store the data
/*template<typename T, size_t size>
void ascendingSort(T(&numbers)[size]) {
    sort(numbers, numbers + size);
}

template<typename T, size_t size>
void descendingAbsSort(T(&numbers)[size]) {
    sort(numbers, numbers + size, [](T a, T b) {
        return abs(a) > abs(b);
        });
}

template<typename T, size_t size>
void evenOddSort(T(&numbers)[size]) {
    sort(numbers, numbers + size, [](T a, T b) {
        if (a % 2 == 0 && b % 2 == 0) {
            return a < b;
        }
        else if (a % 2 != 0 && b % 2 != 0) {
            return a > b;
        }
        else if (a % 2 == 0 && b % 2 != 0) {
            return true;
        }
        else {
            return false;
        }
        });
}

template<typename T, size_t size>
void customSort(T(&numbers)[size]) {
    sort(numbers, numbers + size, [](T a, T b) {
        if (a < 0 && b < 0) {
            return a > b;
        }
        else if (a >= 0 && b >= 0) {
            return a < b;
        }
        else if (a < 0 && b >= 0) {
            return true;
        }
        else {
            return false;
        }
        });
}

int main() {

    int numbers1[] = { 5, 2, 8, 3, 1 };
    ascendingSort(numbers1);
    cout << "Ascending Sort: ";
    for (int num : numbers1) {
       cout << num << " ";
    }
    cout << endl;

    int numbers2[] = { -5, 2, -8, 3, -1 };
    descendingAbsSort(numbers2);
    cout << "Descending Sort of Absolute Value: ";
    for (int num : numbers2) {
        cout << num << " ";
    }
    cout << endl;


    int numbers3[] = { 5, 2, 8, 3, 1 };
    evenOddSort(numbers3);
    cout << "Even Numbers Ascending, Odd Numbers Descending: ";
    for (int num : numbers3) {
        cout << num << " ";
    }
    cout << endl;

    int numbers4[] = { -5, 2, -8, 3, -1 };
    customSort(numbers4);
    cout << "Negative Numbers Descending, Positive Numbers Ascending: ";
    for (int num : numbers4) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}*/
