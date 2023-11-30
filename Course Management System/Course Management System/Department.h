#include <string>
#include <iostream>
#include <list>
#include "Course.h"

class Department {
private:
    std::string departmentID;
    std::string departmentName;
    std::string departmentDescription;
    std::list<Course*> coursesInDepartment;

    // Tạo một danh sách lưu trữ các bộ môn
    static std::list<Department*> departmentList;

public:
    Department(std::string deptID, std::string deptName, std::string deptDesc);

    static void listAllDepartments(); // Hiển thị danh sách tất cả các bộ môn
    static Department* searchDepartment(std::string deptID); // Tìm kiếm bộ môn
    void viewDepartmentDetails(); // Hiển thị chi tiết bộ môn
    static void addNewDepartment(std::string deptID, std::string deptName, std::string deptDesc); // Thêm bộ môn mới
    static void deleteDepartment(std::string deptID); // Xóa bộ môn
};
