#include "Vlekaci.h"
#include <ctime>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

Vlekaci::Vlekaci() : Zivotno(){}

Vlekaci::Vlekaci(char pol, string ime, 
int denRagjanje, int mesecRagjanje, int godinaRagjanje,
int denDonesuvanje, int mesecDonesuvanje, int godinaDonesuvnje,
int denVakcinacija, int mesecVakcinacija, int godinaVakcinacija,
int denSlednaVakcinacija, int mesecSlednaVakcinacija, int godinaSlednaVakcinacija
) : Zivotno(pol, ime, denRagjanje, mesecRagjanje, godinaRagjanje, denDonesuvanje, mesecDonesuvanje, godinaDonesuvnje, denVakcinacija, mesecVakcinacija, godinaVakcinacija),
Datum_na_sledna_vakcinacija(denSlednaVakcinacija, mesecSlednaVakcinacija, godinaSlednaVakcinacija){}

void Vlekaci::Prikazi_Podatoci(){
    cout<<"\nIme: "<<getIme()<<", Pol: "<<getPol()<<endl;
    cout<<"Datum na ragjanje: "; getDatumRagjanje().print();
    cout<<"Datum na donesuvanje vo zoo: "; getDatumDonesuvanje().print();
    cout<<"Datum na posledna vakcinacija: "; getDatumVakcinacija().print();
    cout<<"Datum na sledna vakcinacija: "; getDatumSlednaVakcinacija().print(); cout<<"\n"<<endl;
}

Vlekaci Vlekaci::postavi(){
    char pol;
    string ime;
    int denRagjanje, mesecRagjanje, godinaRagjanje, 
    denDonesuvanje, mesecDonesuvanje, godinaDonesuvnje, 
    denVakcinacija, mesecVakcinacija, godinaVakcinacija,
    denSlednaVakcinacija, mesecSlednaVakcinacija, godinaSlednaVakcinacija;
    cout<<"Pol ('m' za masko, 'z' za zensko): ";  
    cin>>pol;
    cout<<"Ime (do 20 karakteri): "; cin.sync(); getline(cin, ime);
    cout<<"Datum na ragjanje (den mesec godina): "; 
    cin>>denRagjanje; cin>>mesecRagjanje; cin>>godinaRagjanje;
    cout<<"Datum na donesuvanje vo zoo (den mesec godina): "; 
    cin>>denDonesuvanje; cin>>mesecDonesuvanje; cin>>godinaDonesuvnje;
    cout<<"Datum na posledna vakcinacija (den mesec godina): "; 
    cin>>denVakcinacija; cin>>mesecVakcinacija; cin>>godinaVakcinacija;
    cout<<"Datum na sledna vakcinacija (den mesec godina): "; 
    cin>>denSlednaVakcinacija; cin>>mesecSlednaVakcinacija; cin>>godinaSlednaVakcinacija;

    return Vlekaci(pol, ime, 
    denRagjanje, mesecRagjanje, godinaRagjanje, 
    denDonesuvanje, mesecDonesuvanje, godinaDonesuvnje, 
    denVakcinacija, mesecVakcinacija, godinaVakcinacija,
    denSlednaVakcinacija, mesecSlednaVakcinacija, godinaSlednaVakcinacija);
}

bool Vlekaci::Presmetaj_vakcinacija(){
    time_t now = time(0);
    tm* datum = localtime(&now);

    tm tm{};
    tm.tm_year = getDatumSlednaVakcinacija().getGodina()-1900;
    tm.tm_mon = getDatumSlednaVakcinacija().getMesec()-1;
    tm.tm_mday = getDatumSlednaVakcinacija().getDen();
    time_t t = mktime(&tm);

    if(difftime(now, t)>0){ // ako datumot na slednata vakcinacija e pomal od denesniot
      return true;
    }

    tm.tm_year = getDatumVakcinacija().getGodina()-1900;
    tm.tm_mon = getDatumVakcinacija().getMesec()-1;
    tm.tm_mday = getDatumVakcinacija().getDen();
    t = mktime(&tm);

    if(difftime(now, t)>21040000){ // ako datumot na posledna vakcinacija e pomal od 8 meseci
      return true;
    }

    return false;
}

Datum Vlekaci::getDatumSlednaVakcinacija(){return this->Datum_na_sledna_vakcinacija;}