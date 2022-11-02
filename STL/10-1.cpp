#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Klasa1{
    public:
        Klasa1(){
            cout<<"Kreirana klasa 1"<<endl;
        }
        ~Klasa1(){
            cout<<"Unistena e klasa 1"<<endl;
        }
};

class Klasa2{
    public:
        Klasa2(){
            cout<<"Kreirana klasa 2"<<endl;
            throw 2;
        }
        ~Klasa2(){
            cout<<"Unistena e klasa 2"<<endl;
        }
};

int main(){    
    try {
        Klasa1 k1;

        Klasa2 k2;
    }
    catch (int i) {
        cout << "Faten exception: "<<i<<endl;
    }

    return 0;
}