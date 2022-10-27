#ifndef ZIVOTNO_H
#define ZIVOTNO_H

#include "Datum.h"

class Zivotno {
    public:
        Zivotno();
        Zivotno(char, char, std::string,
         int, int, int, int, int, int, int, int, int);
        void vnesi_podatoci();
        void Prikazi_Podatoci();
        bool Presmetaj_vakcinacija();
        Datum getDatumRagjanje();
        Datum getDatumDonesuvanje();
        Datum getDatumVakcinacija();
        char getTip();
        char getPol();
        std::string getIme();
    private:
        Datum Datum_na_ragjanje;
        Datum Datum_na_donesuvanje_vo_zoo;
        char tip;
        char pol;
        std::string ime;
        Datum Datum_na_posledna_vakcinacija;
};

#endif