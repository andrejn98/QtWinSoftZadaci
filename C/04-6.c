#include <stdio.h>

int main()
{
    int total=0, temp;
    while(1){
        scanf("%d", &temp);
        if(temp!=-1)
            total += temp;
        else
            break;
    }

    printf("%d", total);
    return 0;
}