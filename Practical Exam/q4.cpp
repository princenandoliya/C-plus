#include <iostream>
using namespace std;

class Device
{
public:
     int calculateDiscount()
    {
        return 0;
    }

};

class Tv:public Device{
    public:

    virtual int calculateDiscount(){
        return 4000;
    }
};

class Tablet:public Device{
    public:

    virtual int calculateDiscount(){
        return 3500;

        
    }
};


int main()
{

    Tv T;
    Tablet b;

    cout <<T.calculateDiscount()<<endl;
    cout <<b.calculateDiscount()<<endl;
    
   

    return 0;
}