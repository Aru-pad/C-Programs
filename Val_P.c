//Sezione delle include

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Sezione dichiarativa

    int Cod_1,Cod_2;
    printf("Inserire codici dei due pazienti\n");
    printf("Primo paziente:");
    scanf("%d",&Cod_1);
    printf("\nSecondo paziente:");
    scanf("%d",&Cod_2);

    //Sezione esecutiva

    while(Cod_1==Cod_2)
    {
        printf("\nErrore dei codici inseriti: codici uguali.\nReinserire i dati relativi ai codici per favore usando dei codici univoci.");
        printf("\nPrimo paziente:");
        scanf("%d",&Cod_1);
        printf("\nSecondo paziente:");
        scanf("%d",&Cod_2);
    }
    float P1,P2;
    printf("\nInserire il peso di entrambi i pazienti");
    printf("\nPrimo paziente:");
    scanf("%f",&P1);
    printf("\nSecondo paziente:");
    scanf("%f",&P2);
    while(P1<0||P2<0)
    {
        printf("\nErrore del peso inserito: peso minore di 0.\nReinserire i dati relativi al peso usando dei valori validi.");
        printf("\nPrimo paziente:");
        scanf("%f",&P1);
        printf("\nSecondo paziente:");
        scanf("%f",&P2);
    }
}
