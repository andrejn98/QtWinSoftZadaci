#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template< class T > void prevrtiPechati(T *array, const int n){
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; ++j)
            if (array[j] > array[j + 1]){
                auto temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }

    for (int i=0; i<n; ++i)
        cout<<array[i]<<" ";

    cout<<endl;
}
 
int main(){
    int n;
    cout<<"Vnesi broj na elementi: ";
    cin>>n;

    int a[n];
    cout<<"Vnesi celi broevi: ";
    for (int i=0; i<n; ++i){
        cin>>a[i];
    }    

    double b[n];
    cout<<"Vnesi realni broevi: ";
    for (int i=0; i<n; ++i){
        cin>>b[i];
    }
    
    cout << "Sortirani celi broevi:" << endl;
    prevrtiPechati(a, n);

    cout << "Sortirani realni broevi:" << endl;
    prevrtiPechati(b, n); 

    return 0;
}