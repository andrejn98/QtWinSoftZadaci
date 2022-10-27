#ifndef PANTOLONI_H
#define PANTOLONI_H

#include "Datum.h"
#include "artikl.h"

class pantoloni : public artikl{
    public:
        pantoloni();
        pantoloni(string, int, int, int, int, int, int, int, int);
        void Prikazi_Podatoci();
        pantoloni postavi();
        bool Presmetaj_nabavka();
        Datum getDatum_na_sledna_nabavka();
        void setDatum_na_sledna_nabavka(int, int, int);
    private:
        Datum Datum_na_sledna_nabavka;
};

#endif