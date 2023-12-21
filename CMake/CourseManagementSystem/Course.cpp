#include "Course.h"

Course::Course(string courseID, string name, string professor, string maxCapacity, string schedule)
{
		this->courseID = courseID,
		this->name = name,
		this->professor = professor;
		this->maxCapacity = maxCapacity;
		this->schedule = schedule;
}

void Course::viewCourseDetails()
{
	cout << "Course ID: " << courseID << "\n";
	cout << "Course Name: " << name << "\n";
	cout << "Professor: " << professor << "\n";
	cout << "Max Capacity: " << maxCapacity << "\n";
	cout << "Schedule: " << schedule << "\n";
}

void Course::addCourse()
{
	cout << "Please! Fill down information of the course that you want to add in the system.\n\n";
	string courseID, name, professor, schedule, maxCapacity;

	cout << "Course ID:";
	cin.ignore();
	getline(std::cin, courseID);

	cout << "Course Name:";
	getline(std::cin, name);

	cout << "Professor:";
	getline(std::cin, professor);

	cout << "Max Capacity:";
	cin >> maxCapacity;

	cout << "Schedule:";
	cin.ignore();
	getline(std::cin, schedule);

	Course newCourse(courseID, name, professor, maxCapacity, schedule);
	courseList.push_back(newCourse);
	writeToFile(newCourse);
}

void Course::enrollStudent(Student* studentID)
{
	for (const auto& enrolledStudent : enrolledStudents)
	{
		if (enrolledStudent->getID() == studentID->getID())
		{
			cout << "Student with ID " << studentID->getID() << " is already enrolled in this course.\n";
			return;
		}
	}
	if (enrolledStudents.size() >= stoi(maxCapacity))
	{
		cout << "Course has reached its maximum capacity. Enrollment failed.\n";
		return;
	}
	enrolledStudents.push_back(studentID);
	cout << "Student with ID " << studentID->getID() << " has been enrolled in the course.\n";
}


string Course::toString()
{
	return "CourseID: " + this->courseID
		+ "\nCourseName: " + this->name
		+ "\nProfessor: " + this->professor
		+ "\nMaxCapacity: " + this->maxCapacity
		+ "\nSchedule: " + this->schedule;
}

bool Course::writeToFile(Course course)
{
	this->courseList.push_back(course);
	ofstream fileOut("Course.txt", ios::app);
	//fileOut << endl;
	if (fileOut.is_open()) {
		fileOut << course.toString() << endl;
	}
	else {
		cerr << "Can not open file and write." << endl;
	}
	fileOut << endl;
	fileOut.close();
	return true;
}

void Course::courseClearList()
{
	courseList.clear();	
}

void Course::readFile(const string& fileName)
{
	ifstream inputFile(fileName);

	if (inputFile.is_open()) {
		string line;
		string courseID, name, professor, schedule,maxCapacity;

		while (getline(inputFile, line)) {
			if (line.find("CourseID:") == 0) {
				courseID = line.substr(10);
			}
			else if (line.find("CourseName:") == 0) {
				name = line.substr(12);
			}
			else if (line.find("Professor:") == 0) {
				professor = line.substr(11);
			}
			else if (line.find("MaxCapacity:") == 0) {
				maxCapacity = line.substr(13);
			}
			else if (line.find("Schedule:") == 0) {
				schedule = line.substr(10);
				Course newCourse(courseID, name, professor, maxCapacity, schedule);
				courseList.push_back(newCourse);
			}
		}

		inputFile.close();
	}
	else {
		cout << "Can't read file!" << endl;
	}
}

void Course::getViewCourse()
{
	cout << "List of students in School\n";
	for (auto& course : this->courseList) {
		cout << course.toString() << "\n\n";
	}
}

void Course::deleteCourse(const string& CourseIdToDelete)
{
	ifstream inputFile("Course.txt");
	ofstream outputFile("TempFile.txt");

	if (inputFile.is_open() && outputFile.is_open()) {
		string line;

		// Đọc từng dòng và ghi vào file tạm
		while (getline(inputFile, line)) {
			if (line.find("CourseID: " + CourseIdToDelete) != string::npos) {
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
		remove("Course.txt");

		// Đổi tên file tạm thành tên file gốc
		(void)rename("TempFile.txt", "Course.txt");
		system("cls");
		getViewCourseFromFile();
	}
	else {
		cerr << "Can't open input or output file." << endl;
	}
}

void Course::getViewCourseFromFile()
{
	ifstream inputFile("Course.txt");

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

Course* Course::searchCourseId(const string& CourseID)
{
	for (auto& course :courseList) {
		if (course.getCourseID() == CourseID) {
			return &course; // Trả về con trỏ đến sinh viên nếu tìm thấy
		}
	}
	return nullptr; // Trả về nullptr nếu không tìm thấy
}

string Course::getCourseID()
{
	return this->courseID;
}


