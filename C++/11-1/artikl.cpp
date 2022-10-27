#include "artikl.h"

using std::cout;
using std::cin;
using std::endl;

artikl::artikl(){}

artikl::artikl(string Ime_na_artikl, int golemina, int cena, int den, int mesec, int godina)
: Donesen_vo_prodavnica(den, mesec, godina){
    this->Ime_na_artikl = Ime_na_artikl, 
    this->golemina = golemina, 
    this->cena= cena;
}

void artikl::Prikazi_Podatoci(){
    cout<<"Ime: "<<getImeNaArtikl()<<", Golemina: "<<getGolemina()<<", Cena: "<<getCena();
    cout<<", Donesen vo prodavnica: "; getDatumDonesen().print();
}

void artikl::Presmetaj_nabavka(){}

string artikl::getImeNaArtikl(){return this->Ime_na_artikl;}
void artikl::setImeNaArtikl(string Ime_na_artikl){this->Ime_na_artikl=Ime_na_artikl;}

int artikl::getGolemina(){return this->golemina;}
void artikl::setGolemina(int golemina){this->golemina=golemina;}

int artikl::getCena(){return this->cena;}
void artikl::setCena(int cena){this->cena=cena;}

Datum artikl::getDatumDonesen(){return this->Donesen_vo_prodavnica;}
void artikl::setDatumDonesen(int den, int mesec, int godina){Datum(den, mesec, godina);}