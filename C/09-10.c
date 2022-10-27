#include <stdio.h>

int main() {

    int n,m;

    printf("Vnesi broj na broevi: ");
    scanf("%d", &n);
    int niza[n], counter;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &m);
        niza[i] = m;
    }

    for(int i=0;i<n;i++)
    {
        counter = 1;
        printf("%d: ", niza[i]);
        for(int j=1;j<=niza[i];j++)
        {
            printf("%d ", counter++);
        }
        printf("\n");
    }

    return 0;
}
