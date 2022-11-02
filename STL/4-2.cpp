#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

int main(){

    string s1 = "slatko";
    string s2 = "staklo";
    vector<char> v1(s1.begin(), s1.end()); // se deli zborot na karakteri
    vector<char> v2(s2.begin(), s2.end());

    sort(v1.begin(), v1.end()); // se sortiraat karakterite 
    sort(v2.begin(), v2.end());

    bool daliSe = true;
    for(int i=0; i<v1.size(); i++){
        if(v1[i]!=v2[i]){
            cout<<"Zborovite ne se anagrami!";
            daliSe=false;
            break;
        }
    }
    if(daliSe)
        cout<<"Zborovite se anagrami.";

    return 0;
}