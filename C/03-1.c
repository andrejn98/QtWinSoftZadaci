#include <stdio.h>

int main()
{
    int broj1, broj2;
    scanf("%d %d", &broj1,&broj2);

    if(broj1>broj2){
        printf("%d pogolem od %d", broj1, broj2);
    }else if(broj1<broj2){
        printf("%d pogolem od %d", broj2, broj1);
    }else{
        printf("Broevite se ednakvi");
    }

    return 0;
}