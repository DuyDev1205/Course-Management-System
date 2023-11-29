#include "Student.h"
#include <iostream>
#include <algorithm>
using namespace std;
Student::Student(string majors, string grades, Person p)
    :Person(p.getID(), p.getName(), p.getAddress(), p.getPhoneNumber())

{
    this->majors = majors;
    this->grades = grades;
}
string Student::toString()
{
    return Person::toString()
        + "\nMajors: " + this->majors
        + "\nGrades: " + this->grades;
}


void Student::readFile(const string& fileName)
{
    ifstream inputFile(fileName);

    if (inputFile.is_open()) {
        string line;
        string studentID, name, address, phone, majors, grades;

        while (getline(inputFile, line)) {
            if (line.find("StudentID:") == 0) {
                studentID = line.substr(11);
            }
            else if (line.find("Name:") == 0) {
                name = line.substr(6);
            }
            else if (line.find("Address:") == 0) {
                address = line.substr(9);
            }
            else if (line.find("Phone:") == 0) {
                phone = line.substr(7);
            }
            else if (line.find("Majors:") == 0) {
                majors = line.substr(8);
            }
            else if (line.find("Grades:") == 0) {
                grades = line.substr(8);
                studentList.push_back(Student(majors, grades, Person(studentID, name, address, phone)));
            }
        }

        inputFile.close();
        getViewStudent();
    }
    else {
        cout << "Can't read file!" << endl;
    }
}

bool Student::writeFile(Student stu)
{
    this->studentList.push_back(stu);
    ofstream fileOut("Student.txt", ios::app);
    //fileOut << endl;
    if (fileOut.is_open()) {
        fileOut << stu.toString() << endl;
    }
    else {
        cerr << "Can not open file and write." << endl;
    }
    fileOut << endl;
    fileOut.close();
    return true;
}

void Student::getViewStudent()
{
    cout << "List of students in School";
    for (auto& stu : this->studentList) {
        cout << stu.toString()<<"\n\n";
    }
}

void Student::addStudent(Student stu)
{
    cout << "Please! Fill down infomation of author that you want to add in system.\n\n";
    string studentID, name, address, phone, majors, grades;

    cout << "Student ID:";
    cin.ignore();
    getline(cin, studentID);

    cout << "Name:";
    getline(cin, name);

    cout << "Address:";
    getline(cin, address);

    cout << "PhoneNumber:";
    getline(cin, phone);

    cout << "Majors:";
    getline(cin, majors);

    cout << "Grades:";
    getline(cin, grades);
    Student newStudent(majors, grades, Person(studentID, name, address, phone));
    writeFile(newStudent);
}


void Student::deleteStudent(const string& studentIDToDelete)
{
    ifstream inputFile("Student.txt");
    ofstream outputFile("TempFile.txt");

    if (inputFile.is_open() && outputFile.is_open()) {
        string line;

        // Đọc từng dòng và ghi vào file tạm
        while (getline(inputFile, line)) {
            if (line.find("StudentID: " + studentIDToDelete) != string::npos) {
                // Bỏ qua và không ghi dòng chứa StudentID cần xóa
                while (getline(inputFile, line) && !line.empty()) {
                    // Bỏ qua dòng
                }
            }
            else {
                // Ghi dòng khác vào file tạm
                outputFile << line << endl;
            }
        }

        // Đóng file
        inputFile.close();
        outputFile.close();

        // Xóa file gốc
        remove("Student.txt");

        // Đổi tên file tạm thành tên file gốc
        rename("TempFile.txt", "Student.txt");
        system("cls");
        getViewStudentFromFile();
    }
    else {
        cerr << "Can't open input or output file." << endl;
    }
}
void Student::getViewStudentFromFile()
{
    ifstream inputFile("Student.txt");

    if (inputFile.is_open()) {
        string line;

        cout << "Data after delete\n";

        while (getline(inputFile, line)) {
            // Xuất từng dòng trực tiếp từ file
            cout << line << "\n";
        }

        inputFile.close();
    }
    else {
        cerr << "Can't open input file." << endl;
    }
}
//bool compareStudents(const Student& stu1, const Student& stu2) {
//    return stu1.getID() < stu2.getID(); // Giả sử bạn có một phương thức getID trong lớp Student
//}
//void Student::sortStudents()
//{
//    studentList.sort();
//}

