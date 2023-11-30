#include "Assignment.h"
#include <iostream>

std::list<Assignment*> Assignment::assignmentList;

Assignment::Assignment(std::string assignID, std::string assignDesc, std::string due, int grade, Course* course)
    : assignmentID(assignID), assignmentDescription(assignDesc), deadline(due), grade(grade), relatedCourse(course) {}

void Assignment::listAllAssignments() {
    // Lặp qua danh sách bài tập và hiển thị thông tin của từng bài tập
    for (auto assignment : assignmentList) {
        assignment->viewAssignmentDetails();
    }
}

Assignment* Assignment::searchAssignment(std::string assignID) {
    // Tìm kiếm bài tập dựa trên assignmentID
    for (auto assignment : assignmentList) {
        if (assignment->assignmentID == assignID) {
            return assignment;
        }
    }
    return nullptr;
}

void Assignment::viewAssignmentDetails() {
    // Hiển thị thông tin chi tiết của bài tập
    std::cout << "Assignment ID: " << assignmentID << ", Description: " << assignmentDescription << ", Deadline: " << deadline << ", Grade: " << grade << std::endl;
}

void Assignment::addNewAssignment(std::string assignID, std::string assignDesc, std::string due, int grade, Course* course) {
    // Tạo một bài tập mới và thêm vào danh sách
    Assignment* newAssignment = new Assignment(assignID, assignDesc, due, grade, course);
    assignmentList.push_back(newAssignment);
}

void Assignment::deleteAssignment(std::string assignID) {
    // Xóa bài tập dựa trên assignmentID
    Assignment* assignmentToDelete = searchAssignment(assignID);
    if (assignmentToDelete != nullptr) {
        assignmentList.remove(assignmentToDelete);
        delete assignmentToDelete;
        std::cout << "Assignment deleted." << std::endl;
    }
    else {
        std::cout << "Assignment not found." << std::endl;
    }
}
