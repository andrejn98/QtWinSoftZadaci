#include <stdio.h>

int main()
{
    int broj;
    scanf("%d", &broj);
    if(broj>=0 && broj<=9999){
        do{
            if (broj >= 1000){

                printf("M");
                broj -= 1000;

            }else if (broj >= 900){

                printf("CM");
                broj -= 900;

            }else if (broj >= 500){    

                printf("D");
                broj -= 500;

            }else if (broj >= 400){

                printf("CD");
                broj -= 400;

            }else if (broj >= 100){

                printf("C");
                broj -= 100;

            }else if (broj >= 90){

                printf("XC");
                broj -= 90;

            }else if (broj >= 50){

                printf("L");
                broj -= 50;
                                                                     
            }else if (broj >= 40){

                printf("XL");
                broj -= 40;

            }else if (broj >= 10){

                printf("X");
                broj -= 10;

            }else if (broj >= 9){

                printf("IX");
                broj -= 9;

            }else if (broj >= 5){

                printf("V");
                broj -= 5;

            }else if (broj >= 4){

                printf("IV");
                broj -= 4;                

            }else if (broj >= 1){

                printf("I");
                broj -= 1;

            }
        }while(broj!=0);

    }else{
        printf("Treba da vnesete najmnogu 4 cifren broj!");
    }

    return 0;
}