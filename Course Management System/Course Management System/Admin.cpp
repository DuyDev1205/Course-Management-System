#include "Admin.h"

void Admin::addStudent(const Student& student) {
    students.push_back(student);
}

void Admin::deleteStudent(int studentID) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getID() == studentID) {
            students.erase(it);
            break;
        }
    }
}

void Admin::displayStudents() const {
    for (const auto& student : students) {
        // Hiển thị thông tin sinh viên, có thể thay đổi tùy theo cấu trúc của class Student
        std::cout << "Student ID: " << student.getID() << ", Name: " << student.getName() << std::endl;
    }
}

Student* Admin::findStudent(int studentID) {
    for (auto& student : students) {
        if (student.getID() == studentID) {
            return &student;
        }
    }
    return nullptr;
}

void Admin::addCourse(const Course& course) {
    courses.push_back(course);
}

void Admin::deleteCourse(int courseID) {
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (it->getID() == courseID) {
            courses.erase(it);
            break;
        }
    }
}

void Admin::displayCourses() const {
    for (const auto& course : courses) {
        // Hiển thị thông tin khóa học, có thể thay đổi tùy theo cấu trúc của class Course
        std::cout << "Course ID: " << course.getID() << ", Name: " << course.getName() << std::endl;
    }
}

Course* Admin::findCourse(int courseID) {
    for (auto& course : courses) {
        if (course.getID() == courseID) {
            return &course;
        }
    }
    return nullptr;
}

void Admin::addTeacher(const Teacher& teacher) {
    teachers.push_back(teacher); 
}

void Admin::deleteTeacher(int teacherId) {
    for (auto it = teachers.begin(); it != teachers.end(); ++it) {
        if (it->getID() == teacherId) {
            teachers.erase(it);
            break;
        }
    }
}

void Admin::displayTeachers() const {
    for (const auto& teacher : teachers) {
        // Hiển thị thông tin giáo viên, có thể thay đổi tùy theo cấu trúc của class Teacher
        std::cout << "Teacher ID: " << teacher.getID() << ", Name: " << teacher.getName() << std::endl;
    }
}

Teacher* Admin::findTeacher(int teacherId) {
    for (auto& teacher : teachers) {
        if (teacher.getID() == teacherId) {
            return &teacher;
        }
    }
    return nullptr;
}
