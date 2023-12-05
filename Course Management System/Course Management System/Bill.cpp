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
        "\nCustomerName:" + customerName +
        "\nDate:" + date +
        "\nTotalAmount:" + totalAmount;
}

void Bill::addBill()
{
    string billID, customerName, date, totalAmount;

    cout << "ID:";
    cin.ignore();
    getline(cin, billID);

    cout << "CustomerName:";
    getline(cin, customerName);

    cout << "Date:";
    getline(cin, date);

    cout << "TotalAmount:";
    getline(cin, totalAmount);

	//cin.ignore();

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
				billID = line.substr(3);
			}
			else if (line.find("CustomerName:") == 0) {
				customerName = line.substr(13);
			}
			else if (line.find("Date:") == 0) {
				date = line.substr(5);
			}
			else if (line.find("TotalAmount:") == 0) {
				totalAmount = line.substr(12);
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
	cout << "List of bill in School\n";
	for (auto& bill : this->billList) {
		cout << bill.toString() << "\n\n";
	}
}

void Bill::deleteBill(const string& billIdToDelete)
{
    ifstream inputFile("Bill.txt");
    ofstream outputFile("TempFile.txt");

    if (inputFile.is_open() && outputFile.is_open()) {
        string line;

        // Đọc từng dòng và ghi vào file tạm
        while (getline(inputFile, line)) {
            if (line.find("ID:" + billIdToDelete) != string::npos) {
                while (getline(inputFile, line) && !line.empty()) {
                    // Bỏ qua dòng
                }
            }
            else {
                // Ghi dòng khác vào file tạm
                outputFile << line << endl;
            }
        }

        // Đóng file
        inputFile.close();
        outputFile.close();

        // Xóa file gốc
        remove("Bill.txt");

        // Đổi tên file tạm thành tên file gốc
        (void)rename("TempFile.txt", "Bill.txt");
        system("cls");
        getViewBillFromFile();
    }
    else {
        cerr << "Can't open input or output file." << endl;
    }
}

void Bill::getViewBillFromFile() const
{
    ifstream inputFile("Bill.txt");

    if (inputFile.is_open()) {
        string line;

        cout << "Data after delete\n";

        while (getline(inputFile, line)) {
            // Xuất từng dòng trực tiếp từ file
            cout << line << "\n";
        }

        inputFile.close();
    }
    else {
        cerr << "Can't open input file." << endl;
    }
}

Bill* Bill::searchBillID(const string& billID)
{
    for (auto& bill : billList) {
        if (bill.getBillID() == billID) {
            return &bill; // Return a pointer to the teacher if found
        }
    }
    return nullptr; // Return nullptr if not found
}

