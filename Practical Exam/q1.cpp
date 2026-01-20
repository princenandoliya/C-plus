#include <iostream>

using namespace std;


class Student
{
	private:
	
	string  Name;
	int RollNumber;
	
	public:
	Student(string n,int r)
	{
		Name = n;
		RollNumber = r;
	}
	
	void dispaly()
	{
		cout <<"Name: " <<Name << "Roll No: " <<RollNumber <<endl;
	}
	
};


int main()
{
    Student students[2]{
        Student("Prince   ", 50),
        Student("Ankit  ", 51),
    };

    for (int i = 0; i < 2; i++)
    {
        students[i].dispaly();
    }

    return 0;
}