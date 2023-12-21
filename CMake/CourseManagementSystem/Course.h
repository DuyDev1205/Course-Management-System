#pragma once
#include <string>
#include"Student.h"
#include<iostream>
#include<list>
using namespace std;
class Course
{
private:
	string courseID;
	string name;
	string professor;
	string maxCapacity;
	list<Student*> enrolledStudents;
	list<Course> courseList;
	string schedule;
public:
	Course(string courseID,
		string name,
		string profressor,
		string maxCapacity,
		string schedule);
	Course() = default;
	void viewCourseDetails();
	void addCourse();
	void enrollStudent(Student* studentID);
	string toString();
	bool writeToFile(Course course);
	void courseClearList();
	void readFile(const string& fileName);
	void getViewCourse();
	void deleteCourse(const string& CourseIdToDelete);
	void getViewCourseFromFile();
	Course* searchCourseId(const string& CourseID);
	string getCourseID();
};

