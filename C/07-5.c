/* Program p07_08.c
   Rekurzivna funkcija za presmetuvanje na Fibonacci-eva niza */
#include <stdio.h>
 
long fibonacci( long n ); /* funkciski prototip */
 
/* funkcijata main go zapochnuva izvrshuvanjeto na programot */
int main()
{
   long result; /* fibonacci-eva vrednost */
   long number; /* broj vnesen od korisnikot */
 
   /* zemi cel broj od korisnikot */
   printf( "Vnesi cel broj: " );
   scanf( "%ld", &number );
 
   /* presmetaj fibonacci-eva niza za vneseniot broj */
   for(int i=0;i<=number;i++)
   {
        result = fibonacci( i );
        printf( "Fibonacci( %ld ) = %ld\n", i, result );
   }
   
   /* ispechati rezultat */
   
   
   return 0; /* uspeshen kraj */
 
} /* kraj main */
 
/* Rekurzivna definicija na funkcijata fibonacci */
long fibonacci( long n )
{
   /* osnoven sluchaj */
   if ( n == 0 || n == 1 ) {
      return n;
   } /* kraj if */
   else { /* rekurziven chekor */ 
      return fibonacci( n - 1 ) + fibonacci( n - 2 );
   } /* kraj else */
   
} /* kraj na funkciata fibonacci */
