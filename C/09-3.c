#include <stdio.h>

int main() {

  int broj, obraten=0, ostatok;

  printf("Vnesi broj: ");
  scanf("%d", &broj);

  while (broj != 0) {
    ostatok = broj % 10;
    obraten = obraten * 10 + ostatok;
    broj /= 10;
  }
  printf("Obraten: %d", obraten);

  return 0;
}