#include <iostream>

using namespace std;

class x
{
	protected:	
	int a,b,c;
};

class y :public  x
{
	public:
	void setData()
	{
		cout << "Enter  Number a:";
		cin >> a ;
		cin.ignore();
		
		cout << "Enter  Numbers b:";
		cin >> b ;
		cin.ignore();
		
		cout << "Enter  Numbers c:";
		cin >> c ;
		cin.ignore();
		
	}
	void getData()
	{
		int sum;
		sum = (a*a*a) + (b*b*b) + (c*c*c);
		cout <<"Sum Of Cubes =" <<sum <<endl;
	}
};

int main()
{
	y obj;
	obj.setData();
	obj.getData();	
	
	return 0;
	
}