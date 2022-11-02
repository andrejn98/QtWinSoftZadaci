#include <iostream>
#include <algorithm>
#include <list>
#include <time.h>
#include <iterator>
#include <numeric>

using std::cout;
using std::endl;
using std::list;
using std::equal;
using std::begin;
using std::end;
using std::generate;
using std::rand;
using std::ostream_iterator;

int nextRandom(){
    return (rand() % 9999);
}

bool getEven(int value){
    return value%2==0;
}

bool getLt2000(int value){
    return value<2000;
}

bool getInRange20004000(int value){
    return (value>=2000) && (value<=4000);
}

bool getInRange40006000(int value){
    return (value>=4000) && (value<=6000);
}

bool getInRange60008000(int value){
    return (value>=6000) && (value<=8000);
}

bool getInRange800010000(int value){
    return (value>=8000) && (value<=10000);
}

int main(){
    list<int> d(1000);
    srand(time(NULL)); 
    generate(d.begin(), d.end(), nextRandom);

    ostream_iterator< int > output( cout, " " );
    std::copy( d.begin(), d.end(), output );

    int result = std::count_if(d.begin(), d.end(), getEven);
    cout<<endl<<"Broj na parni broevi: "<<result<<endl;

    result = std::count_if(d.begin(), d.end(), getLt2000);
    cout<<"Broj na broevi pomali od 2000: "<<result<<endl;

    result = std::count_if(d.begin(), d.end(), getInRange20004000);
    cout<<"Broj na broevi od 2000 do 4000: "<<result<<endl;

    result = std::count_if(d.begin(), d.end(), getInRange40006000);
    cout<<"Broj na broevi od 4000 do 6000: "<<result<<endl;
    
    result = std::count_if(d.begin(), d.end(), getInRange60008000);
    cout<<"Broj na broevi od 6000 do 8000: "<<result<<endl;

    result = std::count_if(d.begin(), d.end(), getInRange800010000);
    cout<<"Broj na broevi od 8000 do 10000: "<<result<<endl;

    result = std::accumulate(d.begin(), d.end(), 0)/1000;
    cout<<"Sredna vrednost na broevite: "<<result<<endl;

    return 0;
}