#include <stdio.h>

int nzd(int broj1, int broj2);
 
int main()
{ 
    int broj1, broj2;
    scanf("%d %d", &broj1, &broj2);
    printf("%d", nzd(broj1, broj2));
 
    return 0;
} 

int nzd(int broj1, int broj2)
{
    int delitel;
    if(broj1>broj2)
        delitel=broj1;
    else
        delitel=broj2;

    while (1) {
        if(broj1%delitel==0 && broj2%delitel==0)
            return delitel;
        delitel--;
    }
}