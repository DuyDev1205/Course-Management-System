#pragma once
#include <vector>
#include "Course.h"
#include "Student.h" 

class Bill {
private:
    std::vector<Course> billCourses;
    float calculateTotal() const;

public:
    void displayBill() const;
    void addCourse(const Course& course);
    void removeCourse(int courseID);
    Course* findCourse(int courseID);
    float calculateSubtotal() const;
    float calculateFinalTotal(const Student& student) const;  
};
