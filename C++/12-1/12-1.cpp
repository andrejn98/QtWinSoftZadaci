#include <iostream>
#include "Zivotno.h"
#include "Vlekaci.h"
#include "Ptici.h"
#include "Cicaci.h"
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::list;

int instructions()
{
    int izbor;
    cout<<"Vnesi izbor:\n"
        "1 Vnesuvanje novo zivotno.\n"
        "2 Prikaz na brojna sostojba.\n"
        "3 Prikaz na zivotni spored tip.\n"
        "4 Prikaz na celata lista na zivotni.\n"
        "5 Prikaz na site zivotni koi treba da se vakciniraat.\n"
        "6 Za kraj.\n";

    cin>>izbor;
    return izbor;
}

int instructions1()
{
    int izbor;
    cout<<"Vnesi izbor:\n"
        "1 Vlekac.\n"
        "2 Ptica.\n"
        "3 Cicac.\n"
        "4 Za kraj.\n";

    cin>>izbor;
    return izbor;
}

int main(){
    int choice;
    list<Vlekaci> listaVlekaci;
    list<Ptici> listaPtici;
    list<Cicaci> listaCicaci;

    while((choice = instructions()) != 6) { 
        Vlekaci v;
        Ptici p;
        Cicaci c;
        int broj=0, choice1;
        long denari;
        double ima = false;
        char tip;
        switch(choice){ 
            case 1:
                while((choice1 = instructions1()) != 4){
                    switch(choice1){
                        case 1:
                            v = v.postavi();
                            listaVlekaci.push_front(v);
                            break;
                        case 2:
                            p = p.postavi();
                            listaPtici.push_front(p);
                            break;
                        case 3:
                            c = c.postavi();
                            listaCicaci.push_front(c);
                            break;
                        default:
                            cout<<"Greshen izbor\n";
                            break;
                    }
                }
                break;
            case 2:
                for(auto i=listaVlekaci.begin(); i!=listaVlekaci.end(); ++i){
                    broj++;
                }
                for(auto i=listaPtici.begin(); i!=listaPtici.end(); ++i){
                    broj++;
                }
                for(auto i=listaCicaci.begin(); i!=listaCicaci.end(); ++i){
                    broj++;
                }
                cout<<"\nVkupen broj na zivotni: \n"<<broj<<endl;
                break;
            case 3:
                cout<<"Vnesete tip ('c' za cicachi, 'v' za vlekachi, 'p' za ptici): ";
                cin>>tip;
                if(tip=='v')
                    for(auto i=listaVlekaci.begin(); i!=listaVlekaci.end(); ++i){
                        i->Prikazi_Podatoci();
                        ima=true;
                    }
                else if(tip=='p')
                    for(auto i=listaPtici.begin(); i!=listaPtici.end(); ++i){
                        i->Prikazi_Podatoci();
                        ima=true;
                    }
                else if(tip=='c')
                    for(auto i=listaCicaci.begin(); i!=listaCicaci.end(); ++i){
                        i->Prikazi_Podatoci();
                        ima=true;
                    }
                if(!ima){
                    cout<<"\nNema zivotni so toj tip!\n"<<endl;
                }
                break;
            case 4:
                for(auto i=listaVlekaci.begin(); i!=listaVlekaci.end(); ++i){
                    i->Prikazi_Podatoci();
                    ima=true;
                }
                for(auto i=listaPtici.begin(); i!=listaPtici.end(); ++i){
                    i->Prikazi_Podatoci();
                    ima=true;
                }
                for(auto i=listaCicaci.begin(); i!=listaCicaci.end(); ++i){
                    i->Prikazi_Podatoci();
                    ima=true;
                }
                if(!ima){
                    cout<<"Nema vneseno zivotni!"<<endl;
                }
                break;
            case 5:
                for(auto i=listaVlekaci.begin(); i!=listaVlekaci.end(); ++i){
                    if(i->Presmetaj_vakcinacija()){
                        cout<<"\nVlekac: "<<i->getIme()<<" treba da se vakcinira!\n"<<endl;
                        ima=true;
                    }
                }
                for(auto i=listaPtici.begin(); i!=listaPtici.end(); ++i){
                    if(i->Presmetaj_vakcinacija()){
                        cout<<"\nPtica: "<<i->getIme()<<" treba da se vakcinira!\n"<<endl;
                        ima=true;
                    }
                }
                for(auto i=listaCicaci.begin(); i!=listaCicaci.end(); ++i){
                    if(i->Presmetaj_vakcinacija()){
                        cout<<"\nCicac: "<<i->getIme()<<" treba da se vakcinira!\n"<<endl;
                        ima=true;
                    }
                }
                if(!ima){
                    cout<<"Nema zivotni za vakciniranje."<<endl;
                }
                break;
            default:
                cout<<"Greshen izbor\n";
                break;
        }
    }
    
    return 0;
}