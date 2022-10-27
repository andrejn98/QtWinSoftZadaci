#include <stdio.h>

int main() {

    int n, i, j, x, k, temp;

    printf("Vnesi broj na bakterii, minuti na delba na bakteriite, minuti na umiranje, procent na umiranje i minuti za proverka: ");
    scanf("%d %d %d %d %d", &n, &i, &j, &x, &k);

    temp=j; // minuti na izumiranje
    for(;k>=0;k--)
    {
        temp--;
        n*=2;
        if(temp==0)
        {
            n=n-(n*x/100);
            temp=j;
        }
    }

    printf("\nn=%d", n);

    return 0;
}