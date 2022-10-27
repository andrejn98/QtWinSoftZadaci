#include <stdio.h>

int nzd(int broj1, int broj2, int delitel);
 
int main()
{ 
    int broj1, broj2, delitel;
    scanf("%d %d", &broj1, &broj2);

    if(broj1>broj2)
        delitel=broj1;
    else
        delitel=broj2;

    printf("%d", nzd(broj1, broj2, delitel));
 
    return 0;
} 

int nzd(int broj1, int broj2, int delitel)
{ 
    if(broj1%delitel==0 && broj2%delitel==0)
        return delitel;
    nzd(broj1, broj2, delitel-1);
}