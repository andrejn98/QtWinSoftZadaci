#include <stdio.h>
#include <stdlib.h>

/* samo-referencirachka struktutra */
struct listNode {            
   int broj;
   char karakter; /* sekoj listNode sodrzhi karakter */
   struct listNode *nextPtr; /* pokazhuvach do sledniot jazol */ 
}; /* kraj na strukturata listNode */

typedef struct listNode ListNode; /* sinonim za strukturata listNode */
typedef ListNode *ListNodePtr; /* sinonim za ListNode* */

/* prototipovi */
void vnesi( ListNodePtr *sPtr, int broj, char karakter );
void pecatiListaNanazad( ListNodePtr currentPtr);
void printList( ListNodePtr currentPtr );
void instructions( void );

int main()
{ 
   ListNodePtr startPtr = NULL; /* vo pochetokot nema jazli */
   int choice; /* korisnichki izbor */
   int broj; // korisnichki vnesen broj
   char karakter;  /* korisnichki vnesen karakter */

   instructions(); /* pechati meni */
   printf( "? " );
   scanf( "%d", &choice );

   /* vrti dodeka korisnikot ne vnese 3 */
   while ( choice != 3 ) { 

      switch ( choice ) { 

         case 1:
            printf( "Vnesi broj i karakter: " );
            scanf( "\n%d %c", &broj, &karakter );
            vnesi( &startPtr, broj, karakter ); /* vnesi elementi vo listata */
            printList( startPtr );
            break;
         case 2:
            pecatiListaNanazad( startPtr );
            break;
         default:
            printf( "Greshen izbor.\n\n" );
            instructions();
            break;
      
      } /* kraj switch */

      printf( "\n? " );
      scanf( "%d", &choice );
   } /* kraj while */

   printf( "Kraj.\n" );
   
   return 0; /* uspeshen kraj */

} /* kraj main */

/* ispechati gi instrukciite za korisnikot */
void instructions( void )
{ 
   printf( "Vnesi izbor:\n"
      "   1 za vnesuvanje element vo lista.\n"
      "   2 za pechatenje na listata nanazad.\n"
      "   3 za kraj.\n" );
} /* kraj na funkcijata instructions */

/* Vnesi nova vrednost vo listata sortiranor */
void vnesi( ListNodePtr *sPtr, int broj, char karakter )
{ 
   ListNodePtr newPtr;      /* pointer do nov jazel */
   ListNodePtr previousPtr; /* pokazhuvach do prethodniot jazel vo listata */
   ListNodePtr currentPtr;  /* pokazhuvach do tekovniot jazel */

   newPtr = malloc( sizeof( ListNode ) ); /* sozdadi jazel */

   if ( newPtr != NULL ) { /* ako ima mesto */
      newPtr->broj = broj;
      newPtr->karakter = karakter; /* stavi vrednost vo jazelot */
      newPtr->nextPtr = NULL; /* jazelot ne e povrzan so drug jazel */

      previousPtr = NULL;
      currentPtr = *sPtr;

      /* vrti dodeka ne ja najdesh tochnata pozicija vo listata */
      while ( currentPtr != NULL && karakter > currentPtr->karakter ) { 
         previousPtr = currentPtr;          /* odi do ...   */
         currentPtr = currentPtr->nextPtr;  /* ... sledniot jazel */
      } /* kraj while */

      /* vnesi nov jazel na pochetokot na listata */
      if ( previousPtr == NULL ) { 
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      } /* kraj if */
      else { /* vnesi nov jazel megju previousPtr i currentPtr */
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      } /* kraj else */
   
   } /* kraj if */
   else {
      printf( "%c ne e vnesen. Nema dovolno memorija.\n", karakter );
   } /* kraj else */

} /* kraj na funkcijata insert */

/* Ispechati ja listata */
void printList( ListNodePtr currentPtr )
{ 

   /* ako listata e prazna */
   if ( currentPtr == NULL ) {
      printf( "Listata e prazna.\n\n" );
   } /* kraj if */
   else { 
      printf( "Listata e:\n" );

      /* dodeka ne e kraj na listata */
      while ( currentPtr != NULL ) { 
         printf( "%d%c --> ", currentPtr->broj, currentPtr->karakter );
         currentPtr = currentPtr->nextPtr;   
      } /* kraj while */

      printf( "NULL\n\n" );
   } /* kraj else */

} /* kraj na funkcijata printList */

void pecatiListaNanazad( ListNodePtr currentPtr )
{
    if (currentPtr == NULL){
        return;
    }
    pecatiListaNanazad(currentPtr->nextPtr);
 
    printf("%d%c ", currentPtr->broj, currentPtr->karakter);
}