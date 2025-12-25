#include <iostream>
using namespace std;

class Men
{
	public:
	void name()
	{
		cout<< "nandoliya" <<endl;
	}
};

class Student :public Men
{
	public:
	void name()
	{
		cout << "prince" <<endl;
	}
};

int main(){
	
	Student r1;
	r1.name();	
	
	return 0;
}