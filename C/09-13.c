#include <stdio.h>

int main() {

    int n,m;
    printf("Vnesi m i n: ");
    scanf("%d %d", &m, &n);
    int matrica[m][n], counter=1, kolona=0;

    while(kolona <= n) { // proveruvaj za sekoja kolona
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {

                if (j == kolona) {
                    if(j % 2 == 0) {
                        matrica[i][j] = counter;
                        counter++;
                    }else {
                        if (i == 0) // ako e prv red
                            counter += m-1;

                        matrica[i][j] = counter;
                        counter--;

                        if (i == m-1) // ako e posleden
                            counter += m+1;
                    }
                }

            }
        }
       kolona++;
    }

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++)
            printf("%d ", matrica[i][j]);
        
        printf("\n");
    }

    return 0;
}
