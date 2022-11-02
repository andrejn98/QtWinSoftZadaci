#include <iostream>
#include <list>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;

template <typename T>
class Mnozestvo {
    private:
        T x;
        static int brojElementi;
    public:
        Mnozestvo(T x){this->x=x; ++brojElementi;}
        void setElement(T x){this->x=x;};
        T getElement(){return x;};
        int getBrojElementi(){return brojElementi;}
};

template <> int Mnozestvo<int>::brojElementi = 0;
template <> int Mnozestvo<double>::brojElementi = 0;
template <> int Mnozestvo<string>::brojElementi = 0;

template <typename T> T najdiNajgolem(list<Mnozestvo<T>> lista){}

template <> string najdiNajgolem(list<Mnozestvo<string>> lista){
    string tmp;

    auto i=lista.begin(); 
    tmp = i->getElement();
    int size = tmp.length();
    ++i;
    while(i!=lista.end()){
        if(size<i->getElement().length()){
            tmp = i->getElement();
        }
        ++i;
    }

    return tmp;
}

template <> int najdiNajgolem(list<Mnozestvo<int>> lista){
    int tmp;

    auto i=lista.begin(); 
    tmp = i->getElement();
    ++i;
    while(i!=lista.end()){
        if(tmp<i->getElement()){
            tmp = i->getElement();
        }
        ++i;
    }

    return tmp;
}

template <> double najdiNajgolem(list<Mnozestvo<double>> lista){
    double tmp;

    auto i=lista.begin(); 
    tmp = i->getElement();
    ++i;
    while(i!=lista.end()){
        if(tmp<i->getElement()){
            tmp = i->getElement();
        }
        ++i;
    }

    return tmp;
}


int instructions()
{
    int izbor;
    cout<<"Vnesi izbor:\n"
        "1 Dodaj element vo A.\n"
        "2 Dodaj element vo B.\n"
        "3 Dodaj element vo C.\n"
        "4 Prikazi go A.\n"
        "5 Prikazi go B.\n"
        "6 Prikazi go C.\n"
        "7 Prikazi najgolemi elementi.\n"
        "8 Prikazi broj na elementi vo mnozestvata.\n"
        "9 Za kraj.\n";        

    cin>>izbor;
    return izbor;
}

int main(){
    int choice;
    list<Mnozestvo<int>> listaA;
    list<Mnozestvo<double>> listaB;
    list<Mnozestvo<string>> listaC;
    
    int x;
    double y;
    string z;
    bool ima=false;
    int broj;
    bool imaA = false, imaB = false, imaC=false;
    
    while((choice = instructions()) != 9){
        switch (choice){
            case 1:
                {
                    cout<<"Vnesete int element: "; cin>>x;
                    Mnozestvo<int> A(x);
                    listaA.push_back(A);
                }
                break;
            case 2: 
                {
                    cout<<"Vnesete double element: "; cin>>y;
                    Mnozestvo<double> B(y);
                    listaB.push_back(B);
                }
                break;
            case 3:
                {
                    cout<<"Vnesete string element: "; cin>>z;
                    Mnozestvo<string> C(z);
                    listaC.push_back(C);
                }
                break;
            case 4:
                for(auto i=listaA.begin(); i!=listaA.end(); ++i){
                    cout<<i->getElement()<<" ";
                    ima=true;
                }
                if(!ima){
                    cout<<"Nema elementi vo lista A!";
                }
                cout<<endl;
                break;
            case 5:
                for(auto i=listaB.begin(); i!=listaB.end(); ++i){
                    cout<<i->getElement()<<" ";
                    ima=true;
                }
                if(!ima){
                    cout<<"Nema elementi vo lista B!";
                }
                cout<<endl;
                break;
            case 6:
                for(auto i=listaC.begin(); i!=listaC.end(); ++i){
                    cout<<i->getElement()<<" ";
                    ima=true;
                }
                if(!ima){
                    cout<<"Nema elementi vo lista C!";
                }
                cout<<endl;
                break;
            case 7:
                for(auto i=listaA.begin(); i!=listaA.end(); ++i){
                    imaA=true;
                }
                for(auto i=listaB.begin(); i!=listaB.end(); ++i){
                    imaB=true;
                }
                for(auto i=listaC.begin(); i!=listaC.end(); ++i){
                    imaC=true;
                }

                if(!imaA || !imaB || !imaC){
                    cout<<"Nema vneseno elementi!"<<endl;
                }else{
                    cout<<"Najgolem int: "<<najdiNajgolem(listaA);
                    cout<<" Najgolem double: "<<najdiNajgolem(listaB);
                    cout<<" Najgolem string: "<<najdiNajgolem(listaC)<<endl;;
                }
                break;
            case 8:
                broj=0;
                broj+=listaA.front().getBrojElementi(); // zatoa shto e static site od taa klasa imaat ista vrednost
                broj+=listaB.front().getBrojElementi();
                broj+=listaC.front().getBrojElementi();
                cout<<"Vkupen broj na elementi: "<<broj<<endl;
                break;
            default:
                cout<<"Greshen izbor\n";
                break;
            }
    }

    return 0;
};