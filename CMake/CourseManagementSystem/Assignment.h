#pragma once
#include "Person.h"
#include <list>
#include<fstream>
#include <iostream>
#include "Student.h"  
#include "Course.h"   
#include "Teacher.h"
#include "Person.h"
#include <sstream>
using namespace std;
class Assignment
{
private:
    string taskId;
    string description;
    string courseId;
    string studentId;
    string teacherId;
    list<Assignment> listAssign;
public:
    Assignment(string taskId, const string& description, string courseId, string studentId, string teacherId);
    Assignment() = default;

    string getTaskId() const;
    string getDescription() const;
    string getCourseId() const;
    string getStudentId() const;
    string getTeacherId() const;
    void inputAssignment(Assignment& assignment);
    void addAssignment(const Assignment& assignment);
    void removeAssignment(string taskId);
    void viewAllAssignments() const;
    Assignment* searchAssignment(const string& taskId);
    bool isStudentValid(string studentID);
    bool writeFile(Assignment assignment);
    string toString();
    void readFile(const string& fileName);
    void getViewAssignment();
    void assignmentClearList();
    void getViewAssignmentFromFile();
};
