#include <iostream>
#include <cmath>
#include <iomanip>

using std::setprecision;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;

int main(){    
    
    int n,m;
    cout<<"Vnesete broj na elementi: "; cin>>n;
    cout<<"Vneste sirina na koloni: "; cin>>m;

    double rootI;
    cout.precision(3);

    for(int i=1;i<n;++i){
        cout<<left<<setw(m)<<i<<setw(m)<<pow(i, 2)<<setw(m)<<sqrt(i)<<setw(m)<<cbrt(i)<<endl;
    }
    
    return 0;
}