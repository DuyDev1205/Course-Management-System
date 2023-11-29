#pragma once
#include <string>
#include<iostream>
#include<list>
using namespace std;
class Course
{
private:
	string courseID;
	string name;
	string profressor;
	int maxCapacity;
	list<Course> enrolledStudents;
	string schedule;
public:
	Course(string courseID,
		string name,
		string profressor,
		int maxCapacity,
		string schedule);
	void viewCourseDetails();
	void enrollStudent(int studentID);
	void withdrawStudent(int studentID);
	void listEnrolledStudents();
	void viewSchedule();
	string toString();
};

