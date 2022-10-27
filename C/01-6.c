#include <stdio.h>

int main()
{
    int broj;
    scanf("%d", &broj);

    int broj1=broj/10000%10,broj2=broj/1000%10,broj3=broj/100%10,broj4=broj/10%10,broj5=broj%10;

    printf("%d   %d   %d   %d   %d",broj1,broj2,broj3,broj4,broj5);

    return 0;
}
