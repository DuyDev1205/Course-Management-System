#pragma once
#include "Person.h"
#include <list>
#include<fstream>
class Student :
	public Person
{
private:
	string majors;
	string grades;
	list<Student> studentList;
public:
	Student(string majors, string grades, Person p);
	Student() = default;
	string toString();
	void readFile(const string& fileName);
	bool writeFile(Student stu);
	void getViewStudent();
	void addStudent(Student stu);
	void deleteStudent(const string& studentIdToDelete);
	void getViewStudentFromFile();
	Student* searchStudentId(const string& studentId);
	void clearStudentList();
	friend class Assignment;
};	

