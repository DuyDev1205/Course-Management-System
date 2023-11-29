#include "Person.h"
#include "format"
Person::Person(string id, string name, string address, string phoneNumber)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->phoneNumber = phoneNumber;
}

string Person::toString()
{
	return "StudentID: " + this->id
		+ "\nName: " + this->name
		+ "\nAddress: " + this->address
		+ "\nPhone: " + this->phoneNumber;
}

string Person::getID()
{
	return this->id;
}

string Person::getName()
{
	return this->name;
}

string Person::getAddress()
{
	return this->address;
}

string Person::getPhoneNumber()
{
	return this->phoneNumber;
}

void Person::setID(string newID)
{
	this->id = newID;
}

void Person::setName(string newName)
{
	this->name = newName;
}

void Person::setAddress(string newAddress)
{
	this->address = newAddress;
}

void Person::setPhoneNumber(string newPhoneNumber)
{
	this->phoneNumber = newPhoneNumber;
}
