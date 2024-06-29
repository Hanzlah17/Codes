#include<iostream>
#include<Windows.h>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
class Course
{
	string code;
	string name;
	string instructor;
	int credithour;
	vector<int> quizmarks;
	vector<int> assignmentmarks;
	int finalMarks;
};
class Student
{
	string name;
	string rollNumber;
	string contact;
	int age;
	Course** courseList;
	int totalCourse;
public:
	void ReadDataFromFile(ifstream& file)
	{
		string temp;
		file >> temp;
		name = temp;
		name += " ";
		file >> temp;
		name += temp;
		file >> rollNumber;
		file >> contact;
		file >> age;
	}
	void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Roll Number: " << rollNumber << endl;
		cout << "Contact: " <<contact << endl;
		cout << "Age: " << age << endl;
	}
};
class Flex
{
	Student** studentList;
	int totalStudents;
	Course** courseList;
	int totalCourses;
public:
	Flex()
	{
		totalStudents = totalCourses = 0;
		studentList = 0;
		courseList = 0;
	}
	void CalculateTotalstudents()
	{
		ifstream file;
		string line;
		file.open("students.txt");
		while (getline(file,line))
		{
			totalStudents++;
		}
	}
	void ReadStudentsFromFile()
	{
		CalculateTotalstudents();
		ifstream file;
		file.open("students.txt");
		studentList = new Student * [totalStudents];
		for (int i = 0;i < totalStudents;i++)
		{
			studentList[i] = new Student;
			studentList[i]->ReadDataFromFile(file);
		}
	}
	void Print()
	{
		cout << "------------------StudentList----------------\n";
		for (int i = 0;i < totalStudents;i++)
		{
			studentList[i]->Print();
		}
	}
	bool Authentication()
	{
		string domain;
		cout << "Enter your domain" << endl;
		cin >> domain;
		if (domain == "NU" || domain == "FAST" || domain == "nu")
		{
			return true;
		}
		return false;
	}
	void DisplayMenu()
	{
		int choice;
		
	}
};
void main()
{
	Flex obj;
	if (obj.Authentication())
	{
		cout << "         Welcome\n";
		cout << "Fetching Data";
		for (int i = 0;i < 5;i++)
		{
			cout << ". ";
			Sleep(100);
		}
		system("cls");
		cout << "         Welcome\n";
		obj.ReadStudentsFromFile();
		obj.Print();
	}
}