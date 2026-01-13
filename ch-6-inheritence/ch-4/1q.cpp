#include <iostream>
using namespace std;

class Admin
{
private:
    double total_annual_revenue;
    bool can_terminate;


protected:
    double manager_salary;
    double employee_salary;

public:
    string company_name;
    int total_staff;

    Admin()
    {
        company_name = "Red & white PVT LTD";
        manager_salary = 55000;
        employee_salary = 35000;
        total_staff = 100;
        total_annual_revenue = 500000;
        can_terminate = true;
    }


    virtual void myAccess()
    {
        cout << "\n ===== Admin Details ====="<<endl;
        cout << "Company Name   : " << company_name << endl;
        cout << "Manager Salary : " << manager_salary<< endl;
        cout << "Employee Salary: " << employee_salary<< endl;
        cout << "Total Staff    : " << total_staff<< endl;
        cout << "Annual Revenue : " << total_annual_revenue<< endl;
        cout << "Can terminate    : " << can_terminate<< endl;

        
    }
};

class Manager : public Admin
{
public:
    void myAccess() 
    {
        cout << "\n===== Manager Details ====="<<endl;
       cout << "Company Name   : " << company_name << endl;
        cout << "Manager Salary : " << manager_salary<< endl;
        cout << "Employee Salary: " << employee_salary<< endl;
        cout << "Total Staff    : " << total_staff<< endl; 
    }
};

class Employee : public Manager
{
public:
    void myAccess() 
    {
        cout << "\n===== Employee Details ====="<<endl;
        cout << "Company Name   : " << company_name << endl;
        cout << "Employee Salary: " << employee_salary<< endl;
        cout << "Total Staff    : " << total_staff<< endl;
    }
};

int main()
{
    Admin admin;
    admin.myAccess();

    Manager manager;
    manager.myAccess();

    Employee employee;
    employee.myAccess();

    return 0;
}