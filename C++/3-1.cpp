#include <iostream>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::list;

class Shtedach {
    private:
        double dolzhina, shirina, visina;
    public:
        void set();
        double getDolzhina() { return dolzhina; }
        double getShirina() { return shirina; }
        double getVisina() { return visina; }
        double Ploshtina();
        double Volumen();
        void Print();
};

void Shtedach::set () {
    cout<<"dolzhina="; cin>>dolzhina;
    cout<<"shirina="; cin>>shirina;
    cout<<"visina="; cin>>visina;
}

double Shtedach::Ploshtina () {
    return 2*(getDolzhina()*getShirina()+
            getShirina()*getVisina()+
            getDolzhina()*getVisina());
}

double Shtedach::Volumen () {
    return getDolzhina()*getShirina()*getVisina();
}

void Shtedach::Print(){
    cout<<"dolzhina="<<getDolzhina()<<
        " shirina="<<getShirina()<<
        " visina="<<getVisina()<<endl;
}

int instructions()
{
    int izbor;
    cout<<"Vnesi izbor:\n"
        "1 Kreiraj nov objekt.\n"
        "2 Postavi gi dimenziite.\n"
        "3 Pechati gi dimenziite za site objekti.\n"
        "4 Pechati gi onie koi go zadovoluvaat uslovot.\n"
        "5 za kraj.\n";

    cin>>izbor;
    return izbor;
}

int main()
{
    int choice;
    list<Shtedach> lista;
    
    while((choice = instructions()) != 5) { 
        Shtedach k;
        double ploshtina = __DBL_MAX__;
        switch(choice){ 

        case 1:
            lista.push_front(k);
            break;
        case 2:
            for(auto i=lista.begin(); i!=lista.end(); ++i){
                i->set();
            }
            break;
        case 3:
            for(auto i=lista.begin(); i!=lista.end(); ++i){
                i->Print();
            }
            break;
        case 4:
            for(auto i=lista.begin(); i!=lista.end(); ++i){
                if(!(i->getDolzhina()==i->getShirina() && i->getShirina()==i->getVisina())){
                    if(ploshtina > i->Ploshtina()){
                        ploshtina = i->Ploshtina();
                    }
                }
            }
            for(auto i=lista.begin(); i!=lista.end(); ++i){
                if(ploshtina == i->Ploshtina()){
                    i->Print();
                    cout<<"Ploshtina="<<i->Ploshtina()<<endl;
                }
            }
            break;
        default:
            printf("Greshen izbor\n");
            break;
        }
      }

    return 0;
}
