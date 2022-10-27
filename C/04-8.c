#include <stdio.h>

int main()
{
    int counter=5, product, quantity;
    float total=0;
    while(counter!=0){
        printf("\nVnesete proizvod i kolichina: ");
        scanf("%d %d", &product, &quantity);
        counter--;

        switch (product) {
            case 1:
                printf("\nProizvod: %d, vkupna cena: %.1f", product, 50.5*quantity);
                total+=50.5*quantity;
                break;
            case 2:
                printf("\nProizvod: %d, vkupna cena: %.1f", product, 45.6*quantity);
                total+=45.6*quantity;
                break;
            case 3:
                printf("\nProizvod: %d, vkupna cena: %.1f", product, 32.8*quantity);
                total+=32.8*quantity;
                break;
            case 4:
                printf("\nProizvod: %d, vkupna cena: %.1f", product, 65.3*quantity);
                total+=65.3*quantity;
                break;
            case 5:
                printf("\nProizvod: %d, vkupna cena: %.1f", product, 20.0*quantity);
                total+=20.0*quantity;
                break;
            default:
                break;
        }

    }

    printf("\nVkupna cena za site produkti: %.2f", total);

    return 0;
}