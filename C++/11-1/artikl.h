#ifndef ARTIKL_H
#define ARTIKL_H
#include "Datum.h"

using std::string;

class artikl{
    public:
        artikl();
        artikl(string, int, int, int, int, int);
        void Prikazi_Podatoci();
        void Presmetaj_nabavka();
        string getImeNaArtikl();
        void setImeNaArtikl(string);
        int getGolemina();
        void setGolemina(int);
        int getCena();
        void setCena(int);
        Datum getDatumDonesen();
        void setDatumDonesen(int, int, int);
    private:
        string Ime_na_artikl;
        int golemina;
        int cena;
        Datum Donesen_vo_prodavnica;
};

#endif