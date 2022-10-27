#include <iostream>
#include "Covek.h"

Covek::Covek(){}

Covek::Covek(string ime, string prezime, string adresa, int telefon){
    this->ime = ime, this->prezime = prezime, this->adresa = adresa, this->telefon = telefon;
}

string Covek::getIme(){return this->ime;}
string Covek::getPrezime(){return this->prezime;}
string Covek::getAdresa(){return this->adresa;}
int Covek::getTelefon(){return this->telefon;}