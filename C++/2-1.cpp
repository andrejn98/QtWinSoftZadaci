#include <iostream>

using std::cout;
using std::endl;

template < class T >
T min( T x, T y )
{
    if ( x > y )
        return y;
    else 
        return x;
}

int main()
{
    int x=3, y=2;
    double x1=3.5, y1=2.7;
    char x2='a', y2='b';

    cout << ::min(x, y) << endl << ::min(x1, y1) << endl << ::min(x2, y2);

    return 0;
}