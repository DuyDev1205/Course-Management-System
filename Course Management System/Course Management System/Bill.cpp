#include "Bill.h"
#include <iostream>

void Bill::displayBill() const {
    std::cout << "Courses in Bill:" << std::endl;
    for (const auto& course : billCourses) {
        std::cout << "Course ID: " << course.getID() << ", Name: " << course.getName() << std::endl;
    }
}

void Bill::addCourse(const Course& course) {
    billCourses.push_back(course);
}

void Bill::removeCourse(int courseID) {
    for (auto it = billCourses.begin(); it != billCourses.end(); ++it) {
        if (it->getID() == courseID) {
            billCourses.erase(it);
            break;
        }
    }
}

Course* Bill::findCourse(int courseID) {
    for (auto& course : billCourses) {
        if (course.getID() == courseID) {
            return &course; 
        }
    }
    return nullptr;
}

float Bill::calculateSubtotal() const {
    return calculateTotal();
}

float Bill::calculateFinalTotal(const Student& student) const {
    float scholarshipAmount = student.getScholarshipAmount(); // Lấy học bổng từ đối tượng Student
    float total = calculateTotal();
    return total - scholarshipAmount;
}

float Bill::calculateTotal() const {
    float total = 0.0f;
    for (const auto& course : billCourses) {
        total += course.getPrice();
    }
    return total;
}
