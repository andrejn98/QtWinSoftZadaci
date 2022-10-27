#include <stdio.h>
#include <stdlib.h>

/* samo-referencirachka struktutra */
struct listNode {            
   int broj;
   struct listNode *nextPtr; /* pokazhuvach do sledniot jazol */ 
}; /* kraj na strukturata listNode */

typedef struct listNode ListNode; /* sinonim za strukturata listNode */
typedef ListNode *ListNodePtr; /* sinonim za ListNode* */

/* prototipovi */
void vnesi( ListNodePtr *sPtr, int broj );
void printList( ListNodePtr currentPtr );
void sortOpagjanje( ListNodePtr currentPtr );
void sortRastenje( ListNodePtr currentPtr );
int isEmpty (ListNodePtr sPtr);
int brisi( ListNodePtr *cursPtrrentPtr, int broj );
void instructions( void );

int main()
{ 
   ListNodePtr startPtr = NULL; /* vo pochetokot nema jazli */
   int choice; /* korisnichki izbor */
   int broj; // korisnichki vnesen broj

   instructions(); /* pechati meni */
   printf( "? " );
   scanf( "%d", &choice );

   /* vrti dodeka korisnikot ne vnese 3 */
   while ( choice != 5 ) { 

      switch ( choice ) { 

         case 1:
            printf( "Vnesi broj: " );
            scanf( "\n%d", &broj );
            vnesi( &startPtr, broj ); /* vnesi element vo listata */
            printList( startPtr );
            break;
         case 2:
            if ( !isEmpty( startPtr ) ) { 
               printf( "Vnesi broj za brishenje: " );
               scanf( "\n%d", &broj );

               if ( brisi( &startPtr, broj ) ) {
                  printf( "%d izbrishan.\n", broj );
                  printList( startPtr );
               }
               else
                  printf( "%d ne e vo listata.\n\n", broj );
            }else
               printf( "Listata e prazna.\n\n" );
            break;
         case 3:
            if ( !isEmpty( startPtr ) ) { 
                sortRastenje( startPtr );
                printList( startPtr );
            }else
               printf( "Listata e prazna.\n\n" );
            break;
        case 4:
            if ( !isEmpty( startPtr ) ) { 
                sortOpagjanje( startPtr );
                printList( startPtr );
            }else
               printf( "Listata e prazna.\n\n" );
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
      "   2 za brishenje na element od listata.\n"
      "   3 za sortiranje rastecki.\n"
      "   4 za sortiranje opagjacki.\n"
      "   5 za kraj.\n" );
} /* kraj na funkcijata instructions */

/* Vnesi nova vrednost vo listata sortiranor */
void vnesi( ListNodePtr *sPtr, int broj )
{ 
   ListNodePtr newPtr;      /* pointer do nov jazel */
   ListNodePtr previousPtr; /* pokazhuvach do prethodniot jazel vo listata */
   ListNodePtr currentPtr;  /* pokazhuvach do tekovniot jazel */

   newPtr = malloc( sizeof( ListNode ) ); /* sozdadi jazel */

   if ( newPtr != NULL ) { /* ako ima mesto */
      newPtr->broj = broj;
      newPtr->nextPtr = NULL; /* jazelot ne e povrzan so drug jazel */

      previousPtr = NULL;
      currentPtr = *sPtr;

      /* vrti dodeka ne ja najdesh tochnata pozicija vo listata */
      while ( currentPtr != NULL) { 
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
      printf( "%d ne e vnesen. Nema dovolno memorija.\n", broj );
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
         printf( "%d --> ", currentPtr->broj );
         currentPtr = currentPtr->nextPtr;   
      } /* kraj while */

      printf( "NULL\n\n" );
   } /* kraj else */

} /* kraj na funkcijata printList */

/* Vrati 1 ako listata e prazna, 0 inaku */
int isEmpty( ListNodePtr sPtr )
{ 
   return sPtr == NULL;

} /* kraj na funkcijata isEmpty */

/* Izbrishi element od lista */
int brisi( ListNodePtr *sPtr, int broj )
{ 
   ListNodePtr previousPtr; /* pokazhuvach do prethodniot element vo listata */
   ListNodePtr currentPtr;  /* pokazhuvach do tekovniot jazel */
   ListNodePtr tempPtr;     /* pokazhuvach do privremen element */

   /* izbrishi go prviot jazel */
   if ( broj == ( *sPtr )->broj) { 
      tempPtr = *sPtr; /* chuvaj go jazelot shto se brishe */
      *sPtr = ( *sPtr )->nextPtr; /* sredi ja listata */
      free( tempPtr ); /* oslobodi go nepotrebniot jazel */
      return broj;
   } /* kraj if */
   else { 
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      /* vrti dodeka ne ja najdesh tochnata pozicija */
      while ( currentPtr != NULL && currentPtr->broj != broj ) { 
         previousPtr = currentPtr;         /* odi do ...   */
         currentPtr = currentPtr->nextPtr; /* ... sledniot jazel */  
      } /* kraj while */

      /* izbrishi go jazelot na currentPtr */
      if ( currentPtr != NULL ) { 
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         return broj;
         free( tempPtr );
      } /* kraj if */
     
   } /* kraj else */
    return 0;
} /* kraj na funkcijata delete */

void sortOpagjanje( ListNodePtr currentPtr )
{
    ListNodePtr nextPtr;
    int temp;
    while(currentPtr!=NULL)
    {
        nextPtr = currentPtr->nextPtr;
        while(nextPtr!=NULL){
            if(currentPtr->broj < nextPtr->broj){
                temp = currentPtr->broj;   
                currentPtr->broj = nextPtr->broj;
                nextPtr->broj = temp;
            }
            nextPtr = nextPtr->nextPtr;
        }
        currentPtr = currentPtr->nextPtr;
    }
}

void sortRastenje( ListNodePtr currentPtr )
{
    ListNodePtr nextPtr;
    int temp;
    while(currentPtr!=NULL)
    {
        nextPtr = currentPtr->nextPtr;
        while(nextPtr!=NULL){
            if(currentPtr->broj > nextPtr->broj){
                temp = currentPtr->broj;   
                currentPtr->broj = nextPtr->broj;
                nextPtr->broj = temp;
            }
            nextPtr = nextPtr->nextPtr;
        }
        currentPtr = currentPtr->nextPtr;
    }
}