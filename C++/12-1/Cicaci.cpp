#include "Cicaci.h"
#include <time.h>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

Cicaci::Cicaci() : Zivotno(){}

Cicaci::Cicaci(char pol, string ime, 
int denRagjanje, int mesecRagjanje, int godinaRagjanje,
int denDonesuvanje, int mesecDonesuvanje, int godinaDonesuvnje,
int denVakcinacija, int mesecVakcinacija, int godinaVakcinacija,
char Prezivar
) : Zivotno(pol, ime, denRagjanje, mesecRagjanje, godinaRagjanje, denDonesuvanje, mesecDonesuvanje, godinaDonesuvnje, denVakcinacija, mesecVakcinacija, godinaVakcinacija){
    this->Prezivar = Prezivar;
}

void Cicaci::Prikazi_Podatoci(){
    cout<<"\nIme: "<<getIme()<<", Pol: "<<getPol()<<endl;
    cout<<"Datum na ragjanje: "; getDatumRagjanje().print();
    cout<<"Datum na donesuvanje vo zoo: "; getDatumDonesuvanje().print();
    cout<<"Datum na posledna vakcinacija: "; getDatumVakcinacija().print();
    cout<<"Dali e prezivar: "; getPrezivar(); cout<<"\n"<<endl;
}

Cicaci Cicaci::postavi(){
    char pol, Prezivar;
    string ime;
    int denRagjanje, mesecRagjanje, godinaRagjanje, 
    denDonesuvanje, mesecDonesuvanje, godinaDonesuvnje, 
    denVakcinacija, mesecVakcinacija, godinaVakcinacija;
    cout<<"Pol ('m' za masko, 'z' za zensko): ";  
    cin>>pol;
    cout<<"Ime (do 20 karakteri): "; cin.sync(); getline(cin, ime);
    cout<<"Datum na ragjanje (den mesec godina): "; 
    cin>>denRagjanje; cin>>mesecRagjanje; cin>>godinaRagjanje;
    cout<<"Datum na donesuvanje vo zoo (den mesec godina): "; 
    cin>>denDonesuvanje; cin>>mesecDonesuvanje; cin>>godinaDonesuvnje;
    cout<<"Datum na posledna vakcinacija (den mesec godina): "; 
    cin>>denVakcinacija; cin>>mesecVakcinacija; cin>>godinaVakcinacija;
    cout<<"Dali e prezivar (d/n): "; cin>>Prezivar;

    return Cicaci(pol, ime, 
    denRagjanje, mesecRagjanje, godinaRagjanje, 
    denDonesuvanje, mesecDonesuvanje, godinaDonesuvnje, 
    denVakcinacija, mesecVakcinacija, godinaVakcinacija,
    Prezivar);
}

bool Cicaci::Presmetaj_vakcinacija(){
    time_t now = time(0);

    tm tm{};
    tm.tm_year = getDatumVakcinacija().getGodina()-1900;
    tm.tm_mon = getDatumVakcinacija().getMesec()-1;
    tm.tm_mday = getDatumVakcinacija().getDen();
    time_t t = mktime(&tm);

    if(difftime(now, t)>31536000){ // ako datumot na posledna vakcinacija e pomal od 1 godina
      return true;
    }

    return false;
}

char Cicaci::getPrezivar(){return this->Prezivar;}
void Cicaci::setPrezivar(char Prezivar){this->Prezivar = Prezivar;}