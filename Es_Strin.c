// Sezione delle include

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Sezione dichiarativa

    char parola1[10];
    char parola2[15];
    char np[35];
    char cp[15];
    int c;

    // Sezione esecutiva

    printf("Inserire prima parola:");
    scanf("%s",parola1);
    printf("\nInserire seconda parola:");
    scanf("%s",parola2);

    c=strcmp(parola1,parola2);
    if (c==0)
    {
        printf("\n\nLe parole sono uguali:\n%s\n%s\n\n",parola1,parola2);
        system("pause");
    }
    else if (c<0)
    {
        printf("\n\nPrima parola inserita:%s\nSeconda parola inserita:%s\n\n",parola1,parola2);
        system("pause");
    }
    else
    {
        printf("\n\nSeconda parola inserita:%s\nPrima parola inserita:%s\n\n",parola2,parola1);
        system("pause");
    }
    strcpy(cp,parola1);
    strcpy(parola1,parola2);
    strcpy(parola2,cp);
    printf("\n%s %s\n\n",parola1,parola2);
    system("pause");
    strcpy(np,parola2);
    strcat(np," ");
    strcat(np,parola1);
    printf("\n%s\n\n",np);
    system("pause");
    return 0;
}
