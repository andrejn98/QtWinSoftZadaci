#include <stdio.h>

int vreme(int chas, int minuta, int sekunda);
 
int main()
{ 
    int chas, minuta, sekunda;
    scanf("%d %d %d", &chas, &minuta, &sekunda);
    printf("\n%d sekundi do 12 chasot", vreme(chas, minuta, sekunda));
 
    return 0;
} 

int vreme(int chas, int minuta, int sekunda)
{
    if(chas<=12)
    {
        int sekundi = chas*60*60 + minuta*60 + sekunda;
        return 12*60*60 - sekundi;
    }
    else
        return 0;
}