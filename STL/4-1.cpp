#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

class Imenik{
    public:
        Imenik(string ime, string broj){this->ime=ime; tel_broj=broj;}
        void setIme(string ime){this->ime=ime;};
        string getIme(){return ime;};
        void setBroj(string broj){tel_broj=broj;};
        string getBroj(){return tel_broj;};
    private:
        string ime,tel_broj;
};

bool compareName(Imenik i1, Imenik i2)
{
    return i1.getIme()<i2.getIme();
}

int main(){

    vector<Imenik> vektor;
    vektor.push_back(Imenik("Bojan", "070707070"));
    vektor.push_back(Imenik("Stefan", "078787878"));
    vektor.push_back(Imenik("Andrej", "074747474"));
    vektor.push_back(Imenik("Irina", "072727272"));
    vektor.push_back(Imenik("Maja", "074747474"));
    
    sort(vektor.begin(), vektor.end(), compareName);

    for(int i=0; i<vektor.size(); ++i){
        cout<<vektor[i].getIme()<<" "<<vektor[i].getBroj()<<endl;
    }

    return 0;
}