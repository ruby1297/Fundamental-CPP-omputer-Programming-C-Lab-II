#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

class Room {
public:
    virtual double calculateRevenue(int numberOfNights) const = 0;
    virtual string getType() const = 0;
};

class DeluxeRoom : public Room {
private:
    double serviceFee;
    double extraFee;

public:
    DeluxeRoom(double serviceFee, double extraFee) : serviceFee(serviceFee), extraFee(extraFee) {}

    double calculateRevenue(int numberOfNights) const override {
        return (numberOfNights * 7500 + serviceFee) * 1.15 + extraFee;
    }

    string getType() const override {
        return "Deluxe";
    }
};

class PremiumRoom : public Room {
private:
    double serviceFee;

public:
    PremiumRoom(double serviceFee) : serviceFee(serviceFee) {}

    double calculateRevenue(int numberOfNights) const override {
        return (numberOfNights * 5000 + serviceFee) * 1.05;
    }

    string getType() const override {
        return "Premium";
    }
};

class BusinessRoom : public Room {
public:
    double calculateRevenue(int numberOfNights) const override {
        return numberOfNights * 3000;
    }

    string getType() const override {
        return "Business";
    }
};

vector<Room*> importRoomList(const string& filename) {
    vector<Room*> rooms;
    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        int d, p, b;
        inputFile >> d >> p >> b;

        for (int i = 0; i < d; i++) {
            double serviceFee, extraFee;
            inputFile >> serviceFee >> extraFee;
            rooms.push_back(new DeluxeRoom(serviceFee, extraFee));
        }

        for (int i = 0; i < p; i++) {
            double serviceFee;
            inputFile >> serviceFee;
            rooms.push_back(new PremiumRoom(serviceFee));
        }

        for (int i = 0; i < b; i++) {
            rooms.push_back(new BusinessRoom());
        }

        inputFile.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }

    return rooms;
}

void Output(const vector<Room*>& rooms, int numberOfNights, const string& outputFilename) {
    ofstream outputFile(outputFilename);

    if (outputFile.is_open()) {
        double totalRevenue = 0.0;

        for (const Room* room : rooms) {
            double revenue = room->calculateRevenue(numberOfNights);
            totalRevenue += revenue;

            outputFile << "Type " << room->getType() << ": "
                << "Revenue=" << revenue << endl;
        }

        outputFile << "Total Revenue: " << totalRevenue << endl;

        double lastMonthRevenue = totalRevenue / 1.25;
        outputFile << "Excellent Revenue: " << endl;
        for (const Room* room : rooms) {
            double revenue = room->calculateRevenue(numberOfNights);
            if (revenue >= lastMonthRevenue * 1.25) {
                outputFile << room->getType() << ": " << "Revenue=" << revenue << endl;
            }
        }

        outputFile.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

int main() {
    string roomListFile = "rooms.imp";
    string revenueOutputFile = "revenue.out";
    int numberOfNights = 30;

    vector<Room*> rooms = importRoomList(roomListFile);
    Output(rooms, numberOfNights, revenueOutputFile);

    // Clean up memory by deleting room objects
	while (!rooms.empty()) {
		delete rooms.back();
        rooms.pop_back();
	}
   

    return 0;
}
