#include <iostream>
using namespace std;

class Student{
	public:
	int Roll;
	
	void setRoll(int r)
	{
		Roll =r;
	}
};

class Marks :public Student{
	public:
	int Marks;	
	void setMarks(int m)
	{
		Marks =m;
	}
	void showData()
	{
		cout << "Roll no "<<Roll<<endl;
		cout << "Marks "<<Marks<<endl;
	}
};

int main(){
	
	Marks r1;
	r1.setRoll(6);
	r1.setMarks(95);
	
	r1.showData();		
	return 0;	
}