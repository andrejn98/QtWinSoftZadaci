#include <iostream>
#include <map>

using std::multimap;
using std::cout;
using std::cin;
using std::string;
using std::endl;

class Uplata{
    private:
        string imeNaStedac;
        int uplata;
    public:
        Uplata();
        Uplata(string ime, int uplata){ imeNaStedac=ime; this->uplata=uplata; };
        string getIme(){return imeNaStedac;};
        int getUplata(){return uplata;};
};  

int instructions()
{
    int izbor;
    cout<<"Vnesi izbor:\n"
        "1 Dodaj uplata.\n"
        "2 Prikazi uplati za daden stedac.\n"
        "3 Za kraj.\n";        

    cin>>izbor;
    return izbor;
}

int main(){
    int choice, uplata;

    multimap<string, Uplata> mapa;
    string ime;

    while((choice = instructions()) != 3){
        switch (choice)
            {
            case 1:
                cout<<"Vnesete ime na stedac: "; cin.sync(); getline(cin, ime);
                cout<<"Vnesete golemina na uplata: "; cin>>uplata;
                mapa.insert({ime, Uplata(ime, uplata)});
                break;
            case 2:
                cout<<"Vnesete ime na stedac: "; cin.sync(); getline(cin, ime);
                for(auto x : mapa){
                    if(x.first == ime){
                        cout<<"Ime: "<<x.second.getIme()<<", uplata: "<<x.second.getUplata()<<endl;
                    }
                }
                break;
            default:
                cout<<"Greshen izbor\n";
                break;
            }
    }
}