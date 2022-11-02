#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class Zapis {
    public:
        T x, y, z;
        Zapis(T x, T y, T z){ this->x=x; this->y=y; this->z=z;}
};

template <typename T>
void kontrolor(Zapis<T> x)
{
    if((x.x + x.y + x.z)>1000){
        cout<<"Zbirot e pogolem od 1000"<<endl; 
    }else{
        cout<<"Zbirot e pomal od 1000"<<endl;
    }
}

int main(){

    Zapis<int> celi(20, 60, 30);
    kontrolor(celi);
    celi = Zapis<int>(274, 422, 421);
    kontrolor(celi);
    
    Zapis<double> realni(42.4, 10.1, 34.6);
    kontrolor(realni);
    realni = Zapis<double>(202.4, 603.1, 301.6);
    kontrolor(realni);

    return 0;
};