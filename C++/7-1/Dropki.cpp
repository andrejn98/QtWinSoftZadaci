#include "Dropki.h"

Dropki::Dropki(){}

Dropki::Dropki(int broitel, int imenitel){
    if(imenitel!=0)
        this->broitel = broitel, this->imenitel = imenitel;
    else{
        cout<<"So 0 ne se deli!"<<endl;
        this->broitel=broitel, this->imenitel=1;
    }
}

Dropki::~Dropki(){}

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

Dropki Dropki::operator+(Dropki dropka2) {
    Dropki tmp;
    int imenitel1=findGCD(this->getImenitel(), dropka2.getImenitel());

    imenitel1=(this->getImenitel()*dropka2.getImenitel())/imenitel1;

    int broitel1 = this->getBroitel()*(imenitel1/this->getImenitel())+
                dropka2.getBroitel()*(imenitel1/dropka2.getImenitel());

    lowestFraction(broitel1, imenitel1);

    tmp.broitel = broitel1;
    tmp.imenitel = imenitel1;
    return tmp;
}

Dropki Dropki::operator-(Dropki dropka2) {
    Dropki tmp;
    int imenitel1=findGCD(this->getImenitel(), dropka2.getImenitel());

    imenitel1=(this->getImenitel()*dropka2.getImenitel())/imenitel1;

    int broitel1 = this->getBroitel()*(imenitel1/this->getImenitel())-
                dropka2.getBroitel()*(imenitel1/dropka2.getImenitel());

    lowestFraction(broitel1, imenitel1);

    tmp.broitel = broitel1;
    tmp.imenitel = imenitel1;
    return tmp;
}

Dropki Dropki::operator*(Dropki dropka2) {
    Dropki tmp;
    int x,y;
    x = this->getBroitel()*dropka2.getBroitel();
    y = this->getImenitel()*dropka2.getImenitel();
    lowestFraction(x, y);

    tmp.broitel = x;
    tmp.imenitel = y;
    return tmp;
}

Dropki Dropki::operator/(Dropki dropka2) {
    Dropki tmp;
    int x,y;
    x = this->getBroitel()*dropka2.getImenitel();
    y = this->getImenitel()*dropka2.getBroitel();
    lowestFraction(x, y);

    tmp.broitel = x;
    tmp.imenitel = y;
    return tmp;
}

Dropki Dropki::operator+(int broj) {
    Dropki tmp;
    int imenitel1=findGCD(this->getImenitel(), 1);

    imenitel1=(this->getImenitel()*1)/imenitel1;

    int broitel1 = this->getBroitel()*(imenitel1/this->getImenitel())+
                broj*(imenitel1/1);

    lowestFraction(broitel1, imenitel1);

    tmp.broitel = broitel1;
    tmp.imenitel = imenitel1;
    return tmp;
}

Dropki Dropki::operator-(int broj) {
    Dropki tmp;
    int imenitel1=findGCD(this->getImenitel(), 1);

    imenitel1=(this->getImenitel()*1)/imenitel1;

    int broitel1 = this->getBroitel()*(imenitel1/this->getImenitel())-
                broj*(imenitel1/1);

    lowestFraction(broitel1, imenitel1);

    tmp.broitel = broitel1;
    tmp.imenitel = imenitel1;
    return tmp;
}

Dropki Dropki::operator*(int broj) {
    Dropki tmp;
    int x,y;
    x = this->getBroitel()*broj;
    y = this->getImenitel()*1;
    lowestFraction(x, y);

    tmp.broitel = x;
    tmp.imenitel = y;
    return tmp;
}

Dropki Dropki::operator/(int broj) {
    Dropki tmp;
    int x,y;
    x = this->getBroitel()*1;
    y = this->getImenitel()*broj;
    lowestFraction(x, y);

    tmp.broitel = x;
    tmp.imenitel = y;
    return tmp;
}

void Dropki::pechatenjeVoString(){
    cout<<" vo dropka: "<<getBroitel()<<"/"<<getImenitel()<<endl;
}

void Dropki::pechatenjeVoDouble(){
    cout<<" vo realen broj: "<<(double)getBroitel()/getImenitel()<<endl;
}

int Dropki::getBroitel(){return this->broitel;}
int Dropki::getImenitel(){return this->imenitel;}