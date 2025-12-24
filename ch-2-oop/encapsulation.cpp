#include <iostream>
using namespace std;
class Student
{
	private:
	
	int roll;
	int Marks;	
	
	public:
	 void setData(int r,int m)
	 {
	 	roll =r;
		Marks =m;
	 }
	 void showData(){
	 	cout << "roll no:\n " <<roll <<endl;
		cout << "marks:\n "<<Marks <<endl;
	 }
};
int main()
{
	Student r1;
	 r1.setData(1,70);
	 
	 r1.showData();	
	
	
	return 0;
	
}