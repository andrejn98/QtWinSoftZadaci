#include <stdio.h>

int main()
{
    int counter=10, total=1, temp;
    while(counter>0){
        scanf("%d", &temp);
        total *= temp;
        counter--;
    }

    printf("%d", total);
    return 0;
}