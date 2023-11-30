#include "Enrollment.h"
#include <iostream>

std::list<Enrollment*> Enrollment::enrollmentList;

Enrollment::Enrollment(std::string studentID, std::string courseID, std::string regDate, std::string regStatus)
    : studentID(studentID), courseID(courseID), registrationDate(regDate), registrationStatus(regStatus) {}

void Enrollment::listAllEnrollments() {
    // Lặp qua danh sách đăng ký và hiển thị thông tin của từng đăng ký
    for (auto enrollment : enrollmentList) {
        enrollment->viewEnrollmentDetails();
    }
}

Enrollment* Enrollment::searchEnrollment(std::string studentID, std::string courseID) {
    // Tìm kiếm đăng ký dựa trên studentID và courseID
    for (auto enrollment : enrollmentList) {
        if (enrollment->studentID == studentID && enrollment->courseID == courseID) {
            return enrollment;
        }
    }
    return nullptr;
}

void Enrollment::viewEnrollmentDetails() {
    // Hiển thị thông tin chi tiết của đăng ký
    std::cout << "Student ID: " << studentID << ", Course ID: " << courseID << ", Registration Date: " << registrationDate << ", Status: " << registrationStatus << std::endl;
}

void Enrollment::addNewEnrollment(std::string studentID, std::string courseID, std::string regDate, std::string regStatus) {
    // Tạo một đăng ký mới và thêm vào danh sách
    Enrollment* newEnrollment = new Enrollment(studentID, courseID, regDate, regStatus);
    enrollmentList.push_back(newEnrollment);
}

void Enrollment::deleteEnrollment(std::string studentID, std::string courseID) {
    // Xóa đăng ký dựa trên studentID và courseID
    Enrollment* enrollmentToDelete = searchEnrollment(studentID, courseID);
    if (enrollmentToDelete != nullptr) {
        enrollmentList.remove(enrollmentToDelete);
        delete enrollmentToDelete;
        std::cout << "Enrollment deleted." << std::endl;
    }
    else {
        std::cout << "Enrollment not found." << std::endl;
    }
}
