#include <stdio.h>
 
int main()
{ 
    int temperatura;
    scanf("%d", &temperatura);
    if(temperatura>=0 && temperatura<=212)
    {
        printf("%+*.*f", 10, 3, 5.0/9.0*(temperatura-32));
        // + za znak, 10 za dolzina, 3 za preciznost
    }else
        printf("Greshen vnes!");
 
    return 0;
} 
