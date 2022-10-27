#include <stdio.h>

void selekcija(int niza[])
{
    int zameni, pozicija;
    for(int i=0;i<7;i++)
    {
        pozicija = i;
        for(int j=i+1;j<7;j++)
        {
            if(niza[pozicija]>niza[j])
                pozicija=j;
        }
        if(pozicija!=i)
        {
            zameni = niza[i];
            niza[i] = niza[pozicija];
            niza[pozicija] = zameni;
        }
    }
    printf("\n");
    for(int i=0;i<7;i++)
    {
        printf("%d ", niza[i]);
    }
}
// v) procesirackite kapaciteti na ova sortiranje se slicni
// kako so bubble sort zatoa shto i vo dvete sortiranja se koristi
// for vo for odnosno imaat kompleksnost O(n^2)
int main()
{
    int niza[7];
    
    for(int i=0;i<7;i++)
    {
        scanf("%d", &niza[i]);
    }

    for(int i=0;i<7;i++)
    {
        printf("%d ", niza[i]);
    }

    selekcija(niza);

    return 0;
}