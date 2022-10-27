#include <stdio.h>

int main() {

    int n1, n2;

    printf("Vnesi interval: ");
    scanf("%d %d", &n1, &n2);
    int n=n2-n1, temp=n1;
    int niza[n];
    for(int i=0;i<=n;i++)
    {
        niza[i] = temp++;
        printf("%d ", niza[i]);
    }

    for(int i=n;i>0;i--)
    {
        if(niza[i]%n1==0)
        {
            printf("\n%d %d", niza[i], n1);
        }
        n1++;
    }

    return 0;
}