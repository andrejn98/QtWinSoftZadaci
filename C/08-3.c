#include <stdio.h>
#include<string.h>

int palindrom(char niza[])
{
    int temp=0, len=strlen(niza);
    for(int i=0;i<len;i++)
    {
        if(niza[i] != niza[len-i-1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char niza[20];
    scanf("%s", &niza);

    printf("%d", palindrom(niza));

    return 0;
}