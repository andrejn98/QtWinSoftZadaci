#include <iostream>

using std::cout;
using std::endl;

template<typename T> void f(T array[], int start, int end, int count, int value=0)
{
    double sum=0;
    for(int i=value; i<count; ++i)
        if(i>=start && i<=end){
            sum+=array[i];
        }

    cout<<sum<<endl;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    double arr1[5] = {1.2, 3.6, 4.4, 6.2, 2.8};

    f(arr, 1, 3, 5);
    f(arr, 1, 3, 5, 2);

    f(arr1, 1, 4, 5, 0);
    f(arr1, 1, 4, 5, 2);

    return 0;
}