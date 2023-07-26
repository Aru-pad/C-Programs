// Sezione delle include

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int Num[30];
    int NA[30];
    int AP[30];
    int I,N,Scelta1,Scelta2;

    //Leggi Array
    printf("Inserire il numero di dati presenti nell'insieme:");
    scanf("%d",&N);
    for (I=0; I<N; I++)
    {
        printf("\nInserire dato:");
        scanf("%d",&Num[I]);
    }
    printf("\nScegliere tra:\n1-Cancella tutte le istanze;\n2-Cancella prima istanza;\n3-Visualizza l'insieme;\n4-Ricerca Binaria\n5-Termine programma");
    scanf("%d",&Scelta1);
    while (Scelta1>=1 && Scelta1<=4)
    {
        if (Scelta1==1)
        {
            //Cancella TI
            printf("\nScegliere tipo di cancellazione:\n1-Tramite Nuovo Insieme;\n2-Logicamente");
            scanf("%d",&Scelta2);
            while (Scelta2<1 || Scelta2>2)
            {
                printf("\nScelta errata. Porre una scelta corretta:");
                scanf("%d",&Scelta2);
            }
        }
    }
}
