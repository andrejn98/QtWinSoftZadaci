#ifndef PTICI_H
#define PTICI_H

#include "Zivotno.h"

using std::string;

class Ptici : public Zivotno{
    public:
        Ptici();
        Ptici(char, string,
         int, int, int, int, int, int, int, int, int, char);
        void vnesi_podatoci();
        void Prikazi_Podatoci();
        Ptici postavi();
        bool Presmetaj_vakcinacija();
        char getLetac();
        void setLetac(char);
    private:
        char Letac;
};

#endif