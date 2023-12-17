#include "Assignment.h"

Assignment::Assignment(string taskId,
	const string& description,
	string courseId,
	string studentId,
	string teacherId)
{
	this->taskId = taskId;
	this->description = description;
	this->courseId = courseId;
	this->studentId = studentId;
	this->teacherId = teacherId;
}

string Assignment::getTaskId() const
{
	return this->taskId;
}

string Assignment::getDescription() const
{
	return this->description;
}

string Assignment::getCourseId() const
{
	return this->courseId;
}

string Assignment::getStudentId() const
{
	return this->studentId;
}

string Assignment::getTeacherId() const
{
	return this->teacherId;
}

void Assignment::inputAssignment( Assignment& assignment)
{
	string taskId, courseId, studentId, teacherId, description;
	cout << "TaskID: ";
	cin >> taskId;
	if (assignment.searchAssignment(taskId) != nullptr) {
		cout << "Task ID already exists. Please choose a different Task ID." << std::endl;
		return;
	}
	cout << "Enter Description: ";
	cin.ignore(); // Để xóa dấu newline còn lại trong bộ đệm
	getline(cin, description);

	cout << "Enter Course ID: ";
	cin >> courseId;

	cout << "Enter Student ID: ";
	cin >> studentId;
	if (isStudentValid(studentId)==false) {
		cout << "Invalid Student ID. Please enter a valid Student ID." << std::endl;
		return;
	}
	cout << "Enter Teacher ID: ";
	cin >> teacherId;
	Assignment newAssignment(taskId, description, courseId, studentId, teacherId);
	assignment.addAssignment(newAssignment);
	assignment.writeFile(newAssignment);
	cout << "Assignment added successfully." << std::endl;
}

void Assignment::addAssignment(const Assignment& assignment)
{
	listAssign.push_back(assignment);
}

void Assignment::removeAssignment(string taskId)
{
	ifstream inputFile("Assignment.txt");
	ofstream outputFile("TempFile.txt");

	if (inputFile.is_open() && outputFile.is_open()) {
		string line;

		// Đọc từng dòng và ghi vào file tạm
		while (getline(inputFile, line)) {
			if (line.find("Task ID: " + taskId) != string::npos) {
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
		remove("Assignment.txt");

		// Đổi tên file tạm thành tên file gốc
		(void)rename("TempFile.txt", "Assignment.txt");
		system("cls");
		getViewAssignmentFromFile();
	}
	else {
		cerr << "Can't open input or output file." << endl;
	}
			//cout << "Assignment with Task ID '" << taskId << "' removed successfully." << endl;
}

void Assignment::viewAllAssignments() const
{
	for (const auto& assignment : listAssign) {
		// Hiển thị thông tin bài tập, bạn có thể tùy chỉnh theo yêu cầu
		cout << "Task ID: " << assignment.getTaskId() << endl;
		cout << "Description: " << assignment.getDescription() <<endl;
		cout << "CourseID: " << assignment.getCourseId() << endl;
		cout << "TeacherID: " << assignment.getTeacherId() << endl;
		cout << "StudentID: " << assignment.getStudentId() << endl;
	}
}

Assignment* Assignment::searchAssignment(const string& taskId)
{
	for (auto& task : listAssign) {
		if (task.getTaskId() == taskId) {
			return &task; // Trả về con trỏ đến sinh viên nếu tìm thấy
		}
	}
	return nullptr; // Trả về nullptr nếu không tìm thấy
}

bool Assignment::isStudentValid(string studentID)
{
	ifstream inputFile("Student.txt");
	string line,key,value;
	while (getline(inputFile, line)) {
		if (line.find("ID:") == 0) {
			value = line.substr(4);
			if(value == studentID)
			{
				inputFile.close(); // Đóng file sau khi kiểm tra
				return true; // studentId đã tồn tại
			}
		}
	}
	inputFile.close(); // Đóng file nếu không tìm thấy studentId
	return false; // studentId không tồn tại
}

bool Assignment::writeFile(Assignment assignment)
{
	this->listAssign.push_back(assignment);
	ofstream fileOut("Assignment.txt", ios::app);
	//fileOut << endl;
	if (fileOut.is_open()) {
		fileOut << assignment.toString() << endl;
	}
	else {
		cerr << "Can not open file and write." << endl;
	}
	fileOut << endl;
	fileOut.close();
	return true;
}

string Assignment::toString()
{
	ostringstream oss;

	oss << "Task ID: " << getTaskId() << "\n";
	oss << "Description: " << getDescription() << "\n";
	oss << "Course ID: " << getCourseId() << "\n";
	oss << "Teacher ID: " << getTeacherId() << "\n";
	oss << "Student ID: " << getStudentId() << "\n";

	return oss.str();
}

void Assignment::readFile(const string& fileName)
{
	ifstream inputFile(fileName);
	if (inputFile.is_open())
	{
		string line;
		string taskId, courseId, studentId, teacherId, description;
		while (getline(inputFile, line)) {
			if (line.find("Task ID:") == 0) {
				taskId = line.substr(9);
			}
			else if (line.find("Description:") == 0)
			{
				description = line.substr(13);
			}
			else if (line.find("Course ID:") == 0) {
				courseId = line.substr(11);
			}
			else if (line.find("Teacher ID:") == 0)
			{
				teacherId = line.substr(12);
			}
			else if (line.find("Student ID:") == 0)
			{
				studentId = line.substr(12);
				listAssign.push_back(Assignment(taskId, description, courseId, studentId, teacherId));
			}
		}
		inputFile.close();
	}
	else
	{
		cout << "Can't read file!" << endl;
	}
}

void Assignment::getViewAssignment()
{
	cout << "List of Assignment in School\n";
	for (auto& assign : this->listAssign) {
		cout << assign.toString() << "\n\n";
	}
}

void Assignment::assignmentClearList()
{
	listAssign.clear();
}
void Assignment::getViewAssignmentFromFile()
{
	ifstream inputFile("Assignment.txt");

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