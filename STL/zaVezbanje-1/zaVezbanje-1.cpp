#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>

using std::ifstream;
using std::ofstream;
using std::vector;
using std::cout;
using std::string;
using std::endl;
using std::set_union;
using std::set_intersection;

class Pravoagolnik{
    private:
        double sirina, dolzina;
    public:
        Pravoagolnik(){}
        Pravoagolnik(double sirina, double dolzina){
            this->sirina=sirina;
            this->dolzina=dolzina;
        }
        double getSirina(){return sirina;}
        double getDolzina(){return dolzina;}
        void print(){
            cout<<"Sirina: "<<sirina<<", dolzina: "<<dolzina<<endl;
        }
        bool operator < (const Pravoagolnik& p) const {return sirina<p.sirina;}
};

class Kvadrat{
    private:
        double strana;
    public:
        Kvadrat(){}
        Kvadrat(double strana){
            this->strana=strana;
        }
        double getStrana(){return strana;}
        void print(){
            cout<<"Strana: "<<strana<<endl;
        }
        bool operator < (const Kvadrat& k) const {return strana<k.strana;}
};

int main() {
    double broj, sirina, dolzina, strana;
    ifstream datoteka1("datoteka1.txt");
    vector<Pravoagolnik> pravoagolnici1;
    vector<Kvadrat> kvadrati1;
    if(datoteka1)
    {
        try
        {
            while(datoteka1>>broj){
                if(broj==1){
                    if(!(datoteka1>>sirina>>dolzina)) throw 1;
                    pravoagolnici1.push_back(Pravoagolnik(sirina, dolzina));
                }else{
                    if(!(datoteka1>>strana)) throw 1;
                    kvadrati1.push_back(Kvadrat(strana));
                }
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }        
        datoteka1.close();
    }
    else
    {
        cout<<"Ne postoi takva datoteka.";
    }

    vector<Pravoagolnik> pravoagolnici2;
    vector<Kvadrat> kvadrati2;
    ifstream datoteka2("datoteka2.txt");
    if(datoteka2)
    {
        try
        {
            while(datoteka2>>broj){
                if(broj==1){
                    if(!(datoteka2>>sirina>>dolzina)) throw 1;
                    pravoagolnici2.push_back(Pravoagolnik(sirina, dolzina));
                }else{
                    if(!(datoteka2>>strana)) throw 1;
                    kvadrati2.push_back(Kvadrat(strana));
                }
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        datoteka2.close();
    }
    else
    {
        cout<<"Ne postoi takva datoteka.";
    }
    
    std::sort(pravoagolnici1.begin(), pravoagolnici1.end()); // za da moze da se najde presek, unija...
    std::sort(kvadrati1.begin(), kvadrati1.end());
    cout<<"Pravoagolnici1:"<<endl;
    for(int i=0;i<pravoagolnici1.size();++i){
        pravoagolnici1[i].print();
    }
    cout<<endl<<"Kvadrati1:"<<endl;
    for(int i=0;i<kvadrati1.size();++i){
        kvadrati1[i].print();
    }
    std::sort(pravoagolnici2.begin(), pravoagolnici2.end());
    std::sort(kvadrati2.begin(), kvadrati2.end());
    cout<<"-----------"<<endl<<"Pravoagolnici2:"<<endl;
    for(int i=0;i<pravoagolnici2.size();++i){
        pravoagolnici2[i].print();
    }
    cout<<endl<<"Kvadrati2:"<<endl;
    for(int i=0;i<kvadrati2.size();++i){
        kvadrati2[i].print();
    }

    vector<Pravoagolnik> pravoagolnici;
    vector<Kvadrat> kvadrati;

    set_union(pravoagolnici1.begin(), pravoagolnici1.end(), pravoagolnici2.begin(), pravoagolnici2.end(), std::back_inserter(pravoagolnici));
    set_union(kvadrati1.begin(), kvadrati1.end(), kvadrati2.begin(), kvadrati2.end(), std::back_inserter(kvadrati));
    cout<<"=================="<<endl<<"Unija na pravoagolnici:"<<endl;
    for(auto x : pravoagolnici){
        x.print();
    }
    cout<<endl<<"Unija na kvadrati:"<<endl;
    for(auto x : kvadrati){
        x.print();
    }

    pravoagolnici.clear();
    kvadrati.clear();

    set_intersection(pravoagolnici1.begin(), pravoagolnici1.end(), pravoagolnici2.begin(), pravoagolnici2.end(), std::back_inserter(pravoagolnici));
    set_intersection(kvadrati1.begin(), kvadrati1.end(), kvadrati2.begin(), kvadrati2.end(), std::back_inserter(kvadrati));
    cout<<"=================="<<endl<<"Presek na pravoagolnici:"<<endl;
    for(auto x : pravoagolnici){
        x.print();
    }
    cout<<endl<<"Presek na kvadrati:"<<endl;
    for(auto x : kvadrati){
        x.print();
    }

    return 0;
}