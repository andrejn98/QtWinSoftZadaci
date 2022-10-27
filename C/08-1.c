#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int randInRange(int min, int max)
{
    return ( rand() % ( max - min ) ) + min;
}

enum DenoviMesec
{
    JANUARI=31,
    FEBRUARI=28,
    MART=31,
    APRIL=30,
    MAJ=31,
    JUNI=30,
    JULI=31,
    AVGUST=31,
    SEPTEMVRI=30,
    OKTOMVRI=31,
    NOEMVRI=30,
    DEKEMVRI=31,
};

int srednaVrednost(int mesec, int min, int max)
{
    int sredna=0;
    int denoviVoMesec[mesec];
    for(int i=0;i<mesec;i++)
    {
        denoviVoMesec[i]=randInRange(min, max);
        printf("%d ", denoviVoMesec[i]);
        sredna+=denoviVoMesec[i];
    }
    return sredna;
}

int main()
{
    int mesec;
    srand( time( NULL ) ); 
    printf("Vnesi broj na mesec: ");
    scanf("%d", &mesec);
    
    switch (mesec)
    {
        case 1:
            printf("\nSredna vrednost temperaturi vo Januari: %dC", srednaVrednost(JANUARI, -5, 9)/JANUARI);
            break;
        case 2:
            printf("\nSredna vrednost temperaturi vo Februari: %dC", srednaVrednost(FEBRUARI, -2, 12)/FEBRUARI);
            break;
        case 3:
            printf("\nSredna vrednost temperaturi vo Mart: %dC", srednaVrednost(MART, 2, 15)/MART);
            break;
        case 4:
            printf("\nSredna vrednost temperaturi vo April: %dC", srednaVrednost(APRIL, 4, 18)/APRIL);
            break;
        case 5:
            printf("\nSredna vrednost temperaturi vo Maj: %dC", srednaVrednost(MAJ, 7, 20)/MAJ);
            break;
        case 6:
            printf("\nSredna vrednost temperaturi vo Juni: %dC", srednaVrednost(JUNI, 10, 27)/JUNI);
            break;
        case 7:
            printf("\nSredna vrednost temperaturi vo Juli: %dC", srednaVrednost(JULI, 14, 34)/JULI);
            break;
        case 8:
            printf("\nSredna vrednost temperaturi vo Avgust: %dC", srednaVrednost(AVGUST, 16, 32)/AVGUST);
            break;
        case 9:
            printf("\nSredna vrednost temperaturi vo Septemvri: %dC", srednaVrednost(SEPTEMVRI, 14, 29)/SEPTEMVRI);
            break;
        case 10:
            printf("\nSredna vrednost temperaturi vo Oktomvri: %dC", srednaVrednost(OKTOMVRI, 13, 22)/OKTOMVRI);
            break;
        case 11:
            printf("\nSredna vrednost temperaturi vo Noemvri: %dC", srednaVrednost(NOEMVRI, 7, 17)/NOEMVRI);
            break;
        case 12:
            printf("\nSredna vrednost temperaturi vo Dekemvri: %dC", srednaVrednost(DEKEMVRI, 3, 14)/DEKEMVRI);
            break;
        default:
            printf("Vneseniot daum e nevaliden!");
            break;
    }
  
    return 0;
}