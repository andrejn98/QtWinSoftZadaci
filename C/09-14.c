#include <stdio.h>

void rekurzivna(int n)
{
    int counter = n;
    if(n>1)
    {
        //printf("%d \n", n);

        rekurzivna(n-1);
    }
    while(counter!=1){  
        printf("%d", --counter);
    }
    printf("%d \n", n);
} // so rekurziite ne mi ide bash

int main() {

    int n;
    printf("Vnesi n: ");
    scanf("%d", &n);
    rekurzivna(n);

    return 0;
}
