#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "Dropki.h"

Dropki::Dropki(){
    imenitel=broitel=1;
}

Dropki::Dropki(int broitel, int imenitel){
    if(imenitel!=0){
        this->broitel=broitel;
        this->imenitel=imenitel;
    }else{
        cout<<"So 0 ne se deli!"<<endl;
        this->imenitel = this->broitel=1;
    }
}

int Dropki::getBroitel(){return broitel;}
int Dropki::getImenitel(){return imenitel;}

//za reducirana forma
int findGCD(int a, int b) {
   if (b == 0)
      return a;
      return findGCD(b, a % b);
}
void lowestFraction(int &num1, int &num2){
    int denom;
    denom = findGCD(num1,num2);
    num1/=denom;
    num2/=denom;
}

void Dropki::sobiranje(Dropki dropka){
    int imenitel1=findGCD(this->getImenitel(), dropka.getImenitel());

    imenitel1=(this->getImenitel()*dropka.getImenitel())/imenitel1;

    int broitel1 = this->getBroitel()*(imenitel1/this->getImenitel())+
                dropka.getBroitel()*(imenitel1/dropka.getImenitel());

    lowestFraction(broitel1, imenitel1);
    cout<<"Sobiranje: "<<broitel1<<"/"<<imenitel1<<endl;
}

void Dropki::odzemanje(Dropki dropka){
    int imenitel1=findGCD(this->getImenitel(), dropka.getImenitel());

    imenitel1=(this->getImenitel()*dropka.getImenitel())/imenitel1;

    int broitel1 = this->getBroitel()*(imenitel1/this->getImenitel())-
                dropka.getBroitel()*(imenitel1/dropka.getImenitel());

    lowestFraction(broitel1, imenitel1);
    cout<<"Odzemanje: "<<broitel1<<"/"<<imenitel1<<endl;
}

void Dropki::mnozhenje(Dropki dropka){
    int x,y;
    x = this->getBroitel()*dropka.getBroitel();
    y = this->getImenitel()*dropka.getImenitel();
    lowestFraction(x, y);
    cout<<"Mnozhenje: "<<x<<"/"<<y<<endl;
}

void Dropki::delenje(Dropki dropka){
    int x,y;
    x = this->getBroitel()*dropka.getImenitel();
    y = this->getImenitel()*dropka.getBroitel();
    lowestFraction(x, y);
    cout<<"Delenje: "<<x<<"/"<<y<<endl;
}

void Dropki::pechatenjeVoString(){
    cout<<" vo dropka: "<<getBroitel()<<"/"<<getImenitel()<<endl;
}

void Dropki::pechatenjeVoDouble(){
    cout<<" vo realen broj: "<<(double)getBroitel()/getImenitel()<<endl;
}
