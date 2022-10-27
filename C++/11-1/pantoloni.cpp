#include "pantoloni.h"
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

pantoloni::pantoloni(){}

pantoloni::pantoloni(string Ime_na_artikl, int golemina, int cena, int denDonesen, int mesecDonesen, int godinaDonesen, int denSlednaNabavka, int mesecSlednaNabavka, int godinaSlednaNabavka)
: artikl(Ime_na_artikl, golemina, cena, denDonesen, mesecDonesen, godinaDonesen),
Datum_na_sledna_nabavka(denSlednaNabavka, mesecSlednaNabavka, godinaSlednaNabavka){}
    

void pantoloni::Prikazi_Podatoci(){
    cout<<"Ime: "<<getImeNaArtikl()<<", Golemina: "<<getGolemina()<<", Cena: "<<getCena();
    cout<<", Donesen vo prodavnica: "; getDatumDonesen().print();
    cout<<"Sledna nabavka: "; getDatum_na_sledna_nabavka().print();
}

pantoloni pantoloni::postavi(){
    string Ime_na_artikl;
    int golemina, cena, denDonesen, mesecDonesen, godinaDonesen, denSlednaNabavka, mesecSlednaNabavka, godinaSlednaNabavka;
    cout<<"Vnesi ime: " <<endl; cin>>Ime_na_artikl;
    cout<<"Vnesi golemina: " <<endl; cin>>golemina;
    cout<<"Vnesi cena: " <<endl; cin>>cena;
    cout<<"Vnesi datum koga e donesen(den mesec godina): " <<endl; cin>>denDonesen; cin>>mesecDonesen; cin>>godinaDonesen;
    cout<<"Vnesi datum koga e slednata nabavka(den mesec godina): " <<endl; cin>>denSlednaNabavka; cin>>mesecSlednaNabavka; cin>>godinaSlednaNabavka;
    return pantoloni(Ime_na_artikl, golemina, cena, denDonesen, mesecDonesen, godinaDonesen, denSlednaNabavka, mesecSlednaNabavka, godinaSlednaNabavka);
}

bool pantoloni::Presmetaj_nabavka(){
    time_t now = time(0);
    tm* datum = localtime(&now);

    tm tm{};
    tm.tm_year = getDatum_na_sledna_nabavka().getGodina()-1900;
    tm.tm_mon = getDatum_na_sledna_nabavka().getMesec()-1;
    tm.tm_mday = getDatum_na_sledna_nabavka().getDen();
    time_t t = mktime(&tm);

    if(difftime(now, t)>0){ // ako datumot na slednata narachka e pomal od deneshniot
      return true;
    }

    tm.tm_year = getDatumDonesen().getGodina()-1900;
    tm.tm_mon = getDatumDonesen().getMesec()-1;
    tm.tm_mday = getDatumDonesen().getDen();
    t = mktime(&tm);

    if(difftime(now, t)>2630000){ // ako datumot koga e donesen e pomal od 1 mesec
      return true;
    }else return false;
}

Datum pantoloni::getDatum_na_sledna_nabavka(){return this->Datum_na_sledna_nabavka;}
void pantoloni::setDatum_na_sledna_nabavka(int den, int mesec, int godina){Datum(den, mesec, godina);}