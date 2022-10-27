#include <stdio.h>

int main()
{
    char bukvi[4];
    printf("vnesi pet bukvi\nprva bukva: "); 
    scanf(" %c", &bukvi[0]);

    printf("\nvtora bukva: "); 
    scanf(" %c", &bukvi[1]);

    printf("\ntreta bukva: "); 
    scanf(" %c", &bukvi[2]);

    printf("\nchetvrta bukva: "); 
    scanf(" %c", &bukvi[3]);

    printf("\npetta bukva: "); 
    scanf(" %c", &bukvi[4]);

    printf("\nSe dobi: %c%c%c%c%c", bukvi[4], bukvi[2], bukvi[1], bukvi[0], bukvi[3]);

    return 0;
}