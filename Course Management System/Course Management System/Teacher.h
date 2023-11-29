#pragma once
#include "Person.h"
#include<fstream>
#include<list>
class Teacher :
    public Person
{
private:
    string department;
    double salary;
    string teacherId;
    list<Teacher> teacherList;
public:
    Teacher(string department, double salary,Person p);
    Teacher() = default;
    string getDepartment();
    double getSalary();
    string getTeacherId();
    string toString();
    bool writeFile(Teacher teach);
    void addTeacher();
    void getViewTeacher();
    void clearTeacherList();
    void readFile(const string& fileName);
    void deleteTeacher(const string& teacherIdToDelete);
    void getViewTeacherFromFile();
    Teacher* searchTeacherID(const string& teacherId);
};

