#include <iostream>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;

class Stedac
{
 public:
        void vnesi_podatoci();
        void prikazi_podatoci();
        void uplata(unsigned long i);
        void isplata(unsigned long i);
        long sostojba();
        int getBroj(){ return broj; };
        string getImePrezime(){ return imeprezime; };
        string getAdresa(){ return adresa; };
        long getSaldo(){ return saldo; }; 
        void setSaldo( long saldo ){ this->saldo=saldo; };

  private:
        int broj;
        char imeprezime[30], adresa[50];
        long saldo;
};


void Stedac::vnesi_podatoci () {
    cout<<"Broj na stedac="; cin>>broj;
    cout<<"Ime i prezime: ";  cin.sync(); cin.getline(imeprezime, 30);
    cout<<"Adresa: "; cin.sync(); cin.getline(adresa, 50);
    cout<<"Saldo="; cin>>saldo;
}

void Stedac::prikazi_podatoci(){
    cout<<"Broj="<<getBroj()<<
        " Ime i prezime: "<<getImePrezime()<<
        " Adresa: "<<getAdresa()<<
        " Saldo: "<<getSaldo()<<endl;
}

int instructions()
{
    int izbor;
    cout<<"Vnesi izbor:\n"
        "1 Vnesuvanje nov stedac.\n"
        "2 Prikaz na podatocite.\n"
        "3 Uplata na sredstva.\n"
        "4 Isplata na sredstva.\n"
        "5 Prikaz na saldo za daden stedac.\n"
        "6 Za kraj.\n";

    cin>>izbor;
    return izbor;
}

int main()
{
    int choice;
    list<Stedac> lista;
    
    while((choice = instructions()) != 6) { 
        Stedac s;
        int broj;
        long denari;
        double najden = false;
        switch(choice){ 

        case 1:
            s.vnesi_podatoci();
            lista.push_front(s);
            break;
        case 2:
            for(auto i=lista.begin(); i!=lista.end(); ++i){
                i->prikazi_podatoci();
            }
            break;
        case 3:
            cout<<"Vnesete broj na stedac: "; cin>>broj;
            for(auto i=lista.begin(); i!=lista.end(); ++i){
                if(i->getBroj()==broj){
                    cout<<"Vnesete uplata: ";cin>>denari;
                    i->setSaldo(i->getSaldo() + denari);
                    najden=true;
                }
            }
            if(!najden){
                cout<<"Nema stedac so toj broj!"<<endl;
            }
            break;
        case 4:
            cout<<"Vnesete broj na stedac: "; cin>>broj;
            for(auto i=lista.begin(); i!=lista.end(); ++i){
                if(i->getBroj()==broj){
                    cout<<"\nVnesete isplata: ";cin>>denari;
                    if(i->getSaldo()>=denari){
                        i->setSaldo(i->getSaldo() - denari);
                    }else{
                        cout<<"\nStedacot nema dovolno sredstva za isplata."<<endl;
                    }
                    najden=true;
                }
            }
            if(!najden){
                cout<<"Nema stedac so toj broj!"<<endl;
            }
            break;
        case 5:
            cout<<"\nVnesete broj na stedac: "; cin>>broj;
            for(auto i=lista.begin(); i!=lista.end(); ++i){
                if(i->getBroj()==broj){
                    i->prikazi_podatoci();
                }
            }
            if(!najden){
                cout<<"Nema stedac so toj broj!"<<endl;
            }
            break;
        default:
            cout<<"Greshen izbor\n";
            break;
        }
      }

    return 0;
}
