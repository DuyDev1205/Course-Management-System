cmake_minimum_required(VERSION 3.12)
project(CMS LANGUAGES CXX)

add_executable(
    CMS
    "Course Management System.cpp"
    Person.cpp
    Student.cpp
    Teacher.cpp
    Assignment.cpp
    Bill.cpp
    Course.cpp
    Management.cpp
)