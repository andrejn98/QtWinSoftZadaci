#include <stdio.h>

void vnesiMatrica(int n, int m, int matrica[n][m])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d", &matrica[i][j]);
        }
    }
}

void pechatiMatrica(int n, int m, int matrica[n][m])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d", matrica[i][j]);
        }
        printf("\n");
    }
}

int main()
{    
    int n,m;
    scanf("%d %d", &n, &m);
    int matrica[n][m];

    vnesiMatrica(n, m, matrica);
    pechatiMatrica(n, m, matrica);
    
    return 0;
}