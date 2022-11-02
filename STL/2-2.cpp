#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Kvadrat{
    public:
        int strana;
        int plostina;
};

class Pravoagolnik{
    public:
        int sirina, dolzina;
        int plostina;
};

template<typename T> void pecatiPole(T array[], int count)
{
    for(int i=0; i<count; ++i){
        cout<<array[i].plostina<<" ";
    }
    cout<<endl;
}

template<typename T> void sortirajPole(T array[], int count)
{
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; ++j)
            if(array[j].plostina > array[j + 1].plostina)
            {
                int temp = array[j].plostina;
                array[j].plostina = array[j + 1].plostina;
                array[j + 1].plostina = temp;
            }
}

int main()
{
    int n;
    cout<<"Vnesi broj na kvadrati: ";
    cin>>n;
    Kvadrat k[n];
    cout<<"Vnesi strani za kvadratite: ";
    for(int i=0;i<n;++i){
        cin>>k[i].strana;
        k[i].plostina = k[i].strana*k[i].strana;
    }
    pecatiPole(k, n);
    sortirajPole(k, n); 
    pecatiPole(k, n);
    cout<<"Vnesi broj na pravoagolnici: ";
    cin>>n;
    Pravoagolnik p[n];
    cout<<"Vnesi sirina i dolzina za pravoagolnicite: ";
    for(int i=0;i<n;++i){
        cin>>p[i].sirina;
        cin>>p[i].dolzina;
        p[i].plostina = p[i].sirina*p[i].dolzina;
    }
    pecatiPole(p, n);
    sortirajPole(p, n); 
    pecatiPole(p, n);

    return 0;
}