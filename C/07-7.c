#include <stdio.h>

void dzvezdi(int n);
 
int main()
{ 
    int n;
    printf("Vnesi broj na dzvezdi(n): ");
    scanf("%d", &n);

    dzvezdi(n);
 
    return 0;
} 

void dzvezdi(int n)
{
    if(n!=0)
    {
        for(int i=0;i<n;i++)
        {
            printf("*");
        }
        printf("\n");

        dzvezdi(n-1);
    }
}