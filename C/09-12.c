#include <stdio.h>

int main() {

    int a1,a2,b1,b2,d1,d2;

    printf("a1x+a2y=d1\nb1x+b2y=d2\n");
    printf("Vnesi vrednost za a1, a2, d1: ");
    scanf("%d %d %d", &a1, &a2, &d1);
    printf("Vnesi vrednost za b1, b2, d2: ");
    scanf("%d %d %d", &b1, &b2, &d2);

    float determinanta = a1*b2 - a2*b1;
    if(determinanta != 0) {
        float x = (d1*b2 - a2*d2)/determinanta;
        float y = (a1*d2 - d1*b1)/determinanta;
        printf("Vrednosti za x = %.2f, y = %.2f\n", x, y);
    }else
        printf("Determinantite se 0\nnema reshenie ili ima beskonechno reshenija.\n"); 

    return 0;
}
