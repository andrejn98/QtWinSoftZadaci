#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::equal;
using std::begin;
using std::end;

template <typename T> bool palindrom(vector<T> v){
    bool tmp;

    tmp = equal(begin(v), begin(v) + v.size() / 2, rbegin(v));

    return tmp;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    
    for(auto i : v){
        cout<<i<<" ";
    }

    cout<<endl<<(palindrom(v) ? "Vektorot e palindrom" : "Vektorot ne e palindrom")<<endl;

    vector<char> v1;
    v1.push_back('a');
    v1.push_back('b');
    v1.push_back('c');
    v1.push_back('a');

    for(auto i : v1){
        cout<<i<<" ";
    }

    cout<<endl<<(palindrom(v1) ? "Vektorot e palindrom" : "Vektorot ne e palindrom");
    
    return 0;
}