#ifndef STEDAC_H
#define STEDAC_H
#include <iostream>
#include "Covek.h"

class Stedac {
    public:
        Stedac();
        Stedac(int, int, string, string, string, int);
        ~Stedac();
        static int getKamata();
        static int getBrojStedaci();
        Covek getLice();
        int getBilans();
        int getKredit();
        void print();
    private:
        static int kamata;
        static int brojStedaci;
        Covek lice;
        int bilans; 
        int kredit;
};

#endif
