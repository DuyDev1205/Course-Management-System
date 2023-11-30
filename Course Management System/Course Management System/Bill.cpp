#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Bill.h" // Header file for the Bill class

using namespace std;

// Implementation of the Bill class
class Bill {
private:
    string billID;
    string customerName;
    string date;
    string totalAmount;
    vector<Bill> billList;

public:
    Bill() {} // Default constructor

    // Parameterized constructor
    Bill(string billID, string customerName, string date, string totalAmount)
        : billID(billID), customerName(customerName), date(date), totalAmount(totalAmount) {}

    // Getters for accessing private member variables
    string getBillID() const { return billID; }
    string getCustomerName() const { return customerName; }
    string getDate() const { return date; }
    string getTotalAmount() const { return totalAmount; }

    // Convert bill details to string format
    string toString() const {
        ostringstream oss;
        oss << "Bill ID: " << billID << "\n"
            << "Customer Name: " << customerName << "\n"
            << "Date: " << date << "\n"
            << "Total Amount: " << totalAmount;
        return oss.str();
    }

    // Add a new bill to the system
    void addBill() {
        string newBillID, newCustomerName, newDate, newTotalAmount;

        cout << "Enter Bill ID: ";
        cin.ignore();
        getline(cin, newBillID);

        cout << "Enter Customer Name: ";
        getline(cin, newCustomerName);

        cout << "Enter Date: ";
        getline(cin, newDate);

        cout << "Enter Total Amount: ";
        getline(cin, newTotalAmount);

        Bill newBill(newBillID, newCustomerName, newDate, newTotalAmount);
        billList.push_back(newBill);
        writeToFile(newBill);
    }

    // Write bill details to a file
    bool writeToFile(const Bill& bill) {
        billList.push_back(bill);
        ofstream fileOut("Bill.txt", ios::app);
        if (fileOut.is_open()) {
            fileOut << bill.toString() << endl;
            fileOut.close();
            return true;
        }
        else {
            cerr << "Unable to open file and write." << endl;
            return false;
        }
    }

    // Clear the bill list
    void clearBillList() {
        billList.clear();
    }

    // Read bill details from a file
    void readFile(const string& fileName) {
        ifstream inputFile(fileName);

        if (inputFile.is_open()) {
            string line;
            string billID, customerName, date, totalAmount;

            while (getline(inputFile, line)) {
                if (line.find("Bill ID:") == 0) {
                    billID = line.substr(9);
                }
                else if (line.find("Customer Name:") == 0) {
                    customerName = line.substr(14);
                }
                else if (line.find("Date:") == 0) {
                    date = line.substr(6);
                }
                else if (line.find("Total Amount:") == 0) {
                    totalAmount = line.substr(13);
                    Bill newBill(billID, customerName, date, totalAmount);
                    billList.push_back(newBill);
                }
            }
            inputFile.close();
        }
        else {
            cout << "Unable to read file!" << endl;
        }
    }

    // Display all bills
    void getViewBill() const {
        cout << "List of bills:\n";
        for (const auto& bill : billList) {
            cout << bill.toString() << "\n\n";
        }
    }

    // Delete a bill by Bill ID
    void deleteBill(const string& billIDToDelete) {
        ifstream inputFile("Bill.txt");
        ofstream outputFile("TempFile.txt");

        if (inputFile.is_open() && outputFile.is_open()) {
            string line;

            while (getline(inputFile, line)) {
                if (line.find("Bill ID: " + billIDToDelete) != string::npos) {
                    while (getline(inputFile, line) && !line.empty()) {
                        // Skip the lines associated with the bill to be deleted
                    }
                }
                else {
                    outputFile << line << endl;
                }
            }
            inputFile.close();
            outputFile.close();

            remove("Bill.txt");
            rename("TempFile.txt", "Bill.txt");
            getViewBillFromFile(); // Refresh the bill list after deletion
        }
        else {
            cerr << "Unable to open input or output file." << endl;
        }
    }

    // Display bills from file
    void getViewBillFromFile() {
        ifstream inputFile("Bill.txt");

        if (inputFile.is_open()) {
            string line;

            cout << "Data after deletion:\n";

            while (getline(inputFile, line)) {
                cout << line << "\n";
            }
            inputFile.close();
        }
        else {
            cerr << "Unable to open input file." << endl;
        }
    }

    // Search for a bill by Bill ID
    Bill* searchBillID(const string& billID) {
        for (auto& bill : billList) {
            if (bill.getBillID() == billID) {
                return &bill;
            }
        }
        return nullptr;
    }
};
