#ifndef VLEKACI_H
#define VLEKACI_H

#include "Zivotno.h"

class Vlekaci : public Zivotno{
    public:
        Vlekaci();
        Vlekaci(char, string,
         int, int, int, int, int, int, int, int, int, int, int, int);
        void vnesi_podatoci();
        void Prikazi_Podatoci();
        Vlekaci postavi();
        bool Presmetaj_vakcinacija();
        Datum getDatumSlednaVakcinacija();
    private:
        Datum Datum_na_sledna_vakcinacija;
};

#endif