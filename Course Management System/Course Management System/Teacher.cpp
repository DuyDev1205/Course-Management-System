#include "Teacher.h"
#include <iostream>
#include <iomanip>
#include <sstream>
Teacher::Teacher(string department, double salary, Person p)
    :Person(p.getID(), p.getName(), p.getAddress(), p.getPhoneNumber())
{
    this->department = department;
    this->salary = salary;
    this->teacherId = teacherId;
}

string Teacher::getDepartment()
{
    return this->department;
}

double Teacher::getSalary()
{
    return this->salary;
}

string Teacher::getTeacherId()
{
    return this->teacherId;
}

string Teacher::toString()
{
    ostringstream oss;
    oss << Person::toString()
        << "\nDepartment: " << this->department
        << "\nSalary: " << std::fixed << std::setprecision(2) << this->salary<<" USD";
    return oss.str();
}

bool Teacher::writeFile(Teacher teach)
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

void Teacher::addTeacher()
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
    writeFile(newTeacher);
}

void Teacher::getViewTeacher()
{
    cout << "List of teachers in School\n";
    for (auto& teach : this->teacherList) {
        cout << teach.toString() << "\n\n";
    }
}

void Teacher::clearTeacherList()
{
    system("cls");
    teacherList.clear();
}

void Teacher::readFile(const string& fileName)
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
                salary =stod( line.substr(8));
                teacherList.push_back(Teacher(department, salary,  Person(teacherID, name, address, phone)));
            }
        }

        inputFile.close();
    }
    else {
        cout << "Can't read file!" << endl;
    }
}

void Teacher::deleteTeacher(const string& teacherIdToDelete)
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
        getViewTeacherFromFile();
    }
    else {
        cerr << "Can't open input or output file." << endl;
    }
}

void Teacher::getViewTeacherFromFile()
{
    ifstream inputFile("Teacher.txt");

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

Teacher* Teacher::searchTeacherID(const string& teacherId)
{
    for (auto& teach : teacherList) {
        if (teach.getID() == teacherId) {
            return &teach; // Return a pointer to the teacher if found
        }
    }
    return nullptr; // Return nullptr if not found
}
