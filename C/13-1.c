#include <stdio.h>

struct hardware { 
   int kod;
   char imeDel[25];
   int kolichina;
   double cena;
};

int enterChoice(void);
void prikaziDelovi(FILE *readPtr);
void prodazhba(FILE *readPtr);
void azhurirajDel(FILE *fPtr);
void novDel(FILE *fPtr);
void izbrishiDel(FILE *fPtr);

int main()
{ 
   FILE *cfPtr;
   int choice;

   if((cfPtr = fopen("hardware.dat", "rb+")) == NULL)
      printf("Datotekata ne mozhe da se otvori.\n");
   else{ 

      while((choice = enterChoice()) != 6) { 

         switch(choice){ 

            case 1:
               prikaziDelovi(cfPtr);
               break;
            case 2:
               prodazhba(cfPtr);
               break;
            case 3:
               novDel(cfPtr);
               break;
            case 4:
               azhurirajDel(cfPtr);
               break;
            case 5:
               izbrishiDel(cfPtr);
               break;
            default:
               printf("Greshen izbor\n");
               break;
           }
      }

      fclose(cfPtr);
   }
 
   return 0;
}

void prikaziDelovi(FILE *readPtr)
{
    printf("%-8s%-16s%-11s%10s\n", "Kod", "Ime na del",
        "Kolichina", "Cena");

    struct hardware hardware = {0, "", 0, 0.0};
    
    while(!feof( readPtr)){ 
        fread(&hardware, sizeof(struct hardware), 1, readPtr);

        if(hardware.kod != 0){
        printf("%-8d%-16s%9d%12.2lf\n", 
            hardware.kod, hardware.imeDel, 
            hardware.kolichina, hardware.cena);
        }
    }


}

void prodazhba(FILE *readPtr)
{ 
   int kod, kolichina;

   struct hardware hardware = {0, "", 0, 0.0};

   printf("Vnesi kod na delot za prodazba: ");
   scanf("%d", &kod);

   fseek(readPtr, (kod - 1) * sizeof(struct hardware), SEEK_SET);

   fread(&hardware, sizeof( struct hardware ), 1, readPtr);

   if (hardware.kod == 0) 
      printf("Delot so kod %d ne postoi.\n", kod);
   else {
      printf("%-8d%-16s%9d%12.2lf\n\n", 
         hardware.kod, hardware.imeDel, 
         hardware.kolichina, hardware.cena);
      
      printf("Vnesete kolichina za prodazhbata\n?");
      scanf("%d", &kolichina);

      if(hardware.kolichina>0){
         if(hardware.kolichina>=kolichina){
            hardware.kolichina -= kolichina;

            printf("%-8d%-16s%9d%12.2lf\n", 
               hardware.kod, hardware.imeDel, 
               hardware.kolichina, hardware.cena);
            
            fseek(readPtr, (kod - 1) * sizeof(struct hardware), SEEK_SET);

            fwrite(&hardware, sizeof(  struct hardware), 1, readPtr);
         }else{
            printf("Nema dovolno parchinja na zaliha za taa prodazhba.\n");
         }
      }else{
         printf("Delot ne e na zaliha.\n");
      }
   }

}

void novDel(FILE *fPtr)
{ 
    struct hardware hardware = {0, "", 0, 0.0};

    int kod;

    printf("Vnesi kod: ");
    scanf("%d", &kod);

    fseek(fPtr, (kod - 1) * sizeof(struct hardware), SEEK_SET);

    fread(&hardware, sizeof(struct hardware), 1, fPtr);

    if (hardware.kod != 0)
        printf("Delot #%d vekje e sozdaden.\n", hardware.kod);
    else{
        hardware.kod = kod;
        printf("Vnesete ime na del, kolichina i cena na del\n?");
        scanf("%s%d%lf", &hardware.imeDel, &hardware.kolichina, &hardware.cena);

        fseek(fPtr, (hardware.kod - 1) * sizeof(struct hardware), SEEK_SET);

        fwrite(&hardware, sizeof(struct hardware), 1, fPtr);
    }

}

void azhurirajDel(FILE *fPtr)
{ 
   int kod;

   struct hardware hardware = {0, "", 0, 0.0};

   printf("Vnesi kod na del za azhuriranje: ");
   scanf("%d", &kod);

   fseek(fPtr, (kod - 1) * sizeof(struct hardware), SEEK_SET);

   fread(&hardware, sizeof(struct hardware), 1, fPtr);

   if (hardware.kod == 0)
      printf("Ne postoi del so kod %d\n", kod);
   else {
        printf("%-8d%-16s%-11d%10.2f\n\n", 
            hardware.kod, hardware.imeDel, 
            hardware.kolichina, hardware.cena);
      
        printf("Vnesete ime na del, kolichina i cena na del\n?");
        scanf("%s%d%lf", &hardware.imeDel, &hardware.kolichina, &hardware.cena);
            
        printf("%-8d%-16s%9d%12.2lf\n", 
            hardware.kod, hardware.imeDel, 
            hardware.kolichina, hardware.cena);
        
        fseek(fPtr, (kod - 1) * sizeof(struct hardware), SEEK_SET);

        fwrite(&hardware, sizeof(struct hardware), 1, fPtr);
   }

}

void izbrishiDel(FILE *fPtr)
{ 

   struct hardware hdware;
   struct hardware hardware = {0, "", 0, 0.0}; 
   
   int kod;

   printf("Vnesi kod na delot za brishenje: ");
   scanf("%d", &kod);

   fseek(fPtr, (kod - 1) * sizeof(struct hardware), SEEK_SET);

   fread(&hdware, sizeof(struct hardware), 1, fPtr);

   if (hdware.kod == 0)
      printf( "Delot so kod %d ne postoi.\n", kod );
   else{
      if(hdware.kolichina != 0)
      {
         printf( "Delot e seushte na zaliha, nemozhe da se izbrishe.\n");
      }else
      {
         fseek(fPtr, (kod - 1) * sizeof(struct hardware), SEEK_SET);

         fwrite(&hardware, sizeof(struct hardware), 1, fPtr);
      }
   }

}

int enterChoice(void)
{ 
   int menuChoice;

   printf( "\nVnesi izbor\n"
      "1 - Izlistaj delovi\n"
      "2 - Prodazhba\n"
      "3 - Dodadi nov del\n"
      "4 - Azhuriraj del\n"
      "5 - Izbrishi del\n"
      "6 - Kraj na programot\n? " );

   scanf( "%d", &menuChoice );

   return menuChoice;
}
