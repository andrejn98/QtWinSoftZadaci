#include <stdio.h>

int main() {

    int broj, suma;

    printf("Vnesi broj: ");
    scanf("%d", &broj);
    broj--;
    while(broj!=0)
    {
        suma=0;
        for(int i=1;i<broj;i++)
        {
            if(broj%i==0)
                suma+=i;
        }
        if(suma==broj)
            printf("\n%d", broj);

        broj--;
    }
    return 0;
}