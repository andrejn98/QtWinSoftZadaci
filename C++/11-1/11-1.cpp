#include <list>
#include "artikl.h"
#include "pantoloni.h"
#include "kosuli.h"

using std::cout;
using std::cin;
using std::endl;
using std::list;

int instructions()
{
    int izbor;
    cout<<"Vnesi izbor:\n"
        "1 Vnesuvanje nov artikl vo listata.\n"
        "2 Prikaz na artikli od grupa.\n"
        "3 Prikaz na celata lista(so vkupna cena)\n"
        "4 Prikaz na site artikli shto treba da se nabavat\n"
        "5 Za kraj.\n";        

    cin>>izbor;
    return izbor;
}

int instructions1()
{
    int izbor;
    cout<<"Vnesi izbor:\n"
        "1 Pantoloni.\n"
        "2 Kosuli.\n"
        "3 Za kraj.\n";        

    cin>>izbor;
    return izbor;
}

int main(){
    
    int choice;
    list<pantoloni> listaPantoloni;
    list<kosuli> listaKosuli;
    
    while((choice = instructions()) != 5) { 

        artikl a;
        pantoloni p;
        kosuli k;
        double ima = false;
        int choice1;
        int cena=0;
        
        switch(choice){ 
            
            case 1:
                while((choice1 = instructions1()) != 3){
                    switch (choice1)
                    {
                    case 1:
                        p = p.postavi();
                        listaPantoloni.push_front(p);
                        break;
                    case 2:
                        k = k.postavi();
                        listaKosuli.push_front(k);
                        break;
                    default:
                        cout<<"Greshen izbor\n";
                        break;
                    }
                }
                break;
            case 2:
                while((choice1 = instructions1()) != 3){
                    switch (choice1)
                    {
                    case 1:
                        for(auto i=listaPantoloni.begin(); i!=listaPantoloni.end(); ++i){
                            ima = true;
                            i->Prikazi_Podatoci();
                        }
                        if(!ima){
                            cout<<"Nema vneseno artikli za taa grupa!"<<endl;
                        }
                        break;
                    case 2:
                        for(auto i=listaKosuli.begin(); i!=listaKosuli.end(); ++i){
                            ima = true;
                            i->Prikazi_Podatoci();
                        }
                        if(!ima){
                            cout<<"Nema vneseno artikli za taa grupa!"<<endl;
                        }
                        break;
                    default:
                        cout<<"Greshen izbor\n";
                        break;
                    }
                }
                break;
            case 3:
                for(auto i=listaPantoloni.begin(); i!=listaPantoloni.end(); ++i){
                    ima = true;
                    i->Prikazi_Podatoci();
                    cena += i->getCena();
                }
                for(auto i=listaKosuli.begin(); i!=listaKosuli.end(); ++i){
                    ima = true;
                    i->Prikazi_Podatoci();
                    cena += i->getCena();
                }
                if(!ima){
                    cout<<"Nema vneseno artikli!"<<endl;
                }else{
                    cout<<"Vkupna cena: "<<cena<<endl;
                }
                break;
            case 4:
                for(auto i=listaPantoloni.begin(); i!=listaPantoloni.end(); ++i){
                    ima = true;
                    if(i->Presmetaj_nabavka()){
                        cout<<"Treba da se nabavi: "<<i->getImeNaArtikl()<<endl;
                        cena += i->getCena();
                    }
                }
                for(auto i=listaKosuli.begin(); i!=listaKosuli.end(); ++i){
                    ima = true;
                    if(i->Presmetaj_nabavka()){
                        cout<<"Treba da se nabavi: "<<i->getImeNaArtikl()<<endl;
                        cena += i->getCena();
                    }
                }
                if(!ima){
                    cout<<"Nema vneseno artikli!"<<endl;
                }else{
                    cout<<"Vkupna cena: "<<cena<<endl;
                }
                break;
            default:
                cout<<"Greshen izbor\n";
                break;
        }
    }

    return 0;
}