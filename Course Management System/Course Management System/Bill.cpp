#include "Bill.h"
#include <iostream>

Bill::Bill(string billID, string customerName, string date, string totalAmount)
{
    this->billID = billID;
    this->customerName = customerName;
    this->date = date;
    this->totalAmount = totalAmount;

}

string Bill::getBillID() const
{
    return billID;
}

string Bill::toString() const
{
    return "ID:" + billID +
        "\nName:" + customerName +
        "\nDate:" + date +
        "\nTotalAmount:" + totalAmount;
}

void Bill::addBill()
{
    string billID, customerName, date, totalAmount;

    cout << "ID:";
    cin.ignore();
    getline(cin, billID);

    cout << "Name:";
    getline(cin, customerName);

    cout << "Date:";
    getline(cin, date);

    cout << "TotalAmount:";
    getline(cin, totalAmount);

	cin.ignore();

    Bill newBill(billID, customerName, date, totalAmount);
    billList.push_back(newBill);
    writeToFile(newBill);
}

void Bill::readFile(const string& fileName)
{
	ifstream inputFile(fileName);

	if (inputFile.is_open()) {
		string line;
		string billID, customerName, date, totalAmount;

		while (getline(inputFile, line)) {
			if (line.find("ID:") == 0) {
				billID = line.substr(4);
			}
			else if (line.find("Name:") == 0) {
				customerName = line.substr(6);
			}
			else if (line.find("Date:") == 0) {
				date = line.substr(6);
			}
			else if (line.find("TotalAmount:") == 0) {
				totalAmount = line.substr(13);
				Bill newBill(billID, customerName, date, totalAmount);
				billList.push_back(newBill);
			}
		}

		inputFile.close();
	}
	else {
		cout << "Can't read file!" << endl;
	}
}

bool Bill::writeToFile(Bill bill)
{
	this->billList.push_back(bill);
	ofstream fileOut("Bill.txt", ios::app);
	//fileOut << endl;
	if (fileOut.is_open()) {
		fileOut << bill.toString() << endl;
	}
	else {
		cerr << "Can not open file and write." << endl;
	}
	fileOut << endl;
	fileOut.close();
	return true;
}

void Bill::billClearList()
{
	billList.clear();
}

void Bill::getViewBill() const
{
	cout << "List of students in School\n";
	for (auto& bill : this->billList) {
		cout << bill.toString() << "\n\n";
	}
}

