#include <stdio.h>

int main()
{
    int broj1, broj2;
    scanf("%d %d", &broj1,&broj2);

    if(broj1%2==0 && broj2%2==0){
        printf("Broevite se parni");
    }else if(broj1%2==0 && broj2%2!=0){
        printf("Prviot broj e paren, vtoriot e neparen");
    }else if(broj1%2!=0 && broj2%2==0){
        printf("Prviot broj e neparen, vtoriot e paren");
    }else {
        printf("Broevite se neparni");
    }

    return 0;
}