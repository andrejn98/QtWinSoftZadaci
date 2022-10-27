#include <stdio.h>

void prosti(int niza[], int n)
{
    int temp=0;
    for(int i=0;i<n;i++)
    {
        for(int j=2;j<niza[i];j++)
        {
            if(niza[i]%j==0)
            {
                temp=1;
                break;
            }
        }
        if(temp==0)
        {
            printf("%d ", niza[i]);
            niza[i] = 0;
        }
        temp=0;
    }
}

int main()
{
    int n,broj;
    scanf("%d", &n);
    int niza[n];

    for(int i=0;i<n;i++)
    {
        niza[i] = 1;
    }

    for(int i=0;i<n;i++)
    {
        scanf("%d", &broj);
        niza[i] = broj;
    }

    prosti(niza, n);

    return 0;
}