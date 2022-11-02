#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <numeric>

using std::ifstream;
using std::ofstream;
using std::vector;
using std::cout;
using std::string;
using std::endl;

class Inventar{
    private:
        int id, kolicestvo;
        double cena;
    public:
        Inventar(){}
        Inventar(int id, int kolicestvo, double cena){
            this->id=id;
            this->kolicestvo=kolicestvo;
            this->cena=cena;
        }
        double getCena(){return cena;}
        int getKolicestrvo(){return kolicestvo;}
        void print(){
            if(kolicestvo<10)
                cout<<"Id: "<<id<<", kolicestvo: "<<kolicestvo<<", cena: "<<cena<<endl;
        }
};

int main() {
    int id, kolicestvo;
    double cena;
    ifstream inventar("inventar.txt");
    if(inventar)
    {
        vector<Inventar> v;
        while(inventar>>id>>kolicestvo>>cena){
            v.push_back(Inventar(id, kolicestvo, cena));
        }
        for(int i=0;i<v.size();++i){
            v[i].print();
        }
        cena = accumulate(v.begin(), v.end(), 0.0, [](int i, Inventar& v){ return v.getCena()*v.getKolicestrvo() + i; });
        cout<<"Vkupna cena: "<<cena<<endl;
        inventar.close();
    }
    else
    {
        cout<<"Ne postoi takva datoteka.";
    }
    
    return 0;
}