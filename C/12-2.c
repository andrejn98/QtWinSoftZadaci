#include <stdio.h>

void prevtriBitovi( unsigned vrednost )
{ 
   unsigned c, pechatiMaska = 1 << 31;
 
   for(c=1; c<=32; c++) 
   { 
      putchar(vrednost & pechatiMaska ? '1' : '0');
      vrednost <<= 1;
 
      if (c%8==0) {
         putchar(' ');
      }
   }
   putchar('\n');
}

int main()
{
    unsigned int x;
    scanf("%u", &x);
    prevtriBitovi(x);
    prevtriBitovi(~x);
}