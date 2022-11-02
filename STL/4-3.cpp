#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::getline;
using std::find;

void splitString(string str, vector<string> &v, string delimiter = " ")
{
    int start = 0;
    int end = str.find(delimiter);
    string temp;
    while (end != -1) {
        temp = str.substr(start, end - start);
        if(!(find(v.begin(), v.end(), temp) != v.end())) // dali ne e veke dodaden ist zbor
            v.push_back(temp);
        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }
    temp = str.substr(start, end - start);
    if(!(find(v.begin(), v.end(), temp) != v.end()))
            v.push_back(temp);
}

int main(){

    string s;
    cout<<"Vnesete tekst: "; getline(cin, s);

    vector<string> v;
    splitString(s, v, " ");
    sort(v.begin(), v.end());

    for (int i=0;i<v.size(); ++i) {
        cout<<v[i]<<endl;
    }

    return 0;
}