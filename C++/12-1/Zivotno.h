#ifndef ZIVOTNO_H
#define ZIVOTNO_H

#include <string>
#include "Datum.h"

using std::string;

class Zivotno {
    public:
        Zivotno();
        Zivotno(char, string,
         int, int, int, int, int, int, int, int, int);
        void vnesi_podatoci();
        void Prikazi_Podatoci();
        virtual bool Presmetaj_vakcinacija();
        Datum getDatumRagjanje();
        Datum getDatumDonesuvanje();
        Datum getDatumVakcinacija();
        char getPol();
        string getIme();
    private:
        Datum Datum_na_ragjanje;
        Datum Datum_na_donesuvanje_vo_zoo;
        char pol;
        string ime;
        Datum Datum_na_posledna_vakcinacija;
};

#endif