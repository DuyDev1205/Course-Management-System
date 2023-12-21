#pragma once
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include <list>
#include<fstream>

using namespace std;
class Management:public Person
{
private:
	list<Student> studentList;
	list<Teacher> teacherList;
	list<Course> CourseList;
public:
	void addStudent();
	bool writeFileStudent(Student stu);
	void deleteStudent(const string& studentIdToDelete);
	void clearList();
	void readFileStudent(const string& fileName);
	void getViewFromFile(string fileName);
	void addTeacher();
	bool writeFileTeacher(Teacher teach);
	void readFileTeacher(const string& fileName);
	void deleteTeacher(const string& teacherIdToDelete);
};

