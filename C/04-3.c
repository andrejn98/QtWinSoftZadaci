/* Program p04_02.c
   Program koj pregmetuva prosek na klas
   so povtoruvanje kontrolirano od brojach */
#include <stdio.h>
 
/* pochnuva izvrshuvanjeto na prоgramot */
int main()
{
   int counter; /* brojach na vneseni oceni */
   int grade;   /* vrednost na ocena */
   int total;   /* suma na ocenite vneseni od korisnikot */
   float average; /* sredna vrednost na ocenite */
   
   /* inicijalizacija */
   total = 0;   /* inicijaliziraj total */
   
    scanf("%d", &counter);
    int temp=counter;

   /* procesiranje */
   while ( temp > 0 ) {     /* povtori 10 pati */
      printf( "Vnesi ocena: " ); /* prompt za vlez */
      scanf( "%d", &grade );     /* chitaj ocena od korisnikot */
      total = total + grade;     /* dodaj ja ocenata na total */
      temp--;     /* zgolemi go brojachot */
   } /* kraj na while */
   
   /* zavrshna faza */
   average = (float) total / counter; /* celobrojno delenje */
 
   printf( "Srednata vrednost na klasot e %.3f\n", average ); /* pechati rezultat */
 
   return 0; /* uspeshen kraj na programot */
 
} /* kraj na main */
