#include <stdio.h>

int paren(int broj);
 
int main()
{ 
    int broj;
    for(int i=0;i<10;i++)
    {
        scanf("%d", &broj);
        printf("%d\n", paren(broj));
    }
 
    return 0;
} 

int paren(int broj)
{
    if(broj%2==0)
        return 1;
    else
        return 0;
}