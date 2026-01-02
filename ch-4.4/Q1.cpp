#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
private:
	int Roll;
	float Gpa;
	string Name;

public:
	// Default Constructor
	Student()
	{
		Roll = 0;
		Gpa = 0.0;
		Name = "not set";
		
		 cout << "default Constructor Called" << endl;
	}

	// Parameterized Constructor
	Student(int r, float g, string n)
	{
		Roll = r;
		Gpa = g;
		Name = n;
		
		 cout << "parameterized Constructor Called" << endl;
	}

	// Copy Constructor
	Student(const Student &s)
	{
		Roll = s.Roll;
		Gpa = s.Gpa;
		Name = s.Name;
		
		 cout << "Copy Constructor Called" << endl;
	}

	// Getter methods
	int GetRoll() const
	{
		return Roll;
	}

	float GetGpa() const
	{
		return Gpa;
	}

	string GetName() const
	{
		return Name;
	}

	void display() const
	{
		cout << "Name: " << Name
			 << "Roll No: " << Roll
			 << "GPA: " << Gpa << endl;
	}

	~Student()
	{
		cout <<"\ndestructure called"<<endl;
	}
};

class StudentRecordManagement
{
private:
	vector<Student> students;   

public:
	void addStudent(const Student &s)
	{
		students.push_back(s);
		cout << "Student Data Added" << endl;
	}

	void displayAllData()
	{
		if (students.empty())
		{
			cout << "No Student Records Available" << endl;
		}
		else
		{
			for (int i = 0; i < students.size(); i++)
			{
				students[i].display();
			}
		}
	}
	 void SearchByRoll(int roll)
	{
		for (int i = 0; i < students.size(); i++)
		{
			if (students[i].GetRoll() == roll)
			{
				cout << "Student Found :" << endl;
				students[i].display();
				return;
			}
		}

		cout << "Student with Roll No " << roll << " not found." << endl;
	}
};

int main()
{
	Student s1(1, 8.3, "Ankit ");
	Student s2(2, 7.6, "Dharmik ");
	Student s3(3, 6.5, "Amit ");

	StudentRecordManagement manager;

	manager.addStudent(s1);
	manager.addStudent(s2);
	manager.addStudent(s3);

	manager.displayAllData();
	
	manager.SearchByRoll(2);

	return 0;
}
