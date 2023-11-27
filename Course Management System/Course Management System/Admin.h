#pragma once
#include <string>
#include <iostream>
#include <list>
#include "Student.h"
#include "Course.h"
#include "Teacher.h"

class Admin {
private:
    std::list<Student> students;
    std::list<Course> courses;
    std::list<Teacher> teachers;

public:
    void addStudent(const Student& student);
    void deleteStudent(int studentID);
    void displayStudents() const;
    Student* findStudent(int studentID);

    void addCourse(const Course& course);
    void deleteCourse(int courseID);
    void displayCourses() const;
    Course* findCourse(int courseID);

    void addTeacher(const Teacher& teacher);
    void deleteTeacher(int teacherId);
    void displayTeachers() const;
    Teacher* findTeacher(int teacherId); 
};