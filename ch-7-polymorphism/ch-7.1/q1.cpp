#include <iostream>
using namespace std;

class Calculate 
{
	public:
	
	void Calculator(int a, int b)
	{
		cout << "Division :"<< a/b << endl;
	}
	
	void Calculator(int a, int b,int c)
	{
		cout << "subtraction :"<< a-b-c << endl;
	}
	
	void Calculator(int a, int b,int c,int d)
	{
		cout << "multiplication :"<< a*b*c*d << endl;
	}
	
	void Calculator(int a, int b,int c,int d,int e)
	{
		cout << "addition :"<< a+b+c+d+e << endl;
	}
};



int main(){	
	
	Calculate obj;
	
	obj.Calculator(12,2);
	obj.Calculator(50,20,5);
	obj.Calculator(3,5,6,7);
	obj.Calculator(5,2,3,4,8);	
	
	
	
	return 0;
	
}