#include <iostream>
#include "Zivotno.h"
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::string;

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

int main(){
    int choice;
    list<Zivotno> lista;

    while((choice = instructions()) != 6) { 
        Zivotno z;
        int broj=0;
        long denari;
        double ima = false;
        char tip, pol;
        string ime;
        int denRagjanje, mesecRagjanje, godinaRagjanje, 
        denDonesuvanje, mesecDonesuvanje, godinaDonesuvnje, 
        denVakcinacija, mesecVakcinacija, godinaVakcinacija;
        switch(choice){ 

            case 1:                
                cout<<"Tip na zivotno('c' za cicach, 'v' za vlekach, 'p' za ptica): "; 
                cin>>tip;
                cout<<"Pol ('m' za masko, 'z' za zensko): ";  
                cin>>pol;
                cout<<"Ime (do 20 karakteri): "; cin.sync(); getline(cin, ime);
                cout<<"Datum na ragjanje (den mesec godina): "; 
                cin>>denRagjanje; cin>>mesecRagjanje; cin>>godinaRagjanje;
                cout<<"Datum na donesuvanje vo zoo (den mesec godina): "; 
                cin>>denDonesuvanje; cin>>mesecDonesuvanje; cin>>godinaDonesuvnje;
                cout<<"Datum na posledna vakcinacija (den mesec godina): "; 
                cin>>denVakcinacija; cin>>mesecVakcinacija; cin>>godinaVakcinacija;

                z = Zivotno(tip, pol, ime, 
                denRagjanje, mesecRagjanje, godinaRagjanje, 
                denDonesuvanje, mesecDonesuvanje, godinaDonesuvnje, 
                denVakcinacija, mesecVakcinacija, godinaVakcinacija);

                lista.push_front(z);
                break;
            case 2:
                for(auto i=lista.begin(); i!=lista.end(); ++i){
                    broj++;
                }
                cout<<"\nVkupen broj na zivotni: \n"<<broj<<endl;
                break;
            case 3:
                cout<<"Vnesete tip ('c' za cicachi, 'v' za vlekachi, 'p' za ptici): ";
                cin>>tip;
                for(auto i=lista.begin(); i!=lista.end(); ++i){
                    if(i->getTip()==tip){
                        i->Prikazi_Podatoci();
                        ima=true;
                    }
                }
                if(!ima){
                    cout<<"\nNema zivotni so toj tip!\n"<<endl;
                }
                break;
            case 4:
                for(auto i=lista.begin(); i!=lista.end(); ++i){
                    i->Prikazi_Podatoci();
                    ima=true;
                }
                if(!ima){
                    cout<<"Nema vneseno zivotni!"<<endl;
                }
                break;
            case 5:
                for(auto i=lista.begin(); i!=lista.end(); ++i){
                    if(i->Presmetaj_vakcinacija()){
                        cout<<"\n"<<i->getIme()<<" treba da se vakcinira!\n"<<endl;
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