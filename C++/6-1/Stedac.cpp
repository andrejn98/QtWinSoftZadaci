#include <iostream>
#include "Stedac.h"

using std::cout;
using std::cin;
using std::endl;

Stedac::Stedac() : lice(){}

int Stedac::brojStedaci=0;
int Stedac::kamata=0;

Stedac::Stedac(int bilans, int kredit, string ime, string prezime, string adresa, int telefon) : 
lice(ime, prezime, adresa, telefon){
    this->bilans = bilans, this->kredit = kredit;

    ++brojStedaci;
    kamata = 15;
}

Stedac::~Stedac(){
    cout<<"Izbrishan/a e " << getLice().getIme()<<endl;
    --brojStedaci;
}

void Stedac::print(){
    cout << getLice().getIme() << " " << getLice().getPrezime() << ", tel: " <<
    getLice().getTelefon() << ", bilans: " << getBilans() << ", kredit: " << getKredit() << endl;
}
int Stedac::getKamata(){return kamata;}
int Stedac::getBrojStedaci(){return brojStedaci;}
Covek Stedac::getLice(){return this->lice;}
int Stedac::getBilans(){return this->bilans;}
int Stedac::getKredit(){return this->kredit;}