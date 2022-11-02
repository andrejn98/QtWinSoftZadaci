#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Garaza{
    public:
        Garaza(){
            try
            {
                cout<<"Kreirana Garaza"<<endl;
            }
            catch(int i)
            {
                cout<<"Isklucok od Garaza: "<<i<<endl;
                throw 1;
            }
        }
        ~Garaza(){
            cout<<"Unistena Garaza"<<endl;
        }
};

class Motor : Garaza{
    public:
        Motor() : Garaza(){
            cout<<"Kreiran Motor"<<endl;
            throw 3;
        }
        ~Motor(){
            cout<<"Unisten Motor"<<endl;
        }
};

class Avtomobil : Motor{
    public:
        Avtomobil() : Motor(){
            cout<<"Kreiran Avtomobil"<<endl;
        }
        ~Avtomobil(){
            cout<<"Unisten Avtomobil"<<endl;
        }
};

int main(){
    
    try {
        Avtomobil a;
    }
    catch (int i) {
        cout << "Faten exception vo main: "<<i<<endl;
    }

    return 0;
}