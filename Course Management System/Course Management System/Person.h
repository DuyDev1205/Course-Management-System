#pragma once
#include <string>
#include<iostream>
using namespace std;

class Person
{
private:
	string id;
	string name;
	string address;
	string phoneNumber;

public:
	Person(string Id,
		string name,
		string address,
		string phoneNumber);
	Person() = default;
	string toString();
	string getID();
	string getName();
	string getAddress();
	string getPhoneNumber();
	void setID(string newID);
	void setName(string newName);
	void setAddress(string newAddress);
	void setPhoneNumber(string newPhoneNumber);
};



