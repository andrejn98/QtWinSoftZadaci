#include <stdio.h>

int main()
{
    float temp, salary;
    while(1){
        printf("\nVnesi promet vo evra (-1 za kraj): ");
        scanf("%f", &temp);
        if(temp!=-1){
            salary = temp/100*9+200;
            printf("%.2f", salary);   
        }else
            break;
    }

    return 0;
}