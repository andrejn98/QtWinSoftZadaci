#include "kosuli.h"
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

kosuli::kosuli(){}

kosuli::kosuli(string Ime_na_artikl, int golemina, int cena, int denDonesen, int mesecDonesen, int godinaDonesen)
: artikl(Ime_na_artikl, golemina, cena, denDonesen, mesecDonesen, godinaDonesen){}

void kosuli::Prikazi_Podatoci(){
    cout<<"Ime: "<<getImeNaArtikl()<<", Golemina: "<<getGolemina()<<", Cena: "<<getCena();
    cout<<", Donesen vo prodavnica: "; getDatumDonesen().print();
}

kosuli kosuli::postavi(){
    string Ime_na_artikl;
    int golemina, cena, denDonesen, mesecDonesen, godinaDonesen;
    cout<<"Vnesi ime: " <<endl; cin>>Ime_na_artikl;
    cout<<"Vnesi golemina: " <<endl; cin>>golemina;
    cout<<"Vnesi cena: " <<endl; cin>>cena;
    cout<<"Vnesi datum koga e donesen(den mesec godina): " <<endl; cin>>denDonesen; cin>>mesecDonesen; cin>>godinaDonesen;
    return kosuli(Ime_na_artikl, golemina, cena, denDonesen, mesecDonesen, godinaDonesen);
}

bool kosuli::Presmetaj_nabavka(){
    time_t now = time(0);
    tm* datum = localtime(&now);

    tm tm{};
    tm.tm_year = getDatumDonesen().getGodina()-1900;
    tm.tm_mon = getDatumDonesen().getMesec()-1;
    tm.tm_mday = getDatumDonesen().getDen();
    time_t t = mktime(&tm);

    if(difftime(now, t)>0){ // ako datumot koga e donesen e pomal od deneshniot
      return true;
    }else return false;
}