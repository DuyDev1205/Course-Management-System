#include <string>
#include <iostream>
#include "Course.h"

class Assignment {
private:
    std::string assignmentID;
    std::string assignmentDescription;
    std::string deadline;
    int grade;
    Course* relatedCourse;

    // Tạo một danh sách lưu trữ các bài tập
    static std::list<Assignment*> assignmentList;

public:
    Assignment(std::string assignID, std::string assignDesc, std::string due, int grade, Course* course);

    static void listAllAssignments(); // Hiển thị danh sách tất cả các bài tập
    static Assignment* searchAssignment(std::string assignID); // Tìm kiếm bài tập
    void viewAssignmentDetails(); // Hiển thị chi tiết bài tập
    static void addNewAssignment(std::string assignID, std::string assignDesc, std::string due, int grade, Course* course); // Thêm bài tập mới
    static void deleteAssignment(std::string assignID); // Xóa bài tập
};
