#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <iterator>
#include <numeric>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::equal;
using std::begin;
using std::end;
using std::generate;
using std::rand;
using std::ostream_iterator;

int counter = 4, karta = 1, srce = 1;

int podeliKarti(){
    if(counter!=0){
        --counter;
        return karta;
    }else{
        counter = 3;
        return ++karta;
    }
}

int podeliKartiSrce(){
    if(counter!=0){
        --counter;
        if(srce==1){
            --srce;
            return karta*2;
        }
        return karta;
    }else{
        srce = 1;
        counter = 3;
        return ++karta;
    }
}

int main(){
    int x,n,zbir=0;
    
    cout<<"Vnesete broj na igraci: "; cin>>n;

    vector<int> d(52);

    cout<<"Izberete igra: \n"
    "1) Vrednostite na kartite se od 1 do 13 soodvetno, bez razlika na bojata, A ima vrednost 1.\n"
    "2) Vrednostite na kartite se od 1 do 13 soodvetno, A ima vrednost 1. Kartite srce se brojat dvojno."<<endl;
    cin>>x;
    if(x==1){
        generate(d.begin(), d.end(), podeliKarti);
    }else if(x==2){
        generate(d.begin(), d.end(), podeliKartiSrce);
    }else{
        cout<<"Gresen izbor";
        return 0;
    }

    srand(time(NULL)); 
    std::random_shuffle(d.begin(), d.end());

    cout<<"Karti: ";
    ostream_iterator< int > output( cout, " " );
    std::copy( d.begin(), d.end(), output );
    cout<<endl;

    int kartiNaIgrac = 52/n;
    int igrac, zbirKarti=0;

    while(n!=0){
        counter = kartiNaIgrac;
        cout<<endl<<"Karti na igrac "<<n<<": ";
        for (int i=d.size()-1;i>=0; --i) {
            if(counter!=0){
                zbir += d[i];
                --counter;
                cout<<d[i]<<" ";
                d.pop_back();
            }
        }
        cout<<endl<<"Igracot "<<n<<" ima zbir: "<<zbir<<endl;
        if(zbirKarti<zbir){
            zbirKarti = zbir;
            igrac = n;
        }
        zbir=0;
        --n;
    }

    cout<<endl<<"Pobednik e igracot: "<<igrac<<" so zbir: "<<zbirKarti;

    return 0;
}