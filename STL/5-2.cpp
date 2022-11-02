#include <iostream>
#include <list>
#include <algorithm>

using std::cout;
using std::endl;
using std::list;
using std::sort;
using std::string;

int main(){
    list<string> lista1, lista2, lista3;

    lista1.push_back("test@test.com");
    lista1.push_back("andrej@test.com");
    lista1.push_back("petko@test.com");

    lista2.push_back("test@test.com");
    lista2.push_back("andrej@test.com");
    lista2.push_back("test@test.com");

    lista3.push_back("andrej@test.com");
    lista3.push_back("petko@test.com");
    lista3.push_back("andrej@test.com");

    lista1.splice(lista1.end(), lista2);
    lista1.splice(lista1.end(), lista3);

    lista1.sort();
    lista1.unique();

    for(auto x : lista1){
        cout<<x<<" ";
    }

    return 0;
}