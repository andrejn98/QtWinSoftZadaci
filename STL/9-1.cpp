#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ostream_iterator;

int f()
{ 
    static int i;
    return ++i;
}

int main(){
    vector<int> v(1000);
    vector<int> v1(999);
    
    std::generate(v.begin(), v.end(), f);

    try
    {
        for(int i=0;i<v.size();++i){
            v1.at(i) = v.at(i);
        }
        ostream_iterator<int> output(cout, " ");
        std::copy(v1.begin(), v1.end(), output);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Nema dovolno mesto vo v1!" << '\n';
    }

    return 0;
}