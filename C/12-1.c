#include <stdio.h>

int mnoziSoStepenOdDva(int broj, int stepen)
{ 
    return broj<<stepen; 
    // po formula, primer ako broj e 5 5*2^stepen i se shiftne za 1 mesto vo levo
    // togas formulata e 5*2^1=10 ili binarno 5 e 101, vo levo za 1 => 1010 shto e 10
}

int main()
{
    int broj, stepen;
    scanf("%d %d", &broj, &stepen);

    printf("%d", mnoziSoStepenOdDva(broj,stepen));
}