#include <stdio.h>

int obratno(int broj);
 
int main()
{ 
    int broj;
    scanf("%d", &broj);
    printf("%d", obratno(broj));
 
    return 0;
} 

int obratno(int broj)
{
    int ostatok, obraten=0;
    while (broj!=0) {
        ostatok = broj%10;
        obraten = obraten*10 + ostatok;
        broj/=10;
    }
    return obraten;
}