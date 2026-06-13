#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<fstream>
#include<stack>
#include<queue>
#include<utility>
#include<set>
#include<algorithm>
#include<limits>
using namespace std;

class Person
{
protected:
	int age;
	string name;
	char gender;
public:
	Person()
	{
		age = 0;
		name = "";
		gender = ' ';
	}
	void inputPerson()
	{
		cout << "Enter name of Person:";
		getline(cin, name);
		cout << "Enter Age of Person in integer:";
		cin >> age;
		char c;
		do
		{
			cout << "Enter Gender (M/F/N/T):";
			cin >> c;
			if (c == 'M' || c == 'F' || c == 'N' || c == 'T')
			{
				gender = c;
				break;
			}
			else
			{
				cout << endl << "Invalid Input Try Again:" << endl;
			}

		} while (true);

	}
	void displayPerson()
	{
		cout << "Name:" << name << endl;
		cout << "Age:" << age << endl;
		cout << "Gender:" << gender << endl;
	}
};
class Student :public Person
{
private:
	int rollNo;
	string className;
public:
	Student()
	{
		rollNo = 0;
		className = "";
	}
	void addStudent()
	{
		cout << "!!!! ADD STUDENT !!!!" << endl;
		cout << "Enter Roll Number:";
		cin >> rollNo;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		inputPerson();
		cout << "Enter ClassName:";
		getline(cin, className);
	}
	void updateStudent()
	{
		cout << "!!!! UPDATING STUDENT !!!!" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		inputPerson();
		cout << "Enter class Name:";
		getline(cin, className);
	}
	void displayStudent()
	{
		cout << "!!! DISPLAY STUDENT !!!" << endl;
		cout << "Class Name:" << className << endl;
		displayPerson();
	}
	void saveToFile(ofstream& fout)
	{
		fout << rollNo << endl;
		fout << name << endl;
		fout << age << endl;
		fout << gender << endl;
		fout << className << endl;
	}
	void loadFromFile(ifstream& fin)
	{
		fin >> rollNo;
		fin.ignore();

		getline(fin, name);

		fin >> age;
		fin >> gender;

		fin.ignore();

		getline(fin, className);
	}
	int getRollNo()
	{
		return rollNo;
	}
	string getName()
	{
		return name;
	}
};
class Teacher :public Person
{
private:
	int teacherId;
	string subjectName;
public:
	Teacher()
	{
		teacherId = 0;
		subjectName = "";
	}
	void addTeacher()
	{
		cout << "!!! ADD TEACHER !!!" << endl;
		cout << "Enter Teacher id:";
		cin >> teacherId;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		inputPerson();
		cout << "Enter Subject Name:";
		getline(cin, subjectName);
	}
	void updateTeacher()
	{
		cout << "!!! UPDATE TEACHER !!!" << endl;
		inputPerson();
		cout << "Enter subject Name:";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, subjectName);
		
	}
	void displayTeacher()
	{
		cout << "!!! DISPLAY TEACHER !!!" << endl;
		displayPerson();
		cout << "Subject Name:" << subjectName << endl;;
	}
	void saveToFile(ofstream& fout)
	{
		fout << teacherId << endl;
		fout << name << endl;
		fout << age << endl;
		fout << gender << endl;
		fout << subjectName << endl;
	}
	void loadFromFile(ifstream& fin)
	{
		fin >> teacherId;
		fin.ignore();
		getline(fin, name);
		fin >> age;
		fin >> gender;
		fin.ignore();
		getline(fin, subjectName);
	}
	int getTeacherId()
	{
		return teacherId;
	}
	string teacherName()
	{
		return name;
	}
};
class Attendance
{
private:
	int rollNo;
	int presentDays;
	int totalDays;
public:
	Attendance()
	{
		rollNo=0;
		presentDays = 0;
		totalDays = 0;
	}
	void markAttendance()
	{
		cout << endl << "Enter Roll No:" << endl;
		cin >> rollNo;
		cout << endl << "Enter Present Days:";
		cin >> presentDays;
		cout << endl << "Enter Total Days:";
		cin >> totalDays;
	}
	void displayAttendance()
	{
		cout << endl << "!! ATTENDANCE !!" << endl;
		cout << "Roll no:" << rollNo << endl;
		cout << "Present Days:" << presentDays << endl;
		cout << "Total Days:" << totalDays << endl;
		double percentage;
		if(totalDays > 0)
		{
			percentage = ((double)presentDays / totalDays) * 100;
		}
		else
		{
			percentage = 0;
		}
		cout << "Attendace %:" << percentage << "%" << endl;
	}
	void saveToFile(ofstream& fout)
	{
		fout << rollNo << " "<< presentDays << " "<< totalDays << " "<<endl;
	}
	void loadFromFile(ifstream& fin)
	{
		fin >> rollNo>> presentDays>> totalDays;
	}
	int getRollNo()
	{
		return rollNo;
	}
};
class Result
{
private:
	int rollNo;
	//vector for storing marks
	vector<float>marks;
	float percentage;
	char grade;
public:
	Result()
	{
		rollNo = 0;
		percentage = 0;
		grade = 'F';
	}
	void addMarks()
	{
		int subjects;
		cout << endl << "Enter Roll No:";
		cin >> rollNo;
		cout << endl << "Enter number of Subjects:";
		cin >> subjects;
		marks.clear();
		for (int i = 0;i < subjects;i++)
		{
			float m;
			cout << "Enter Marks " << i + 1 << ":";
			cin >> m;
			marks.push_back(m);
		}
		calculateResult();
	}
	void calculateResult()
	{
		float total = 0;
		for (float x : marks)
		{
			total += x;
		}
		if (!marks.empty())
		{
			percentage = total / marks.size();
		}
		else
		{
			percentage = 0;
		}
		if (percentage >= 90)
			grade = 'A';
		else if (percentage >= 80)
			grade = 'B';
		else if (percentage >= 70)
			grade = 'C';
		else if (percentage >= 60)
			grade = 'D';
		else if (percentage >= 50)
			grade = 'E';
		else
			grade = 'F';
	}
	void displayResult()
	{
		cout << endl << "!!! RESULT !!!" << endl;
		cout << "Roll no:" << rollNo << endl;
		cout << "Percentage:" << percentage << endl;
		cout << "Grade:" << grade << endl;
	}
	void saveToFile(ofstream& fout)
	{
		fout << rollNo << endl;

		fout << marks.size() << endl;

		for (float m : marks)
		{
			fout << m << " ";
		}

		fout << endl;

		fout << percentage << endl;
		fout << grade << endl;
	}
	void loadFromFile(ifstream& fin)
	{
		int count;

		fin >> rollNo;

		fin >> count;

		marks.clear();

		for (int i = 0;i < count;i++)
		{
			float m;
			fin >> m;
			marks.push_back(m);
		}

		fin >> percentage;
		fin >> grade;
	}
	int getRollNo()
	{
		return rollNo;
	}
	float getPercentage() const
	{
		return percentage;
	}
};
class Fee
{
private:
	int rollNo;
	float totalFee;
	float paidFee;
public:
	Fee()
	{
		rollNo = 0;
		totalFee = 0;
		paidFee = 0;
	}
	void payFee()
	{
		cout << endl << "Enter Roll No:";
		cin >> rollNo;
		cout << "Enter total Fee:";
		cin >> totalFee;
		cout << "Enter paid Fee:";
		cin >> paidFee;
	}
	void feeStatus()
	{
		cout << endl << "!! FEE STATUS !!" << endl;
		cout << "Roll No:" << rollNo << endl;
		cout << "Total Fee:" << totalFee << endl;
		cout << "Paid Fee:" << paidFee << endl;
		cout << "Remaining Fee:" << totalFee - paidFee << endl;
	}
	void saveToFile(ofstream& fout)
	{
		fout << rollNo << " "<< totalFee << " "<< paidFee << endl;
	}
	void loadFromFile(ifstream& fin)
	{
		fin >> rollNo>> totalFee>> paidFee;
	}
	int getRollNo()
	{
		return rollNo;
	}
};
class Subject
{
private:
	int subjectId;
	string subjectName;
public:
	Subject()
	{
		subjectId = 0;
		subjectName = "";
	}
	void addSubject()
	{
		cout << endl << "Enter subject Id:";
		cin >> subjectId;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter Subject Name:";
		getline(cin, subjectName);
	}
	void displaySubject()
	{
		cout << endl << "Subject Id:" << subjectId << endl;
		cout << "Subject Name:" << subjectName << endl;
	}
	void saveToFile(ofstream& fout)
	{
		fout << subjectId << endl;
		fout << subjectName << endl;
	}
	void loadFromFile(ifstream& fin)
	{
		fin >> subjectId;
		fin.ignore();
		getline(fin,subjectName);
	}
	int getSubjectId()
	{
		return subjectId;
	}
};
class ActivityLog
{
private:
	stack<string>logs;
public:
	void addLog(string activity)
	{
		logs.push(activity);
	}
	void showLatestActivity()
	{
		if (logs.empty())
		{
			cout << "!! No Activity Found !!" << endl;
			return;
		}
		cout << "!! Latest Activity !!" << endl;
		cout << logs.top() << endl;
	}
	void showAllActivity()
	{
		stack<string>temp = logs;
		cout << endl << "!!! ACTIVITY HISTORY !!!" << endl;
		while (!temp.empty())
		{
			cout << temp.top() << endl;
			temp.pop();
		}
	}
};
class AdmissionQueue
{
private:
	queue<string>requests;
public:
	void addRequest(string studentName)
	{
		requests.push(studentName);
	}
	void processRequest()
	{
		if (requests.empty())
		{
			cout << "!! No Requests !!" << endl;
			return;
		}
		cout << "Processing:" << requests.front() << endl;
		requests.pop();
	}
	void showRequests()
	{
		queue<string>temp = requests;
		cout << endl << "!! ADMISSION QUEUE !!" << endl;
		while (!temp.empty())
		{
			cout << temp.front() << endl;
			temp.pop();
		}
	}
};
class TopperSystem
{
private:
	priority_queue<pair<float, int>>toppers;
public:
	void addStudentResult(int rollNo, float percentage)
	{
		toppers.push({ percentage,rollNo });
	}
	void showTopper()
	{
		if (toppers.empty())
		{
			cout << "No Result" << endl;
			return;
		}
		cout << "!!   SCHOOL TOPPER  !!" << endl;
		cout << "Roll No:" << toppers.top().second << endl;
		cout << "Percentage:" << toppers.top().first << "%" << endl;
	}
};
class BSTNode
{
public:
	Student data;
	BSTNode* left;
	BSTNode* right;
	BSTNode(Student s)
	{
		data = s;
		left = NULL;
		right = NULL;
	}
};
class StudentBST
{
private:
	BSTNode* root;
public:
	StudentBST()
	{
		root = NULL;
	}
	BSTNode* insert(BSTNode* node, Student s)
	{
		if (node == NULL)
		{
			return new BSTNode(s);
		}
		if (s.getRollNo() < node->data.getRollNo())
		{
			node->left = insert(node->left, s);
		}
		else if(s.getRollNo()>node->data.getRollNo())
		{
			node->right = insert(node->right, s);
		}
		return node;
	}
	void insertStudent(Student s)
	{
		root = insert(root, s);
	}
	BSTNode* search(BSTNode* node, int roll)
	{
		if (node == NULL)
		{
			return NULL;
		}
		if (node->data.getRollNo() == roll)
		{
			return node;
		}
		if (roll < node->data.getRollNo())
		{
			return search(node->left, roll);
		}
		return search(node->right, roll);
	}
	void searchStudent(int roll)
	{
		BSTNode* result = search(root, roll);
		if (result)
		{
			cout << endl << "!!! Student Found !!!" << endl;
			result->data.displayStudent();
		}
		else
		{
			cout << endl << "!! Student Not Found !!" << endl;
		}
	}
};
class TeacherClassGraph
{
private:
	unordered_map<int, vector<string>>graph;
public:
	void assignClass(int teacherId, string className)
	{
		graph[teacherId].push_back(className);
	}
	void showAssignments()
	{
		cout << endl << "!! TEACHER CLASS GRAPH !!" << endl;
		for (auto& pair : graph)
		{
			cout << endl << "TeacherId:" << pair.first << endl;
			for (auto& cls : pair.second)
			{
				cout << "->" << cls << endl;
			}
		}
	}
	void saveGraph(ofstream& fout)
	{
		fout << graph.size() << endl;
		for (auto& p : graph)
		{
			fout << p.first << endl;
			fout << p.second.size() << endl;
			for (string cls : p.second)
			{
				fout << cls << endl;
			}
		}
	}
	void loadGraph(ifstream& fin)
	{
		int count;
		fin >> count;
		graph.clear();
		for (int i = 0;i < count;i++)
		{
			int teacherId;
			int sz;
			fin >> teacherId;
			fin >> sz;
			fin.ignore();
			for (int j = 0;j < sz;j++)
			{
				string cls;
				getline(fin, cls);
				graph[teacherId].push_back(cls);
			}
		}
	}
};
class SchoolGraph
{
private:
	unordered_map<int, vector<int> >graph;
public:
	void addEdge(int u, int v)
	{
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	void BFS(int start)
	{
		unordered_map<int, bool>visited;
		queue<int>q;
		q.push(start);
		visited[start] = true;
		cout << endl << "BFS:";
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			cout << node << " ";
			for (auto& neighbour : graph[node])
			{
				if (!visited[neighbour])
				{
					visited[neighbour] = true;
					q.push(neighbour);
				}
			}
		}
		cout << endl;
	}
	void DFSHelper(int node, unordered_map<int, bool>& visited)
	{
		visited[node] = true;
		cout << node << " ";
		for (auto neighbour : graph[node])
		{
			if (!visited[neighbour])
			{
				DFSHelper(neighbour, visited);
			}
		}
	}
	void DFS(int start)
	{
		unordered_map<int, bool>visited;
		cout << endl << "DFS:";
		DFSHelper(start, visited);
	}
	void saveGraph(ofstream& fout)
	{
		fout << graph.size() << endl;
		for (auto& p : graph)
		{
			fout << p.first << " " << p.second.size();
			for (int v : p.second)
			{
				fout << " " << v;
			}
			fout << endl;
		}
	}
	void loadGraph(ifstream& fin)
	{
		int nodes;
		fin >> nodes;
		graph.clear();
		for (int i = 0;i < nodes;i++)
		{
			int u, size;
			fin >> u >> size;
			for (int j = 0;j < size;j++)
			{
				int v;
				fin >> v;
				graph[u].push_back(v);
			}
		}
	}
};
class School
{
private:
	//vector for storing student data;
	vector<Student>students;
	//vector for storing teacher data
	vector<Teacher>teachers;
	//Hashmap for searching fast
	unordered_map<int, int>studentIndex;
	unordered_map<int, int>teacherIndex;
	//vector  for storing attendance
	vector<Attendance>attendanceRecords;
	//vector for storing results
	vector<Result>results;
	//vector for storing fees
	vector<Fee>feeRecords;
	//vector for storing subjects
	vector<Subject>subjects;
	ActivityLog activityLog;
	StudentBST bst;
	AdmissionQueue admissionQueue;
	TopperSystem topperSystem;
	TeacherClassGraph teacherGraph;
	SchoolGraph schoolGraph;
public:
	void addStudent();
	void viewStudents();
	void searchStudent();
	void bstSearchStudent();
	void updateStudent();
	void deleteStudent();
	void addTeacher();
	void viewTeachers();
	void searchTeacher();
	void updateTeacher();
	void deleteTeacher();

	void addAttendance();
	void viewAttendance();
	void addResult();
	void viewResults();
	void addFeeRecords();
	void viewFees();
	void addSubject();
	void viewSubjects();
	//DSA
	void showPendingRequests();
	void addAdmissionRequest();
	void processAdmissionRequest();
	void showTopper();
	void showActivityLog();
	void showLatestActivity();
	//GRAPH
	void runDFS();
	void runBFS();
	void runBinarySearch();
	void addSchoolConnection();
	void assignTeacherClass();
	void showTeacherAssignments();
	//File
	void saveAllData();
	void saveStudents();
	void loadStudents();
	void saveResult();
	void saveAttendance();
	void saveFees();
	void loadAllData();
	void loadTeachers();
	void loadAttendance();
	void loadResults();
	void loadFees();
	void loadSubjects();
	void mainMenu();
	static bool compareResult(const Result& a, const Result& b);
	void sortResults();
	void binarySearchStudent(vector<int>& rolls, int target);
	void saveTeachers();
	void saveSubjects();
	void rebuildBST();
	void saveSchoolGraph();
	void loadSchoolGraph();
	void saveTeacherGraph();
	void loadTeacherGraph();
};
void School::rebuildBST()
{
	bst = StudentBST();
	for (auto& s : students)
	{
		bst.insertStudent(s);
	}
}
void School::addStudent()
{
	Student s;
	s.addStudent();
	if (studentIndex.find(s.getRollNo()) != studentIndex.end())
	{
		cout << endl << "!! Student Roll number already exist !!" << endl;
		return;
	}
	students.push_back(s);
	bst.insertStudent(s);
	activityLog.addLog("Student Added Roll No:"+to_string(s.getRollNo()));
	int index = students.size() - 1;
	studentIndex[s.getRollNo()] = index;
	cout << endl << "!!! Student Added Successfully !!!" << endl;
}
void School::viewStudents()
{
	if (students.empty())
	{
		cout << endl << "!!! STUDENTS NOT FOUND !!!" << endl;
		return;
	}
	cout << endl << "!! ALL STUDENTS RECORD !!" << endl;
	for (int i = 0;i < students.size();i++)
	{
		students[i].displayStudent();
	}
}
void School::searchStudent()
{
	int roll;
	cout << "Enter Roll NO:";
	cin >> roll;
	if (studentIndex.find(roll) != studentIndex.end())
	{
		int index = studentIndex[roll];
		students[index].displayStudent();
	}
	else
	{
		cout << endl << "!!! STUDENT NOT FOUND !!!" << endl;
	}
}
void School::bstSearchStudent()
{
	int roll;
	cout << "Enter roll no:";
	cin >> roll;
	bst.searchStudent(roll);
}
void School::updateStudent()
{
	int rollNo;
	cout << "Enter Roll No:";
	cin >> rollNo;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (studentIndex.find(rollNo) != studentIndex.end())
	{
		int index = studentIndex[rollNo];
		students[index].updateStudent();
		rebuildBST();
		activityLog.addLog("Student Updated:"+to_string(rollNo));
		cout << endl << "!! Student Updated Successfully !!" << endl;
	}
	else
	{
		cout << "!! Student Not Found !!" << endl;
	}
}
void School::deleteStudent()
{
	int roll;
	cout << "Enter Roll No:";
	cin >> roll;
	if (studentIndex.find(roll) != studentIndex.end())
	{
		int index = studentIndex[roll];
		students.erase(students.begin() + index);
		studentIndex.clear();
		for (int i = 0;i < students.size();i++)
		{
			studentIndex[students[i].getRollNo()] = i;
		}
		activityLog.addLog("Student Deleted"+to_string(roll));
		cout << endl << "!!! STUDENTS DELETED SUCCESSFULLY !!!" << endl;
		rebuildBST();
	}
	else
	{
		cout << endl << "!! STUDENT DOES NOT FOUND !!" << endl;
	}
}
void School::addTeacher()
{
	Teacher t;
	t.addTeacher();
	if (teacherIndex.find(t.getTeacherId()) != teacherIndex.end())
	{
		cout << endl << "!! Teacher Id Already Exist !!" << endl;
		return;
	}
	teachers.push_back(t);
	int index = teachers.size() - 1;
	teacherIndex[t.getTeacherId()] = index;
	activityLog.addLog("Teacher Added"+to_string(t.getTeacherId()));
	cout << endl << "!!! TEACHER ADDED SUCCESSFULLY !!!" << endl;
}
void School::viewTeachers()
{
	if (teachers.empty())
	{
		cout << endl << "!! Teacher does Not Found !!" << endl;
		return;
	}
	else
	{
		for (int i = 0;i < teachers.size();i++)
		{
			teachers[i].displayTeacher();
		}
	}
}
void School::searchTeacher()
{
	int teacherId;
	cout << "Enter Teacher id:";
	cin >> teacherId;
	if (teacherIndex.find(teacherId) != teacherIndex.end())
	{
		int index = teacherIndex[teacherId];
		teachers[index].displayTeacher();
	}
	else
	{
		cout << endl << "!! TEACHER DOES NOT FOUND !!" << endl;
	}
}
void School::updateTeacher()
{
	int teacherId;
	cout << "Enter Teacher id:";
	cin >> teacherId;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (teacherIndex.find(teacherId) != teacherIndex.end())
	{
		int index = teacherIndex[teacherId];
		teachers[index].updateTeacher();
		activityLog.addLog("Teacher Updated"+to_string(teacherId));
	}
	else
	{
		cout << "!! Teacher Does Not Found !!" << endl;
	}
}
void School::deleteTeacher()
{
	int teacherId;
	cout << "Enter Teacher id:";
	cin >> teacherId;
	if (teacherIndex.find(teacherId) != teacherIndex.end())
	{
		int index = teacherIndex[teacherId];
		teachers.erase(teachers.begin() + index);
		teacherIndex.clear();
		for (int i = 0;i < teachers.size();i++)
		{
			teacherIndex[teachers[i].getTeacherId()] = i;
		}
		activityLog.addLog("Teacher Deleted"+to_string(teacherId));
		cout << endl << "!! DELETED SUCCESSFULLY !!" << endl;
		return;
	}
	cout << endl << "!! Teacher Does Not Found !!" << endl;
}
void School::addAttendance()
{
	Attendance a;
	a.markAttendance();
	attendanceRecords.push_back(a);
	activityLog.addLog("Attendance Added"+to_string(a.getRollNo()));
}
void School::viewAttendance()
{
	for (auto& a : attendanceRecords)
	{
		a.displayAttendance();
	}
}
void School::addResult()
{
	Result r;
	r.addMarks();
	topperSystem.addStudentResult(r.getRollNo(), r.getPercentage());
	results.push_back(r);
	activityLog.addLog("result Added"+to_string(r.getRollNo()));
}
void School::viewResults()
{
	for (auto& r : results)
	{
		r.displayResult();
	}
}
void School::addFeeRecords()
{
	Fee f;
	f.payFee();
	feeRecords.push_back(f);
	activityLog.addLog("Fee Record Added");
}
void School::viewFees()
{
	for (auto& f : feeRecords)
	{
		f.feeStatus();
	}
}
void School::addSubject()
{
	Subject s;
	s.addSubject();
	subjects.push_back(s);
	activityLog.addLog("Subject Added");
}
void School::viewSubjects()
{
	for (auto& s : subjects)
	{
		s.displaySubject();
	}
}
void School::saveStudents()
{
	ofstream fout("D:\\cs notes\\students.txt");
	if (!fout)
	{
		cout << endl << "!! File Error !!" << endl;
		return;
	}
	fout << students.size() << endl;
	for(auto &s : students)
    {
        s.saveToFile(fout);
    }
	fout.close();
}
void School::loadStudents()
{
	bst = StudentBST();
	ifstream fin("D:\\cs notes\\students.txt");

	if (!fin)
	{
		return;
	}

	int count;

	fin >> count;
	fin.ignore();

	students.clear();
	studentIndex.clear();

	for (int i = 0;i < count;i++)
	{
		Student s;

		s.loadFromFile(fin);

		students.push_back(s);

		studentIndex[s.getRollNo()] = i;

		bst.insertStudent(s);
	}

	fin.close();
}
void School::saveResult()
{
	ofstream fout("D:\\cs notes\\results.txt");
	fout << results.size()<<endl;
	for (auto& r : results)
	{
		r.saveToFile(fout);
	}
	fout.close();
}
void School::saveAttendance()
{
	ofstream fout("D:\\cs notes\\attendance.txt");
	fout << attendanceRecords.size() << endl;
	for (auto& a : attendanceRecords)
	{
		a.saveToFile(fout);
	}
	fout.close();
}
void School::saveFees()
{
	ofstream fout("D:\\cs notes\\fees.txt");
	fout << feeRecords.size()<<endl;
	for (auto& f : feeRecords)
	{
		f.saveToFile(fout);
	}
	fout.close();
}
void School::saveTeachers()
{
	ofstream fout("D:\\cs notes\\teachers.txt");
	if (!fout)
	{
		return;
	}
	fout << teachers.size() << endl;
	for (auto& t : teachers)
	{
		t.saveToFile(fout);
	}
	fout.close();
}
void School::saveSubjects()
{
	ofstream fout("D:\\cs notes\\subjects.txt");

	if (!fout)
		return;

	fout << subjects.size() << endl;

	for (auto& s : subjects)
	{
		s.saveToFile(fout);
	}

	fout.close();
}
void School::saveSchoolGraph()
{
	ofstream fout("D:\\cs notes\\SchoolGraph.txt");
	if (!fout)
	{
		return;
	}
	schoolGraph.saveGraph(fout);
	fout.close();
}
void School::loadSchoolGraph()
{
	ifstream fin("D:\\cs notes\\SchoolGraph.txt");
	if (!fin)
	{
		return;
	}
	schoolGraph.loadGraph(fin);
	fin.close();
}
void School::saveTeacherGraph()
{
	ofstream fout("D:\\cs notes\\Teacher Graph.txt");
	if (!fout)
	{
		return;
	}
	teacherGraph.saveGraph(fout);
	fout.close();
}
void School::loadTeacherGraph()
{
	ifstream fin("D:\\cs notes\\Teacher Graph.txt");
	if (!fin)
	{
		return;
	}
	teacherGraph.loadGraph(fin);
	fin.close();
}
void School::loadTeachers()
{
	ifstream fin("D:\\cs notes\\teachers.txt");

	if (!fin)
	{
		return;
	}

	int count;
	fin >> count;
	fin.ignore();
	teachers.clear();
	teacherIndex.clear();
	for (int i = 0; i < count; i++)
	{
		Teacher t;
		t.loadFromFile(fin);
		teachers.push_back(t);
		teacherIndex[t.getTeacherId()] = i;
	}
	fin.close();
}
void School::loadAttendance()
{
	ifstream fin("D:\\cs notes\\attendance.txt");
	if (!fin)
	{
		return;
	}
	int count;
	fin >> count;
	attendanceRecords.clear();
	for (int i = 0; i < count; i++)
	{
		Attendance a;
		a.loadFromFile(fin);
		attendanceRecords.push_back(a);
	}
	fin.close();
}
void School::loadResults()
{
	ifstream fin("D:\\cs notes\\results.txt");
	if (!fin)
	{
		return;
	}
	int count;
	fin >> count;
	results.clear();
	for (int i = 0; i < count; i++)
	{
		Result r;
		r.loadFromFile(fin);
		results.push_back(r);
		topperSystem.addStudentResult(
			r.getRollNo(),
			r.getPercentage()
		);
	}
	fin.close();
}
void School::loadFees()
{
	ifstream fin("D:\\cs notes\\fees.txt");
	if (!fin)
	{
		return;
	}
	int count;
	fin >> count;
	feeRecords.clear();
	for (int i = 0; i < count; i++)
	{
		Fee f;
		f.loadFromFile(fin);
		feeRecords.push_back(f);
	}
	fin.close();
}
void School::loadSubjects()
{
	ifstream fin("D:\\cs notes\\subjects.txt");

	if (!fin)
	{
		return;
	}
	int count;
	fin >> count;
	fin.ignore();
	subjects.clear();
	for (int i = 0; i < count; i++)
	{
		Subject s;
		s.loadFromFile(fin);
		subjects.push_back(s);
	}
	fin.close();
}


bool School::compareResult(const Result& a, const Result& b)
{
	return a.getPercentage() > b.getPercentage();

}
void School::sortResults()
{
	std::sort(results.begin(), results.end(),School::compareResult);
	std::cout << endl << "!! RANK LIST !!" << endl;
	for (auto& r : results)
	{
		r.displayResult();
	}
}
void School::binarySearchStudent(vector<int>& rolls, int target)
{
	int left = 0;
	int right = rolls.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (rolls[mid] == target)
		{
			cout << "Student Found" << endl;
			return;
		}
		if (rolls[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << "Student Not Found!" << endl;
}
void School::showPendingRequests()
{
	admissionQueue.showRequests();
}
void School::addAdmissionRequest()
{
	cout << "Enter name:";
	string name;
	cin.ignore();
	getline(cin, name);
	admissionQueue.addRequest(name);
	activityLog.addLog("Admission Request Added");
}
void School:: processAdmissionRequest()
{
	admissionQueue.processRequest();
	activityLog.addLog("Admission Request Processed");
}
void School::showLatestActivity()
{
	activityLog.showLatestActivity();
}
void School::showActivityLog()
{
	activityLog.showAllActivity();
}
void School::showTopper()
{
	topperSystem.showTopper();
}
void School::assignTeacherClass()
{
	int teacherId;
	string className;
	cout << endl << "Teacher Id:";
	cin >> teacherId;
	cout << endl << "Class Name:";
	cin.ignore();
	getline(cin, className);
	teacherGraph.assignClass(teacherId, className);
	activityLog.addLog("Teacher Assined To Class");
}
void School::showTeacherAssignments()
{
	teacherGraph.showAssignments();
}
void School::addSchoolConnection()
{
	int u, v;
	cout << "Enter Node 1:";
	cin >> u;
	cout << "Enter Node 2:";
	cin >> v;
	schoolGraph.addEdge(u, v);
}
void School::runBFS()
{
	int start;
	cout << "Enter starting Node:";
	cin >> start;
	schoolGraph.BFS(start);
}
void School::runDFS()
{
	int start;
	cout << "Enter Start Node:";
	cin >> start;
	schoolGraph.DFS(start);
}
void School::runBinarySearch()
{
	vector<int>rolls;
	for (auto& s : students)
	{
		rolls.push_back(s.getRollNo());
	}
	sort(rolls.begin(), rolls.end());
	int target;
	cout << "Enter Roll No:";
	cin >> target;
	binarySearchStudent(rolls, target);
}
void School::saveAllData()
{
	saveStudents();
	saveTeachers();
	saveSubjects();
	saveAttendance();
	saveResult();
	saveFees();
	saveSchoolGraph();
	saveTeacherGraph();
	cout << endl << "!! DATA SAVED !!";
}
void School::loadAllData()
{
	cout << endl << endl << "!! LOAD ALL DATA !!" << endl;
	loadStudents();
	loadTeachers();
	loadAttendance();
	loadResults();
	loadFees();
	loadSubjects();
	loadSchoolGraph();
	loadTeacherGraph();
}

void School::mainMenu()
{
	int choice;
	do
	{
		cout << endl << "!! SCHOOL MANAGEMENT SYSTEM !!" << endl;
		cout << endl << "!! STUDENT MANAGEMENT !!" << endl;
		cout << endl << " 1.Add Student:";
		cout << endl << " 2.View Students:";
		cout << endl << " 3.Search Student(HASHMAP):";
		cout << endl << " 4.Search Student(BST):";
		cout << endl << " 5.Update Student:";
		cout << endl << " 6.Delete Student:";
		cout << endl << endl << "!! TEACHER MANAGEMENT !!";
		cout << endl << " 7.Add Teacher:";
		cout << endl << " 8.View Teachers:";
		cout << endl << " 9.Search Teacher:";
		cout << endl << " 10.Update teacher:";
		cout << endl << " 11.Delete Teacher:";
		cout << endl << endl << "!! ATTENDANCE !!" << endl;
		cout << endl << " 12.Add Attendance:";
		cout << endl << " 13.View Attendance:";
		cout << endl << endl << "!! Results !!" << endl;
		cout << endl << " 14.Add Result:";
		cout << endl << " 15.View Results:";
		cout << endl << " 16.Rank List:";
		cout << endl << " 17.School Topper:";
		cout << endl << endl << " !! FEES !!" << endl;
		cout << endl << " 18.Add Fee:";
		cout << endl << " 19.View Fee:";
		cout << endl << endl << " !! Subjects !!" << endl;
		cout << endl << " 20.Add Subject:";
		cout << endl << " 21.View Subjects:";
		cout << endl << endl << "!! Admission Queue !!" << endl;
		cout << endl << " 22.Add Admission Request:";
		cout << endl << " 23.Process Admission Request:";
		cout << endl << " 24.View pending Request:";
		cout << endl << endl << "!! Activity Log !!" << endl;
		cout << endl << " 25.Show latest Activity:";
		cout << endl << " 26.Show Full Activity:";
		cout << endl << endl << "!! Teacher Class Graph !!" << endl;
		cout << endl << " 27.Assign Teacher To Class:";
		cout << endl << " 28.Show Teacher Assignments:";
		cout << endl << endl << "!! School graph !!" << endl;
		cout << endl << " 29. Add Graph Edge:";
		cout << endl << " 30. BFS Traversal:";
		cout << endl << " 31. DFS Traversal:";
		cout << endl << endl << "!! Searching Algorithm !!" << endl;
		cout << endl << " 32. Binary Search Student By Roll:";
		cout << endl << endl << " !! File Handling !!" << endl;
		cout <<endl<< " 33.Load All Data:";
		cout << endl << " 34.Save All Data:";
		cout << endl << " 0.For EXIT:";
		cout << endl << "Choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			addStudent();
			break;
		case 2:
			viewStudents();
			break;
		case 3:
			searchStudent();
			break;
		case 4:
			bstSearchStudent();
			break;
		case 5:
			updateStudent();
			break;
		case 6:
			deleteStudent();
			break;
		case 7:
			addTeacher();
			break;
		case 8:
			viewTeachers();
			break;
		case 9:
			searchTeacher();
			break;
		case 10:
			updateTeacher();
			break;
		case 11:
			deleteTeacher();
			break;
		case 12:
			addAttendance();
			break;
		case 13:
			viewAttendance();
			break;
		case 14:
			addResult();
			break;
		case 15:
			viewResults();
			break;
		case 16:
			sortResults();
			break;
		case 17:
			showTopper();
			break;
		case 18:
			addFeeRecords();
			break;
		case 19:
			viewFees();
			break;
		case 20:
			addSubject();
			break;
		case 21:
			viewSubjects();
			break;
		case 22:
			addAdmissionRequest();
			break;
		case 23:
			processAdmissionRequest();
			break;
		case 24:
			showPendingRequests();
			break;
		case 25:
			showLatestActivity();
			break;
		case 26:
			showActivityLog();
			break;
		case 27:
			assignTeacherClass();
			break;
		case 28:
			showTeacherAssignments();
			break;
		case 29:
			addSchoolConnection();
			break;
		case 30:
			runBFS();
			break;
		case 31:
			runDFS();
			break;
		case 32:
			runBinarySearch();
			break;
		case 33:
			loadAllData();
			break;
		case 34:
			saveAllData();
			break;
		case 0:
			cout << endl << "!! Thankyou For Using My Project !!" << endl;
			cout << "!! MADE BY VINAY YADAV !!" << endl;
			break;
		default:
			cout << endl << "!! INVALID CHOICE !!" << endl;
			cout << "!! TRY AGAIN !!" << endl;
		}
	} while (choice != 0);
}
int main()
{
	School school;
	school.loadAllData();
	school.mainMenu();
	school.saveAllData();
	return 0;

}
