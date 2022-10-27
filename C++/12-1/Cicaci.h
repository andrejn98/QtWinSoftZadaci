#ifndef CICACI_H
#define CICACI_H

#include "Zivotno.h"

class Cicaci : public Zivotno{
    public:
        Cicaci();
        Cicaci(char, string,
         int, int, int, int, int, int, int, int, int, char);
        void vnesi_podatoci();
        void Prikazi_Podatoci();
        Cicaci postavi();
        bool Presmetaj_vakcinacija();
        char getPrezivar();
        void setPrezivar(char);
    private:
        char Prezivar;
};

#endif