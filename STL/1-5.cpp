#include <iostream>

using std::cout;
using std::endl;
  
template <typename T> class Array {
    private:
        T* array;
        int size;
    public:
        Array(int);
        T getValue(int);
};
  
template <typename T> Array<T>::Array(int s){
    array = new T[s];
    size = s;
    for(int i=0; i<size; ++i){
        cin>>array[i];
    }
}
  
template <typename T> T Array<T>::getValue(int n){
    for (int i=0; i<size; ++i)
        if(i==n-1)
            return array[i];
    return -1;
}

int main(){
    Array<int> a(3);
    int n = a.getValue(2);
    cout<<n<<endl;

    Array<double> b(4);
    double n1 = b.getValue(3);
    cout<<n1;
    return 0;
}