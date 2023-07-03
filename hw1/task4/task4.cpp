#include<iostream>
#include"Book.cpp"

using namespace std;

int main() {
	Book b1("C++ Primer, 5th Edition", "Stanley B. Lippman");
	Book b2("Object-Oriented Programming Simplified", "Hari Mohan Prasad");
	Book b3("Design Patterns in Modern C++", "Dmitri Nesteruk");

	b1.setQuantity(5);
	b2.setQuantity(2);
	b3.setQuantity(4);
	
	string title;
	int quantity;
	while (true) {
		cout << "Please input book title: ";
		getline(cin, title);
		cout << "Please input quantity: ";
		cin >> quantity;

		
		if (title != b1.getTitle() && title != b2.getTitle() && title != b3.getTitle()) {
			cout << "Book not found\n\n";
		}
		else if (title == b1.getTitle()) {
			if (quantity > b1.getQuantity()) 
				cout << "The quantity is not enough.Please try again!\n\n";
			else {
				b1.setQuantity(b1.getQuantity() - quantity);
				cout << "Order completed\n\n";
			}
		}
		else if (title == b2.getTitle()) {
			if (quantity > b2.getQuantity())
				cout << "The quantity is not enugh.Please try again!\n\n";
			else {
				b2.setQuantity(b2.getQuantity() - quantity);
				cout << "Order completed\n\n";
			}
		}
		else if (title == b3.getTitle()) {
			if (quantity > b3.getQuantity())
				cout << "The quantity is not enugh.Please try again!\n\n";
			else {
				b3.setQuantity(b3.getQuantity() - quantity);
				cout << "Order completed\n\n";
			}
		}
		
		cin.ignore();
		
	}
	
	return 0;
}