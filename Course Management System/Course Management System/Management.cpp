#include "Management.h"

void Management::addStudent()
{
    cout << "Please! Fill down infomation of author that you want to add in system.\n\n";
    string studentID, name, address, phone, majors, grades;

    cout << "ID:";
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
    writeFileStudent(newStudent);
}

bool Management::writeFileStudent(Student stu)
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

void Management::deleteStudent(const string& studentIdToDelete)
{
    ifstream inputFile("Student.txt");
    ofstream outputFile("TempFile.txt");

    if (inputFile.is_open() && outputFile.is_open()) {
        string line;

        // Đọc từng dòng và ghi vào file tạm
        while (getline(inputFile, line)) {
            if (line.find("ID: " + studentIdToDelete) != string::npos) {
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
        (void)rename("TempFile.txt", "Student.txt");
        system("cls");
        getViewFromFile("Student.txt");
    }
    else {
        cerr << "Can't open input or output file." << endl;
    }
}

void Management::clearList()
{
    studentList.clear();
    teacherList.clear();
}

void Management::readFileStudent(const string& fileName)
{
    ifstream inputFile(fileName);

    if (inputFile.is_open()) {
        string line;
        string studentID, name, address, phone, majors, grades;

        while (getline(inputFile, line)) {
            if (line.find("ID:") == 0) {
                studentID = line.substr(4);
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
    }
}

void Management::getViewFromFile(string fileName)
{
    ifstream inputFile(fileName);

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

void Management::addTeacher()
{
    string teacherID, name, address, phone, department;
    double salary;

    cout << "ID:";
    cin.ignore();
    getline(cin, teacherID);

    cout << "Name:";
    getline(cin, name);

    cout << "Address:";
    getline(cin, address);

    cout << "PhoneNumber:";
    getline(cin, phone);

    cout << "Department:";
    getline(cin, department);

    cout << "Salary:";
    cin >> salary;

    Teacher newTeacher(department, salary, Person(teacherID, name, address, phone));
    writeFileTeacher(newTeacher);
}

bool Management::writeFileTeacher(Teacher teach)
{
    this->teacherList.push_back(teach);
    ofstream fileOut("Teacher.txt", ios::app);
    //fileOut << endl;
    if (fileOut.is_open()) {
        fileOut << teach.toString() << endl;
    }
    else {
        cerr << "Can not open file and write." << endl;
    }
    fileOut << endl;
    fileOut.close();
    return true;
}

void Management::readFileTeacher(const string& fileName)
{
    ifstream inputFile(fileName);

    if (inputFile.is_open()) {
        string line;
        string teacherID, name, address, phone, department;
        double salary;

        while (getline(inputFile, line)) {
            if (line.find("ID:") == 0) {
                teacherID = line.substr(4);
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
            else if (line.find("Department:") == 0) {
                department = line.substr(12);
            }
            else if (line.find("Salary:") == 0) {
                salary = stod(line.substr(8));
                teacherList.push_back(Teacher(department, salary, Person(teacherID, name, address, phone)));
            }
        }

        inputFile.close();
    }
    else {
        cout << "Can't read file!" << endl;
    }
}

void Management::deleteTeacher(const string& teacherIdToDelete)
{
    ifstream inputFile("Teacher.txt");
    ofstream outputFile("TempFile.txt");

    if (inputFile.is_open() && outputFile.is_open()) {
        string line;

        // Đọc từng dòng và ghi vào file tạm
        while (getline(inputFile, line)) {
            if (line.find("ID: " + teacherIdToDelete) != string::npos) {
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
        remove("Teacher.txt");

        // Đổi tên file tạm thành tên file gốc
        (void)rename("TempFile.txt", "Teacher.txt");
        system("cls");
        getViewFromFile("Teacher.txt");
    }
    else {
        cerr << "Can't open input or output file." << endl;
    }
}

