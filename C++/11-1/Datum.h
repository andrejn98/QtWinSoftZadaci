#ifndef DATUM_H
#define DATUM_H
#include <string>
#include <iostream>

class Datum {
    public:
        Datum();
        Datum(int , int , int);
        int getDen();
        int getMesec();
        int getGodina();
        void print();
    private:
        int den;
        int mesec; 
        int godina;
};

#endif
