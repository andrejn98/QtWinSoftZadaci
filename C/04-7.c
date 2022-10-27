#include <stdio.h>

int main()
{
    int total=0, number=0;
    char temp;
    while(temp!='n'){
        printf("Vnesi broj: ");
        scanf("%d", &number);
        total+=number;
        printf("\nUshte? (d/n): ");
        scanf(" %c", &temp);
    }

    printf("Sumata e %d", total);
    return 0;
}