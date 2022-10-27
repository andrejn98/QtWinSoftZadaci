#include <iostream>
#include <string>
#include <ctime>
#include "Zivotno.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Zivotno::Zivotno() : Datum_na_ragjanje(), Datum_na_donesuvanje_vo_zoo(), Datum_na_posledna_vakcinacija(){}

Zivotno::Zivotno(char tip, char pol, string ime, 
int denRagjanje, int mesecRagjanje, int godinaRagjanje,
int denDonesuvanje, int mesecDonesuvanje, int godinaDonesuvnje,
int denVakcinacija, int mesecVakcinacija, int godinaVakcinacija
) : 
Datum_na_ragjanje(denRagjanje, mesecRagjanje, godinaRagjanje), 
Datum_na_donesuvanje_vo_zoo(denDonesuvanje, mesecDonesuvanje, godinaDonesuvnje), 
Datum_na_posledna_vakcinacija(denVakcinacija, mesecVakcinacija, godinaVakcinacija){
    this->tip = tip, this->pol = pol, this->ime= ime;
}

void Zivotno::Prikazi_Podatoci(){
    cout<<"\nIme: "<<getIme()<<", Tip: "<<getTip()<<", Pol: "<<getPol()<<endl;
    cout<<"Datum na ragjanje: "; getDatumRagjanje().print();
    cout<<"Datum na donesuvanje vo zoo: "; getDatumDonesuvanje().print();
    cout<<"Datum na posledna vakcinacija: "; getDatumVakcinacija().print(); cout<<endl;
}

bool Zivotno::Presmetaj_vakcinacija(){
    time_t now = time(0);

    tm tm{};
    tm.tm_year = getDatumVakcinacija().getGodina()-1900;
    tm.tm_mon = getDatumVakcinacija().getMesec()-1;
    tm.tm_mday = getDatumVakcinacija().getDen();
    time_t t = mktime(&tm);

    if(getTip()=='c'){
        if(difftime(now, t)>31536000){ // ako datumot na posledna vakcinacija e pomal od 1 godina
            return true;
        }
    }else if(getTip()=='v'){
        if(difftime(now, t)>21040000){ // ako datumot na posledna vakcinacija e pomal od 8 meseci
            return true;
        }
    }else if(getTip()=='p'){
        if(difftime(now, t)>15780000){ // ako datumot na posledna vakcinacija e pomal od 6 meseci
            return true;
        }
    }

    return false;
}

Datum Zivotno::getDatumRagjanje(){return this->Datum_na_ragjanje;}
Datum Zivotno::getDatumDonesuvanje(){return this->Datum_na_donesuvanje_vo_zoo;}
Datum Zivotno::getDatumVakcinacija(){return this->Datum_na_posledna_vakcinacija;}
char Zivotno::getTip(){return this->tip;}
char Zivotno::getPol(){return this->pol;}
string Zivotno::getIme(){return this->ime;}