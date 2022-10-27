#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const char numbers_letters[37]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' '}; 

const char *m_numbers_letters[37] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "/"};

void voMorseCode(char fraza[])
{
    for (int i = 0; i < strlen(fraza); i++) {
        fraza[i] = toupper(fraza[i]);
    }
    
    for (int i=0; i<strlen(fraza); i++)
    {
        for(int j=0; j<37; j++)
        {
            if(fraza[i] == numbers_letters[j]) 
                printf("%s ", m_numbers_letters[j]);
        }
    }
}

void voObichenTekst(char fraza[])
{
    char *podelen;

    podelen = strtok(fraza, " ");

    while( podelen != NULL ) {
        for(int j=0; j<37; j++)
        {
            if(!strcmp(podelen, m_numbers_letters[j]))
                printf("%c", numbers_letters[j]);
        }
    
        podelen = strtok(NULL, " ");
    }
}

int main()
{
    char fraza[1000];

    fgets(fraza, sizeof fraza, stdin);
    
    voObichenTekst(fraza);
}