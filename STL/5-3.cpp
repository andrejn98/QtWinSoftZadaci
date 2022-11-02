#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::equal;
using std::begin;
using std::end;
using std::reverse;

int main(){
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    d.push_back(6);

    for(auto i : d){
        cout<<i<<" ";
    }

    vector<int> v;
    
    for(auto i : d){
        v.push_back(i);
    }

    reverse(v.begin(), v.end());

    cout<<endl;
    for(auto i : v){
        cout<<i<<" ";
    }
    
    return 0;
}