#include <stdio.h>

int main()
{
    float r;
    scanf("%f", &r);

    printf("Ploshtina: %f, Perimetar: %f", r*r*3.14, 2*r*3.14);

    return 0;
}