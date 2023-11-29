#include <iostream>
#include <string>
#include <Windows.h>

#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
using namespace std;
void Menu(int& choice)
{
    cout << "======= Menu =======\n";
    cout << "1. Student\n";
    cout << "2. Teacher\n";
    cout << "3. Admin\n";
    cout << "4. Receiption\n";
    cout << "5. Course\n";
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
        cout << "1. Add\n";
        cout << "2. Delete by StudentID\n";
        cout << "3. GetAll\n";
        cout << "4. Search\n";
        cout << "5. Sort Student by Name";
        cout << "0. Exit\n";
        cout << "====================\n";
        cout << "Choose function: ";
        cin >> choicef;
    }
    else if (role == "Teacher")
    {
        cout << "======= Menu =======\n";
        cout << "1. Add\n";
        cout << "2. Delete by TeacherID\n";
        cout << "3. GetAll\n";
        cout << "4. Search\n";
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
    int choice, choicef;
    string studentId;
    Menu(choice);
    switch (choice)
    {
        case 1:
            st.readFile("Student.txt");
            system("cls");
            MenuFunction(choicef,"Student");
            switch (choicef)
            {
                case 1:
                    system("cls");
                    st.addStudent(st);
                    system("cls");
                    st.getViewStudent();
                    break;
                case 2:
                    system("cls");
                    st.getViewStudent();
                    cout << "Type StudentID you want to delete: ";
                    cin >> studentId;
                    st.deleteStudent(studentId);
                    break;
                case 5:
                    //st.sortStudents();
                    break;
            }
            break;
        case 2:
            MenuFunction(choicef,"Teacher");
    }
    return 0;
}

