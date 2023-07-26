//Sezione delle include

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Sezione dichiarativa

    char A;
    printf("Inserire carattere ");
    scanf("%c",&A);

    //Sezione di verifica

    if (A>=48&&A<=57)
    {
        printf("E' un una cifra numerica \n");
        system("pause");
    }
    else
    {
        if (A>=65&&A<=90)
        {
            printf("E' una lettera maiuscola \n");
            system("pause");
        }
        else
        {
            if (A>=97&&A<=122)
            {
                printf("E' una lettera minuscola \n");
                system("pause");
            }
            else
            {
                printf("E' un altro genere di carattere \n");
                system("pause");
            }
        }
    }
    return 0;
}
