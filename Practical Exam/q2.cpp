#include <iostream>
using namespace std;

class Car
{
	private:
	
	string Model;
	int Year;
	int Speed;
	
	public:
	 void set(string M,int Y,int S)
	{
		Model = M;
		Year = Y;
		Speed = S;
	}
	void dispaly()
	{
		cout << "Model: " << Model << endl;
		cout << "Year: " << Year << endl;
		cout << "Speed: " << Speed << endl;
	}
};

int main()
{
	
	 Car C;
    C.set("i20",2023,130);
    C.dispaly();
	
	
	
	return 0;	
}