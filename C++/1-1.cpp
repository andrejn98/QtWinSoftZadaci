#include <iostream>

using std::cout;
using std::cin;
using std::endl;

inline double circleArea( double radius ) { return 3.14*radius*radius; }

int main()
{
    cout<<"Vnesete radius na krug: "<<endl;
    double r;
    cin>>r;
    cout<<"Povrshinata na krugot e: "<<circleArea(r);

    return 0;
}