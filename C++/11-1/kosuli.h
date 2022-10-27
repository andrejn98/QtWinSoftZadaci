#ifndef KOSULI_H
#define KOSULI_H

#include "artikl.h"

class kosuli : public artikl{
    public:
        kosuli();
        kosuli(string, int, int, int, int, int);
        void Prikazi_Podatoci();
        bool Presmetaj_nabavka();
        kosuli postavi();
};

#endif