#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void proveriMesec(char *podelen)
{
    int x=atoi(podelen);
    if(x==1)
        printf("januari");
    else if(x==2)
        printf("februari");
    else if(x==3)
        printf("mart");
    else if(x==4)
        printf("april");
    else if(x==5)
        printf("maj");
    else if(x==6)
        printf("juni");
    else if(x==7)
        printf("juli");
    else if(x==8)
        printf("avgust");
    else if(x==9)
        printf("septemvri");
    else if(x==10)
       printf("oktomvri");
    else if(x==11)
        printf("noemvri");
    else if(x==12)
        printf("dekemvri");
}

int main()
{
    char datum[10];
    char *podelen;

    while(1)
    {
        for(int i=0;i<10;i++)
        {
            scanf("%c", &datum[i]);
        }
        podelen = strtok(datum, "/");
        printf("%d ", atoi(podelen));

        podelen = strtok(NULL, "/");
        proveriMesec(podelen);

        podelen = strtok(NULL, "/");
        printf(" %d", atoi(podelen));
        printf("\n");
    }

    return 0;
}