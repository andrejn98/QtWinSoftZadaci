#include <iostream>
#include "Stedac.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
    cout << "Broj na vraboteni: " << Stedac::getBrojStedaci() << endl;

    Stedac *s = new Stedac(1900, 3000, "Mitko", "Mitkovski", "Adresa1", 77777777);
    cout << "Vnes: "; s->print();
    
    Stedac *s1 = new Stedac(1900, 3000, "Ratko", "Ratkovski", "Adresa2", 78888888);
    cout << "Vnes: "; s1->print();
    
    cout << "Broj na stedaci, po vnesuvanje: " << Stedac::getBrojStedaci() << endl;

    Stedac *s2 = new Stedac(1900, 3000, "Ana", "Anovska", "Adresa3", 79999999);
    cout << "Vnes: "; s2->print();
    
    cout << "Broj na stedaci, po vnesuvanje: " << Stedac::getBrojStedaci() << endl;

    delete s;
    s = 0;
    delete s1;
    s1 = 0;
    delete s2;
    s1 = 0;

    cout << "Broj na stedaci po brishenje: " << Stedac::getBrojStedaci() << endl;

    return 0;
}