#include "Ptici.h"
#include <time.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

Ptici::Ptici() : Zivotno(){}

Ptici::Ptici(char pol, string ime, 
int denRagjanje, int mesecRagjanje, int godinaRagjanje,
int denDonesuvanje, int mesecDonesuvanje, int godinaDonesuvnje,
int denVakcinacija, int mesecVakcinacija, int godinaVakcinacija,
char Letac
) : Zivotno(pol, ime, denRagjanje, mesecRagjanje, godinaRagjanje, denDonesuvanje, mesecDonesuvanje, godinaDonesuvnje, denVakcinacija, mesecVakcinacija, godinaVakcinacija){
    this->Letac = Letac;
}

void Ptici::Prikazi_Podatoci(){
    cout<<"\nIme: "<<getIme()<<", Pol: "<<getPol()<<endl;
    cout<<"Datum na ragjanje: "; getDatumRagjanje().print();
    cout<<"Datum na donesuvanje vo zoo: "; getDatumDonesuvanje().print();
    cout<<"Datum na posledna vakcinacija: "; getDatumVakcinacija().print();
    cout<<"Dali e letac: "<<getLetac()<<"\n"<<endl;
}

Ptici Ptici::postavi(){
    char pol, Letac;
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
    cout<<"Dali e letac (d/n): "; cin>>Letac;

    return Ptici(pol, ime, 
    denRagjanje, mesecRagjanje, godinaRagjanje, 
    denDonesuvanje, mesecDonesuvanje, godinaDonesuvnje, 
    denVakcinacija, mesecVakcinacija, godinaVakcinacija,
    Letac);
}

bool Ptici::Presmetaj_vakcinacija(){
    time_t now = time(0);

    tm tm{};
    tm.tm_year = getDatumVakcinacija().getGodina()-1900;
    tm.tm_mon = getDatumVakcinacija().getMesec()-1;
    tm.tm_mday = getDatumVakcinacija().getDen();
    time_t t = mktime(&tm);

    if(difftime(now, t)>15780000){ // ako datumot na posledna vakcinacija e pomal od 6 meseci
      return true;
    }

    return false;
}

char Ptici::getLetac(){return this->Letac;}
void Ptici::setLetac(char Letac){this->Letac = Letac;}