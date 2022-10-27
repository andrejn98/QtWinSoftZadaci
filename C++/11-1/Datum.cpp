#include "Datum.h"

using std::cout;
using std::cin;
using std::endl;

Datum::Datum(){}

Datum::Datum(int den, int mesec, int godina){
    this->den = den, this->mesec = mesec, this->godina = godina;
}

void Datum::print(){
    cout<<getDen()<<"/"<<getMesec()<<"/"<<getGodina()<<endl;
}

int Datum::getDen(){return this->den;}
int Datum::getMesec(){return this->mesec;}
int Datum::getGodina(){return this->godina;}