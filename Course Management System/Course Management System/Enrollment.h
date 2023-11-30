#include <string>
#include <iostream>
#include <list>
#include "Student.h"
#include "Course.h"

class Enrollment {
private:
    std::string studentID;
    std::string courseID;
    std::string registrationDate;
    std::string registrationStatus;

    // Tạo một danh sách lưu trữ đăng ký
    static std::list<Enrollment*> enrollmentList;

public:
    Enrollment(std::string studentID, std::string courseID, std::string regDate, std::string regStatus);

    static void listAllEnrollments(); // Hiển thị danh sách tất cả các đăng ký
    static Enrollment* searchEnrollment(std::string studentID, std::string courseID); // Tìm kiếm đăng ký
    void viewEnrollmentDetails(); // Hiển thị chi tiết đăng ký
    static void addNewEnrollment(std::string studentID, std::string courseID, std::string regDate, std::string regStatus); // Thêm đăng ký mới
    static void deleteEnrollment(std::string studentID, std::string courseID); // Xóa đăng ký
};
