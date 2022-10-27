#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
    char broj[14], kod[2]="", brojce[7]="";
    char *podelen;

    for(int i=0;i<14;i++)
    {
        scanf("%c", &broj[i]);
    }
    
    podelen = strtok(broj, " ");
    memmove(&podelen[0], &podelen[0 + 1], strlen(podelen)-0); // za da izbrishe karakter '('
    printf("%d\n", atoi(podelen));

    podelen = strtok(NULL, "-");
    strcat(brojce, podelen);
    podelen = strtok(NULL, "-");
    strcat(brojce, podelen);
    printf("%d\n", atol(brojce));

    return 0;
}
