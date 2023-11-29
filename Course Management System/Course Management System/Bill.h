#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Bill
{
private:
    string billID;
    string customerName;
    string date;
    string totalAmount;
    list<Bill> billList;

public:
    Bill(string billID, string customerName, string date, string totalAmount);
    Bill() = default;
    string getBillID() const;
    string toString() const;
    void addBill();
    void readFile(const string& fileName);
    bool writeToFile(Bill bill);
    void billClearList();
    void getViewBill() const;
    void deleteBill(const string& billIdToDelete);
    void getViewBillFromFile() const;
    Bill* searchBillID(const string& billID);
};