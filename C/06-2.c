#include <stdio.h>
 
int main()
{ 
    int den, mesec, godina;
   
    printf("Vnesi datum: ");
    scanf("%d%*c%d%*c%d", &godina, &mesec, &den);
 
    switch (mesec)
    {
    case 1:
        printf("Vneseniot daum e %d januari %d godina", den, godina);
        break;
    case 2:
        printf("Vneseniot daum e %d februari %d godina", den, godina);
        break;
    case 3:
        printf("Vneseniot daum e %d mart %d godina", den, godina);
        break;
    case 4:
        printf("Vneseniot daum e %d april %d godina", den, godina);
        break;
    case 5:
        printf("Vneseniot daum e %d maj %d godina", den, godina);
        break;
    case 6:
        printf("Vneseniot daum e %d juni %d godina", den, godina);
        break;
    case 7:
        printf("Vneseniot daum e %d juli %d godina", den, godina);
        break;
    case 8:
        printf("Vneseniot daum e %d avgust %d godina", den, godina);
        break;
    case 9:
        printf("Vneseniot daum e %d septemvri %d godina", den, godina);
        break;
    case 10:
       printf("Vneseniot daum e %d oktomvri %d godina", den, godina);
        break;
    case 11:
        printf("Vneseniot daum e %d noemvri %d godina", den, godina);
        break;
    case 12:
        printf("Vneseniot daum e %d dekemvri %d godina", den, godina);
        break;

    default:
        printf("Vneseniot daum e nevaliden!");
        break;
    }
 
    return 0;
} 
