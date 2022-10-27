#include "Zivotno.h"
#include <ctime>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

Zivotno::Zivotno() : Datum_na_ragjanje(), Datum_na_donesuvanje_vo_zoo(), Datum_na_posledna_vakcinacija(){}

Zivotno::Zivotno(char pol, string ime, 
int denRagjanje, int mesecRagjanje, int godinaRagjanje,
int denDonesuvanje, int mesecDonesuvanje, int godinaDonesuvnje,
int denVakcinacija, int mesecVakcinacija, int godinaVakcinacija
) : 
Datum_na_ragjanje(denRagjanje, mesecRagjanje, godinaRagjanje), 
Datum_na_donesuvanje_vo_zoo(denDonesuvanje, mesecDonesuvanje, godinaDonesuvnje), 
Datum_na_posledna_vakcinacija(denVakcinacija, mesecVakcinacija, godinaVakcinacija){
    this->pol = pol, this->ime= ime;
}

void Zivotno::Prikazi_Podatoci(){
    cout<<"\nIme: "<<getIme()<<", Pol: "<<getPol()<<endl;
    cout<<"Datum na ragjanje: "; getDatumRagjanje().print();
    cout<<"Datum na donesuvanje vo zoo: "; getDatumDonesuvanje().print();
    cout<<"Datum na posledna vakcinacija: "; getDatumVakcinacija().print(); cout<<endl;
}

bool Zivotno::Presmetaj_vakcinacija(){
    return false;
}

Datum Zivotno::getDatumRagjanje(){return this->Datum_na_ragjanje;}
Datum Zivotno::getDatumDonesuvanje(){return this->Datum_na_donesuvanje_vo_zoo;}
Datum Zivotno::getDatumVakcinacija(){return this->Datum_na_posledna_vakcinacija;}
char Zivotno::getPol(){return this->pol;}
string Zivotno::getIme(){return this->ime;}