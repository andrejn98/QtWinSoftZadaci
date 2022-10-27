#include <stdio.h>

int main()
{
    int counter=10, total=0;
    while(counter>0){
        total += counter;
        counter--;
    }

    printf("%d", total);
    return 0;
}