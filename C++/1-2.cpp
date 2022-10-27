#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int trippleCallByValue( int count )
{
    return count = count*count*count;
}

int trippleCallByReference( int &count )
{
    return count = count*count*count;
}

int main()
{
    int count = 3;
    
    cout << "Vnesete vrednost za count: " << endl;
    cin >> count;

    cout << "count = " << trippleCallByReference(count)<< endl;
    cout << "count = " << trippleCallByValue(count)<< endl;
    
    return 0;
}