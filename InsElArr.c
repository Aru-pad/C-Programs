// Sezione delle include

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Array[30];
    int I,C,POS,N,Trovato,Scelta,Flag,EL,ELP;

    printf("Inserire numero di elementi:");
    scanf("%d",&N);

    while (N<0 || N>30)
    {
        printf("\nIl numero di elementi non può superare 30.\nInserire valore corretto:");
        scanf("%d",&N);
    }

    for (I=0; I<N; I++)
    {
        printf("\nInserire elemento dell'array:");
        scanf("%d",&Array[I]);

         //Verifica insieme

        for (C=0; C<I; C++)
        {
            if (Array[I]==Array[C])
            {
                printf("\nElemento gia' presente.\nInserimento annulato");
                Array[I]=0;
            }
        }
    }
    printf("\nScegliere tra:\n1-Inserimento per posizione;\n1-Inserimento per elemento preceduto;\n3-Inserimento in coda\n\nScelta:");
    scanf("%d",&Scelta);
    while (Scelta<1 || Scelta>3)
    {
        printf("\nInserire scelta corretta:");
        scanf("%d",&Scelta);
    }
    if (Scelta==1)
    {
        //Inserimento per posizione

        if (N==30)
        {
            Flag=1;
        }
        else
        {
            printf("\nInserire posizione dove inserire l'elemento:");
            scanf("%d",&POS);
            if (POS<0 || POS>N)
            {
                Flag=2;
            }
            else
            {
                printf("\nInserire nuovo elemento da inserire nell'insieme:");
                scanf("%d",&EL);
                //Ricerca EL
                for (I=0; I<N; I++)
                {
                    if (Array[I]==EL)
                    {
                        printf("\nInserire un nuovo elemento non presente nell'insieme:");
                        scanf("%d",&EL);
                    }
                }
            }
            if (Array[POS]==0)
            {
                Array[POS]=EL;
            }
            else if (POS==N)
            {
                Array[POS]=EL;
            }
            else
            {
                //SHIFTDOWN
                for (I=N; I>=POS; I--)
                {
                        Array[I]=Array[I--];
                }
                Array[POS]=EL;
            }
            N++;
            Flag=3;
        }
        if (Flag==1)
        {
            printf("\nInserimento non riuscito. Array pieno");
        }
        else if (Flag==2)
        {
            printf("\nInserimento non riuscito. Posizione errata");
        }
        else printf("\nInserimento completato con successo");
    }
    else if (Scelta==2)
    {
        //Inserimento per elemento preceduto
        if (N==30)
        {
            Flag=1;
        }
        else
        {
        printf("\nInserire l'elemento che dovra' esser preceduto dal nuovo elemento:");
        scanf("%d",ELP);
        //Ricerca ELP
        for(I=0; I<N; I++)
        {

        }
    }
  }
}
