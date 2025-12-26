#include <iostream>

using namespace std;

class Student
{
	private:	
	int emp_id;
	string emp_name;
	int emp_age;
	string emp_role;
	int emp_salary;
	string emp_city;
	int emp_experience;
	string emp_company_name;	
	
	public:
	 void setdata(int id,string name,int age,string role,int salary,string city,int experience,string company_name)
	 {
	 	emp_id = id;
		emp_name = name;
		emp_age = age;
		emp_role = role;
		emp_salary = salary;
		emp_city = city;
		emp_experience = experience;
		emp_company_name = company_name;
	 }	 
	 
	 void getdata(int i)
	 {
	 	cout << "\n record of employees:"<<  i + 1 << endl;
		cout << "\n ID: "<< emp_id << endl;
		cout << "\n NAME: "<< emp_name << endl;
		cout << "\n AGE: "<< emp_age << endl;
		cout << "\n ROLE: "<<emp_role << endl;
		cout << "\n SALARY: "<<emp_salary <<endl;
		cout << "\n CITY: "<<emp_city <<endl;
		cout << "\n EXPERIENCE: "<<emp_experience <<endl;
		cout << "\n COMPANY_NAME: "<<emp_company_name <<endl;
	 }
};

int main()
{
	Student e[2];
	
	for(int i = 0;i < 2;i++)
	{
		int id,age,salary,experience;
		string name,role,city,company_name;
		
		cout << "Enter Detail of employees:"<< i + 1 <<endl;		
		
		cout <<"ID: ";
		cin >> id;	
			
		cout <<"NAME: ";
		cin >> name;
		
		cout <<"AGE: ";
		cin >> age;
		
		cout << "ROLE: ";
		cin >> role;
		
		cout << "SALARY: ";
		cin >> salary;
		
		cout << "CITY: ";
		cin >> city;
		
		cout << "EXPERIENCE: ";
		cin >> experience;
		
		cout << "COMPANY_NAME: ";
		cin >> company_name;
		
				e[i].setdata(id, name, age, role, salary, city, experience, company_name);	
	}
	
	for (int i = 0;i < 2;i++)
	{
		 e[i].getdata(i);
	}	
	
	return 0;
	
}