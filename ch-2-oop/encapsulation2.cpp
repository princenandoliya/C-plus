#include <iostream>
using namespace std;

class men{
public:
    string Name;

public:
    void setName(string n){
        Name = n;
    }

    void showName(){
        cout << "Name : " << Name << endl;
    }
};

int main(){
    men r1;
    r1.setName("prince");
    r1.showName();

    men r2;
    r2.setName("dharmik");
    r2.showName();

    return 0;
}