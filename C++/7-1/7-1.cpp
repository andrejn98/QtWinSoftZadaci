#include <iostream>
#include "Dropki.h"

int main(){
    Dropki d(3, 4), d1(2, 0), d3; // d1 ke bide 2/1 zaradi proverkata za 0

    cout<<"Dropka 1"; d.pechatenjeVoString();
    cout<<"Dropka 1"; d.pechatenjeVoDouble();
    cout<<"Dropka 2"; d1.pechatenjeVoString();
    cout<<"Dropka 2"; d1.pechatenjeVoDouble();

    d3=d+d1;
    cout<<"Dropka 1 + Dropka 2 "; d3.pechatenjeVoString();
    cout<<"Dropka 1 + Dropka 2 "; d3.pechatenjeVoDouble();
    d3=d-d1;
    cout<<"Dropka 1 - Dropka 2 "; d3.pechatenjeVoString();
    cout<<"Dropka 1 - Dropka 2 "; d3.pechatenjeVoDouble();
    d3=d*d1;
    cout<<"Dropka 1 * Dropka 2 "; d3.pechatenjeVoString();
    cout<<"Dropka 1 * Dropka 2 "; d3.pechatenjeVoDouble();
    d3=d/d1;
    cout<<"Dropka 1 / Dropka 2 "; d3.pechatenjeVoString();
    cout<<"Dropka 1 / Dropka 2 "; d3.pechatenjeVoDouble();

    d3=d+2;
    cout<<"Dropka 1 + 2"; d3.pechatenjeVoString();
    cout<<"Dropka 1 + 2 "; d3.pechatenjeVoDouble();
    d3=d-2;
    cout<<"Dropka 1 - 2"; d3.pechatenjeVoString();
    cout<<"Dropka 1 - 2 "; d3.pechatenjeVoDouble();
    d3=d*2;
    cout<<"Dropka 1 * 2"; d3.pechatenjeVoString();
    cout<<"Dropka 1 * 2 "; d3.pechatenjeVoDouble();
    d3=d/2;
    cout<<"Dropka 1 / 2"; d3.pechatenjeVoString();
    cout<<"Dropka 1 / 2 "; d3.pechatenjeVoDouble();

    return 0;
}