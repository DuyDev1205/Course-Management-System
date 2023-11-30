#include "Department.h"
#include <iostream>

std::list<Department*> Department::departmentList;

Department::Department(std::string deptID, std::string deptName, std::string deptDesc)
    : departmentID(deptID), departmentName(deptName), departmentDescription(deptDesc) {}

void Department::listAllDepartments() {
    // Lặp qua danh sách các bộ môn và hiển thị thông tin của từng bộ môn
    for (auto dept : departmentList) {
        dept->viewDepartmentDetails();
    }
}

Department* Department::searchDepartment(std::string deptID) {
    // Tìm kiếm bộ môn dựa trên departmentID
    for (auto dept : departmentList) {
        if (dept->departmentID == deptID) {
            return dept;
        }
    }
    return nullptr;
}

void Department::viewDepartmentDetails() {
    // Hiển thị thông tin chi tiết của bộ môn
    std::cout << "Department ID: " << departmentID << ", Name: " << departmentName << ", Description: " << departmentDescription << std::endl;
}

void Department::addNewDepartment(std::string deptID, std::string deptName, std::string deptDesc) {
    // Tạo một bộ môn mới và thêm vào danh sách
    Department* newDepartment = new Department(deptID, deptName, deptDesc);
    departmentList.push_back(newDepartment);
}

void Department::deleteDepartment(std::string deptID) {
    // Xóa bộ môn dựa trên departmentID
    Department* deptToDelete = searchDepartment(deptID);
    if (deptToDelete != nullptr) {
        departmentList.remove(deptToDelete);
        delete deptToDelete;
        std::cout << "Department deleted." << std::endl;
    }
    else {
        std::cout << "Department not found." << std::endl;
    }
}
