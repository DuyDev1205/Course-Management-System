#include <iostream>
#include <string>
#include <Windows.h>

#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Bill.h"
#include "Assignment.h"
#include "Management.h"
using namespace std;
void Menu(int& choice)
{
    cout << "======= Menu =======\n";
    cout << "1. Student\n";
    cout << "2. Teacher\n";
    cout << "3. Course\n";
    cout << "4. Receiption\n";
    cout << "5. Assignment\n";
    cout << "6. Management\n";
    cout << "0. Exit\n";
    cout << "====================\n";
    cout << "Choose function: ";
    cin >> choice;
}
void MenuFunction(int& choicef,string role)
{
    if (role == "Student")
    {
        cout << "======= Menu =======\n";
        cout << "1. ViewAll\n";
        cout << "2. Search\n";
        cout << "0. Exit\n";
        cout << "====================\n";
        cout << "Choose function: ";
        cin >> choicef;
    }
    else if (role == "Teacher")
    {
        cout << "======= Menu =======\n";
        cout << "1. ViewAll\n";
        cout << "2. Search\n";
        cout << "0. Exit\n";
        cout << "====================\n";
        cout << "Choose function: ";
        cin >> choicef;
    }
    else if (role == "Course")
    {
        cout << "======= Menu =======\n";
        cout << "1. Add\n";
        cout << "2. Delete by CourseID\n";
        cout << "3. ViewAll\n";
        cout << "4. Search\n";
        cout << "0. Exit\n";
        cout << "====================\n";
        cout << "Choose function: ";
        cin >> choicef;
    }
    else if (role == "Bill")
    {
        cout << "======= Menu =======\n";
        cout << "1. Add\n";
        cout << "2. Delete by BillID\n";
        cout << "3. ViewAll\n";
        cout << "4. Search\n";
        cout << "0. Exit\n";
        cout << "====================\n";
        cout << "Choose function: ";
        cin >> choicef;
    }
    else if (role == "Assignment")
    {
        cout << "======= Menu =======\n";
        cout << "1. Add Assignment for Student\n";
        cout << "2. Delete Assignment by TaskID\n";
        cout << "3. ViewAll\n";
        cout << "4. Search\n";
        cout << "0. Exit\n";
        cout << "====================\n";
        cout << "Choose function: ";
        cin >> choicef;
    }
    else if (role =="Management")
    {
        cout << "======= Menu =======\n";
        cout << "1. Add Student\n";
        cout << "2. Delete by StudentID\n";
        cout << "3. View Student List\n";
        cout << "4. Add Teacher\n";
        cout << "5. Delete by TeacherID\n";
        cout << "6. View Teacher List\n";
        cout << "0. Exit\n";
        cout << "====================\n";
        cout << "Choose function: ";
        cin >> choicef;
    }
}
int main()
{
    system("cls");
    system("color 02");
    Person p;
    Student st;
    Teacher teach;
    Course course;
    Bill bill;
    Assignment assign;
    Management mg;
    int choice, choicef,selection;
    string studentId,teacherId,courseId,billId,taskId;
    Menu(choice);
    switch (choice)
    {
        case 1:
                do
                {
                system("cls");
                st.readFile("Student.txt");
                MenuFunction(choicef, "Student");
                switch (choicef)
                {
                case 1:
                    system("cls");
                    st.clearStudentList(); 
                    st.readFile("Student.txt");
                    st.getViewStudent();
                    break;
                case 2:
                    system("cls");
                    st.clearStudentList(); 
                    st.readFile("Student.txt");
                    st.getViewStudent();
                    cout << "Type StudentID you want to search: ";
                    cin >> studentId;
                    st.searchStudentId(studentId);

                    Student* foundStudent = st.searchStudentId(studentId);
                    system("cls");
                    if (foundStudent != nullptr) {
                        cout << "Student has been found:\n";
                        cout << foundStudent->toString() << "\n";
                    }
                    else {
                        cout << "No student found with StudentId as " << studentId << "\n";
                    }
                    break;
                }
                cout << "Select the option:"<<endl;
                cout << "1.Continue"<<endl<<"2.Quit"<<endl;
                cin >> selection;
            } while (selection == 1);
            break;
        case 2:
            do {
                system("cls");
                MenuFunction(choicef, "Teacher");
                switch (choicef)
                {
                case 1:
                    system("cls");
                    teach.clearTeacherList();
                    teach.readFile("Teacher.txt");
                    teach.getViewTeacher();
                    break;
                case 2:
                    system("cls");
                    teach.clearTeacherList();
                    teach.readFile("Teacher.txt");
                    teach.getViewTeacher();
                    cout << "Type TeacherID you want to search: ";
                    cin >> teacherId;
                    /*teach.searchTeacherID(teacherId);*/

                    Teacher* foundTeacher = teach.searchTeacherID(teacherId);
                    system("cls");
                    if (foundTeacher != nullptr) {
                        cout << "Teacher has been found:\n";
                        cout << foundTeacher->toString() << "\n"; 
                    }
                    else {
                        cout << "No teacher found with TeacherId as " << teacherId << "\n";
                    }
                    break;
                }
                cout << "Select the option:" << endl;
                cout << "1.Continue" << endl << "2.Quit" << endl;
                cin >> selection;
            }
            while (selection == 1);
            break;
        case 3:
        {
            do
            {
                system("cls");
                MenuFunction(choicef, "Course");         
                switch (choicef)
                {
                    case 1:
                        course.addCourse();
                        system("cls");
                        course.courseClearList();
                        course.readFile("Course.txt");
                        course.getViewCourse();
                        break;
                    case 2:
                        system("cls");
                        course.courseClearList();
                        course.readFile("Course.txt");
                        course.getViewCourse();
                        cout << "Type CourseID you want to delete: ";
                        cin >> courseId;
                        course.deleteCourse(courseId);
                        break;
                    case 3:
                        system("cls");
                        course.courseClearList();
                        course.readFile("Course.txt");
                        course.getViewCourse();
                    case 4:system("cls");
                        course.courseClearList();
                        course.readFile("Course.txt");
                        course.getViewCourse();
                        cout << "Type CourseID you want to search: ";
                        cin >> courseId;
                        Course* foundCourseID = course.searchCourseId(courseId);
                        system("cls");
                        if (foundCourseID != nullptr) {
                            cout << "Course has been found:\n";
                            cout << foundCourseID->toString() << "\n";
                        }
                        else {
                            cout << "No Course found with CourseId as " << courseId << "\n";
                        }
                        break;
                }
                cout << "Select the option:" << endl;
                cout << "1.Continue" << endl << "2.Quit" << endl;
                cin >> selection;
            }
            while (selection == 1);
            break;
        case 4:
        {
            do
            {
                system("cls");
                MenuFunction(choicef, "Bill");
                switch (choicef)
                {
                case 1:
                    bill.addBill();
                    system("cls");
                    bill.billClearList();
                    bill.readFile("Bill.txt");
                    bill.getViewBill();
                    break;
                case 2:
                    system("cls");
                    bill.billClearList();
                    bill.readFile("Bill.txt");
                    bill.getViewBill();
                    cout << "Type BillID you want to delete: ";
                    cin >> billId; 
                    bill.deleteBill(billId);
                    break;
                case 3:
                    system("cls");
                    bill.billClearList();
                    bill.readFile("Bill.txt");
                    bill.getViewBill();
                    break;
                case 4:
                    system("cls");
                    bill.billClearList();
                    bill.readFile("Bill.txt");
                    bill.getViewBill();
                    cout << "Type BillID you want to search: ";
                    cin >> billId;
                    Bill* foundBillID = bill.searchBillID(billId);
                    system("cls");
                    if (foundBillID != nullptr)
                    {
                        cout << "Bill has been found:\n";
                        cout << foundBillID->toString() << "\n";
                    }
                    else
                    {
                        cout << "No Bill found with BillID as " << billId << "\n";
                    }
                    break;
                }

                cout << "Select the option:" << endl;
                cout << "1.Continue" << endl << "2.Quit" << endl;
                cin >> selection;
            } while (selection == 1);

            break;
        }
        case 5:
        {
            do
            {
                system("cls");
                MenuFunction(choicef, "Assignment");
                switch (choicef)
                {
                case 1:
                    system("cls");
                    assign.inputAssignment(assign);
                    assign.assignmentClearList();
                    assign.readFile("Assignment.txt");
                    assign.getViewAssignment();
                    break;
                case 2:
                    system("cls");
                    assign.assignmentClearList();
                    assign.readFile("Assignment.txt");
                    assign.getViewAssignment();
                    cout << "Type the Task Id to delete ";
                    cin >> taskId;
                    assign.removeAssignment(taskId);
                    break;
                case 3:
                    system("cls");
                    assign.assignmentClearList();
                    assign.readFile("Assignment.txt");
                    assign.getViewAssignment();
                    break;
                case 4:
                    system("cls");
                    assign.assignmentClearList();
                    assign.readFile("Assignment.txt");
                    assign.getViewAssignment();
                    cout << "Type the task ID you want to search ";
                    cin >> taskId;
                    Assignment* foundTaskID = assign.searchAssignment(taskId);
                    system("cls");
                    if (foundTaskID != nullptr)
                    {
                        cout << "Assignment has been found:\n";
                        cout << foundTaskID->toString() << "\n";
                    }
                    else
                    {
                        cout << "No Assignment found with BillID as " << taskId << "\n";
                    }
                    break;
                }
                cout << "Select the option:" << endl;
                cout << "1.Continue" << endl << "2.Quit" << endl;
                cin >> selection;
            } while (selection == 1);
        }
        case 6:
            do 
            {
                system("cls");
                MenuFunction(choicef, "Management");
                switch (choicef)
                {
                case 1:
                    system("cls");
                    mg.addStudent();
                    mg.clearList();
                    mg.readFileStudent("Student.txt");
                    mg.getViewFromFile("Student.txt");
                    break;
                case 2:
                    system("cls");
                    mg.clearList();
                    mg.readFileStudent("Student.txt");
                    mg.getViewFromFile("Student.txt");
                    cout << "Type StudentID you want to delete: ";
                    cin >> studentId;
                    mg.deleteStudent(studentId);
                case 3:
                    system("cls");
                    mg.clearList();
                    mg.readFileStudent("Student.txt");
                    mg.getViewFromFile("Student.txt");
                    break;
                case 4:
                    system("cls");
                    mg.addTeacher();
                    mg.clearList();
                    mg.readFileTeacher("Teacher.txt");
                    mg.getViewFromFile("Teacher.txt");
                    break;
                case 5:
                    system("cls");
                    mg.clearList();
                    mg.readFileTeacher("Teacher.txt");
                    mg.getViewFromFile("Teacher.txt");
                    cout << "Type TeacherID you want to delete: ";
                    cin >> teacherId;
                    mg.deleteTeacher(teacherId);
                    break;
                case 6:
                    system("cls");
                    mg.clearList();
                    mg.readFileStudent("Teacher.txt");
                    mg.getViewFromFile("Teacher.txt");
                    break;
                }
                cout << "Select the option:" << endl;
                cout << "1.Continue" << endl << "2.Quit" << endl;
                cin >> selection;
            } while (selection == 1);
        }
    }
    return 0;
}