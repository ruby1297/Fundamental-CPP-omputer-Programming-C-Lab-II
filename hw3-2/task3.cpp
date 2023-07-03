#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Base class for customers
class Customer {
protected:
    string type;
    int quantity;
    double unitPrice;

public:
    Customer(string type, int quantity, double unitPrice)
        : type(type), quantity(quantity), unitPrice(unitPrice) {}

    virtual double calculatePayment() const = 0;

    string getType() const {
        return type;
    }

    int getQuantity() const {
        return quantity;
    }

    double getUnitPrice() const {
        return unitPrice;
    }
};

// Ordinary customer class
class OrdinaryCustomer : public Customer {
public:
    OrdinaryCustomer(int quantity, double unitPrice)
        : Customer("Type A (Ordinary)", quantity, unitPrice) {}

    double calculatePayment() const override {
        double vat = quantity * unitPrice * 0.1;
        return quantity * unitPrice + vat;
    }
};

// Loyal customer class
class LoyalCustomer : public Customer {
private:
    int yearsOfLoyalty;

public:
    LoyalCustomer(int quantity, double unitPrice, int yearsOfLoyalty)
        : Customer("Type B (Loyal)", quantity, unitPrice), yearsOfLoyalty(yearsOfLoyalty) {}

    double calculatePayment() const override {
        double promotionPercentage = max(yearsOfLoyalty * 0.05, 0.5);
        double discountedPrice = (quantity * unitPrice) * (1.0 - promotionPercentage);
        double vat = discountedPrice * 0.1;
        return discountedPrice + vat;
    }
};

// Special customer class
class SpecialCustomer : public Customer {
public:
    SpecialCustomer(int quantity, double unitPrice)
        : Customer("Type C (Special)", quantity, unitPrice) {}

    double calculatePayment() const override {
        double discountedPrice = (quantity * unitPrice) * 0.5;
        double vat = discountedPrice * 0.1;
        return discountedPrice + vat;
    }
};

// Function to read customer data from file
vector<Customer*> readCustomerData(const string& filename) {
    vector<Customer*> customers;
    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        string type;
        int quantity;
        double unitPrice;

        while (inputFile >> type >> quantity >> unitPrice) {
            if (type == "A") {
                customers.push_back(new OrdinaryCustomer(quantity, unitPrice));
            }
            else if (type == "B") {
                int yearsOfLoyalty;
                inputFile >> yearsOfLoyalty;
                customers.push_back(new LoyalCustomer(quantity, unitPrice, yearsOfLoyalty));
            }
            else if (type == "C") {
                customers.push_back(new SpecialCustomer(quantity, unitPrice));
            }
        }

        inputFile.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }

    return customers;
}

// Function to calculate total payment and export results to file
void Output(const vector<Customer*>& customers, const string& outputFilename) {
    
    ofstream outputFile(outputFilename);

    if (outputFile.is_open()) {
        double totalPayment = 0.0;

        // Calculate payment for each customer and export results to file
        for (const Customer* customer : customers) {
            double payment = customer->calculatePayment();
            totalPayment += payment;

            outputFile << fixed << setprecision(2);
            outputFile << customer->getType() << ": "
                << "Quantity=" << customer->getQuantity() << ", "
                << "Unit Price=" << customer->getUnitPrice() << ", "
                << "Payment=" << payment << endl;
        }

        outputFile << "Total Payment: " << totalPayment << endl;

        outputFile.close();
    }
    else {
        cout << "Unable to create file " << endl;
    }
}

int main() {

    //test function main.cpp
    string inputFilename = "customer.imp";
    string outputFilename = "payment.out";
    
	ifstream inputFile(inputFilename);
	ofstream outputFile(outputFilename);

        int x, y, z;
        inputFile >> x >> y >> z;
        outputFile << x << y << z;


    vector<Customer*> customers = readCustomerData(inputFilename);
    Output(customers, outputFilename);

    // Clean up memory by deleting customer objects
    while (!customers.empty()) {
        delete customers.back();
        customers.pop_back();
    }


    return 0;
}
