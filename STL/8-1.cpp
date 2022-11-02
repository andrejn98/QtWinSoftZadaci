#include <iostream>
#include <list>
#include <numeric>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::accumulate;

const int PLATA = 10000;

class Vraboten{
    private:
        string ime;
        int bodovi;
    public:
      Vraboten(){};
      Vraboten(string ime, int bodovi){this->bodovi=bodovi; this->ime=ime;};
      string getIme(){return ime;};
      int getBodovi(){return bodovi;};
};

bool compareBodovi(Vraboten v1, Vraboten v2)
{
    return v1.getBodovi()<v2.getBodovi();
}

int main(){
    std::list<Vraboten> vraboteni;

    string ime;
    int bodovi,broj;
    cout<<"Vnesete broj na vraboteni: "; cin>>broj;
    while(broj!=0){
        cout<<"Vnesete ime na vraboten: "; cin.sync(); getline(cin, ime);
        cout<<"Vnesete bodovi na vraboteniot: "; cin>>bodovi;
        vraboteni.push_back(Vraboten(ime, bodovi));
        --broj;
    }

    vraboteni.sort(compareBodovi);

    for(auto i : vraboteni){
        cout<<"Ime: "<<i.getIme()<<", bodovi: "<<i.getBodovi()<<", plata: "<<i.getBodovi()*PLATA<<endl;
    }

    broj = accumulate(vraboteni.begin(), vraboteni.end(), 0, [](int i, Vraboten& v){ return v.getBodovi() + i; }); // lambda za sum

    cout<<"Plata za celata firma: "<<broj*PLATA<<endl;

    return 0;
}