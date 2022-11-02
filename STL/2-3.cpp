#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

template<typename T> class Lica {
private:
    string imeiprezime;
    int mat_br;
    int vozrast;
    string adresa;
    T kod;
public:
    Lica(){};
    Lica(string imeiprezime, int mat_br, int vozrast, string adresa, T kod){
        this->imeiprezime = imeiprezime;
        this->mat_br = mat_br;
        this->vozrast = vozrast;
        this->adresa = adresa;
        this->kod = kod;
    };
    string getImeIPrezime(){return this->imeiprezime;}
    int getMatBroj(){return this->mat_br;}
    int getVozrast(){return this->vozrast;}
    string getAdresa(){return this->adresa;}
    T getKod(){return this->kod;}
};

template<typename T> void pecatiPole(T array[], int count)
{
    if(count==0){
        cout<<"Nema vneseno lica!"<<endl;
        return;
    }
    for(int i=0; i<count; ++i){
        cout<<array[i].getImeIPrezime()<<" "<<array[i].getMatBroj()<<" ";
        cout<<array[i].getVozrast()<<" "<<array[i].getAdresa()<<" "<<array[i].getKod()<<endl;
    }
    cout<<endl;
}

int instructions()
{
    int izbor;
    cout<<"Vnesi izbor:\n"
        "1 Vnesuvanje nov vraboten.\n"
        "2 Vnesuvanje nov klient.\n"
        "3 Prikaz na lista za vraboteni.\n"
        "4 Prikaz na lista za klienti.\n"
        "5 Za kraj.\n";        

    cin>>izbor;
    return izbor;
}


int main()
{
    
    int choice;
    string ime, adresa, kodKlient;
    int mat_br, vozrast, kodVraboten, brojV=0, brojK=0;
    cout<<"Vnesete broj na vraboteni: "; cin>> brojV;
    Lica <int>Vraboten[brojV];
    cout<<"Vnesete broj na klienti: "; cin>> brojK;
    Lica <string>Klient[brojK];

    while((choice = instructions()) != 5){
        switch (choice)
            {
            case 1:
                for(int i=0;i<brojV;++i){
                    cout<<"Vnesete ime: "; cin>>ime;
                    cout<<"Vnesete maticen broj: "; cin>>mat_br;
                    cout<<"Vnesete vozrast: "; cin>>vozrast;
                    cout<<"Vnesete adresa: "; cin>>adresa;
                    cout<<"Vnesete kod: "; cin>>kodVraboten;
                    Lica <int>Vraboten1(ime, mat_br, vozrast, adresa, kodVraboten);
                    Vraboten[i] = Vraboten1;
                }
                break;
            case 2: 
                for(int i=0;i<brojK;++i){
                    cout<<"Vnesete ime: "; cin>>ime;
                    cout<<"Vnesete maticen broj: "; cin>>mat_br;
                    cout<<"Vnesete vozrast: "; cin>>vozrast;
                    cout<<"Vnesete adresa: "; cin>>adresa;
                    cout<<"Vnesete kod: "; cin>>kodKlient;
                    Lica <string>Klient1(ime, mat_br, vozrast, adresa, kodKlient);
                    Klient[i] = Klient1;
                }
                break;
            case 3:
                pecatiPole(Vraboten, brojV);
                break;
            case 4:
                pecatiPole(Klient, brojK);
                break;
            default:
                cout<<"Greshen izbor\n";
                break;
            }
    }

    return 0;
}