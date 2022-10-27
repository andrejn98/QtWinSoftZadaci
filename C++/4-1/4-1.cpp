#include <iostream>

using std::cout;
using std::cin;

#include "Dropki.h"

int main(){
    Dropki d(3, 4), d1(2, 0); // d1 ke bide 1/1 zaradi proverkata za 0 

    cout<<"Dropka 1"; d.pechatenjeVoString();
    cout<<"Dropka 1"; d.pechatenjeVoDouble();
    cout<<"Dropka 2"; d1.pechatenjeVoString();
    cout<<"Dropka 2"; d1.pechatenjeVoDouble();
    d.sobiranje(d1);
    d.odzemanje(d1);
    d.mnozhenje(d1);
    d.delenje(d1);

    return 0;
}