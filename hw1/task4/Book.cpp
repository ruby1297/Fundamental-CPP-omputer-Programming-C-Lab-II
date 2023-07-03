#include<string>
using namespace std;

class Book {
private:
	string Title;
	string Author;
	int Quantity;

public:
	Book() {};
	Book(string title) :Title(title) {};
	Book(string title, string author) :Title(title), Author(author) {};
	
	string getTitle() {
		return Title;
	}
	
	void setTitle(string title) {
		Title = title;
	}

	string getAuthor() {
		return Author;
	}
	
	void setAuthor(string author) {
		Author = author;
	}

	int getQuantity() {
		return Quantity;
	}

	void setQuantity(int quantity) {
		Quantity = quantity;
	}
	
};