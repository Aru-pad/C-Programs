//Sezione delle include

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definizione di tipo
typedef char N[30],C[30];


int Menu(int*);
int Leggi_INT(int[],int[],int,int);
char Leggi_Char(N[],C[],int,int);
int Modifica_Eta(int[],int[],int,int,int*);


int main()
{
    N Nome[50];
    C Cognome[50];
    int COD[50],Eta[50],CODS,Scelta,N,I,Flag;
    char NomeS[30];

    printf("Inserire il numero totale di dipendenti:");
    scanf("%d",&N);

    Leggi_INT(COD,Eta,I,N);

    Leggi_Char(Nome,Cognome,I,N);

    Scelta=Menu(&Scelta);

    while (Scelta!=4)
    {
        if (Scelta==1)
        {
            Modifica_Eta(COD,Eta,N,I,&Flag);
        }
    }


}

int Leggi_INT(int xCOD[],int xEta[],int xI,int xN)
{
    for (xI=0; xI<xN; xI++)
    {
        printf("\nInserire Codice e Eta' del dipendente\n\nCodice:");
        fflush(stdin);
        scanf("%d",&xCOD[xI]);
        printf("\nEta':");
        fflush(stdin);
        scanf("%d",&xEta[xI]);
        fflush(stdin);
    }
}

char Leggi_Char(N xNome[],C xCognome[],int xI,int xN)
{
    for (xI=0; xI<xN; xI++)
    {
        fflush(stdin);
        printf("\nInserire Nome e Cognome del dipendente\n\nNome:");
        fflush(stdin);
        gets(xNome[xI]);
        fflush(stdin);
        printf("\nCognome:");
        fflush(stdin);
        gets(xCognome[xI]);
        fflush(stdin);
    }
}

int Menu(int *xScelta)
{
    printf("\nScegli tra una delle seguenti operazioni:\n1-Modifica Eta'\n2-Cancellazione dipendenti\n3-Struttura locale\n4-Fine");
    scanf("&d",&*xScelta);

    while (*xScelta<1 || *xScelta>4)
    {
        printf("Scelta errata.");
        scanf("&d",&*xScelta);
    }

    return *xScelta;
}

int Modifica_Eta(int xCOD[],int xEta[],int xN,int xI,int *xFlag)
{
    int xxCOD,xTrovato;

    printf("\nInserire Codice del dipendente di cui modificare l'eta':");
    scanf("%d",&xxCOD);

    xTrovato=0;
    for (xI=0; xI<xN; xI++)
    {
        if (xCOD[xI]==xxCOD)
        {
            xTrovato=1;
            *xFlag=0;
        }
    }
}
