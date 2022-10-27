#ifndef STEDAC_H
#define DROPKI_H
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Dropki {
    public:
        Dropki();
        Dropki(int, int);
        ~Dropki();
        int getBroitel();
        int getImenitel();
        void pechatenjeVoString();
        void pechatenjeVoDouble();
        Dropki operator+(Dropki dropka2);
        Dropki operator-(Dropki dropka2);
        Dropki operator*(Dropki dropka2);
        Dropki operator/(Dropki dropka2);
        Dropki operator+(int broj);
        Dropki operator-(int broj);
        Dropki operator*(int broj);
        Dropki operator/(int broj);
    private:
        int broitel; 
        int imenitel;
};

#endif
