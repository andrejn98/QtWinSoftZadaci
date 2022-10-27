#include <stdio.h>
#include <math.h>

int main()
{
    float n, a;
    printf("Vnesete broj na strani i dolzhina na edna strana: ");
    scanf("%f %f", &n, &a);
    float A = (a * a * n) / (4 * tan((180 / n) * 3.14159 / 180));
    float P = n*a;
    printf("Perimetarot iznesuva: %.2f, a ploshtinata: %.2f", P, A);

    return 0;
}