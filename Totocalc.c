// Sezione delle include

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definizione di tipo
typedef char S[28],P[14],SV[14],CS[20],CV[14],CPF[20];

int main()
{

    /*Initialized random number generator */
    srand(time(NULL));

    //Definizione del valore del tipo definito
    S NS[20];
    P Pron[2];
    CV ColVinc[2];
    SV SqVinc[20];
    CPF ClPuFin;
    CS ClSq[20];

    int I,Partite,Min,C,Trovato,Cont,PF,CNS,N,Var,PS,control;
    char GP[20];

    Partite=2;


   for (I=0; I<4; I++)
    {
        printf("\nInserire il nome della squadra che gioca in casa: ");
        fflush(stdin);
        gets(NS[I]);
        fflush(stdin);

        I++;

        printf("\nInserire il nome della squadra che gioca fuori casa: ");
        fflush(stdin);
        gets(NS[I]);
        fflush(stdin);

        //RicercaSq

        Trovato=0;
        for (C=0; Trovato==0 && C<I; C++)
        {
            if (strcmp(NS[C],NS[I])==0)
            {
                Trovato=1;
            }
        }
        if (Trovato==1)
        {
            printf("\nQuesta squadra %s e' gia' stata inserita.\nInserire una nuova:",NS[I]);
            fflush(stdin);
            gets(NS[I]);
            fflush(stdin);
        }
        C=0;

        printf("\nInserire il vostro pronostico riguardante la partita che si svolgere con le due squadre appena inserite:\n1-Vincita Squadra che gioca in casa\nX-Pareggio\n2-Vincita Squadra che gioca fuori casa\n");
        scanf("%c",&Pron[I]);
        while (Pron[I]!='1' && Pron[I]!='2' && Pron[I]!='X')
        {
            printf("\nPronostico errato. Reinserire pronostico corretto:\n1-Vincita Squadra che gioca in casa\nX-Pareggio\n3-Vincita Squadra che gioca fuori casa\n");
            fflush(stdin);
            scanf("%c",&Pron[I]);
        }
        system("cls");
    }
    printf("\nInserire il giorno della partita: ");
    scanf("%s",GP);
    system("cls");

    printf("\nE' arrivato il giorno dell'incontro!\n%s\n",GP);
    system("pause");
    Min=3;
    CNS=0;
    for (I=0; I<Partite; I++)
    {
        printf("\nIncontro tra le due squadre:%s-%s",NS[CNS],NS[CNS+1]);
        for (C=0; C<Min; C++)
        {
            PS=rand()%1+1;
            printf("\n\nInfo:\n1-Sta vincendo %s\n2-Pareggio tra le due squadre\n3-Sta vincendo %s\n\nAttuale situazione:%d\n",NS[CNS],NS[CNS+1],PS);
            system("pause");
        }
        if (PS==1)
        {
            ColVinc[I]=49;
            printf("\nVince %s",NS[CNS]);
            strcpy(SqVinc[I],NS[CNS]);
        }
        else if (PS==2)
        {
            ColVinc[I]=88;
            printf("\nParita'!");
        }
        else
        {
            ColVinc[I]=50;
            printf("\nVince %s",NS[CNS+1]);
            strcpy(SqVinc[I],NS[CNS+1]);
        }
        I++;
        CNS=CNS+2;
        system("cls");
    }
    printf("\nTermine gara!\n\nCalcolo punteggio realizzato in corso...");

    PF=0;
    for (I=0;I<Partite;I++)
    {
        control=strcmp(Pron[I],ColVinc[I]);
        if (control==0)
        {
            PF++;
        }
    }
    if (PF==14)
    {
        printf("\n\n$$$$JACKPOT!!!!$$$$");
    }
    else if (PF==13 || PF==12)
    {
        printf("\nCongratulazioni!\nHai vinto!!!\nPunteggio realizzato:%d",PF);
    }
    else
    {
        printf("\nHai perso:(\nAndra' meglio la prossima volta!:)\nPunteggio realizzato:%d",PF);
    }
    //Classifica
    N=20;
    printf("\nInserimento classifica prima delle partite");
    for (I=0; I<N; I++)
    {
        printf("\nInserire il nome della Squadra della classifica di serie A: ");
        fflush(stdin);
        gets(ClSq[I]);
        fflush(stdin);

        //RicercaCSq

        Trovato=0;
        for (C=0; Trovato==0 && C<I; C++)
        {
            if (strcmp(ClSq[I],ClSq[C])==0)
            {
                Trovato=1;
            }
        }

        if (Trovato==1)
        {
            printf("Questa squadra' %s e' gia' stata inserita.\nInserirne una nuova:",ClSq[I]);
            fflush(stdin);
            gets(ClSq[I]);
            fflush(stdin);
        }
        printf("\nInserire il punteggio di tale Squadra: ");
        fflush(stdin);
        scanf("%d",&ClPuFin[I]);
        fflush(stdin);
    }
    printf("\n\nAggiornamento punteggio classifica...");
    for (I=0;I<N; I++)
    {
        Trovato=0;
        Cont=0;
        while (Cont!=Partite && Trovato==0)
        {
            Var=strcmp(ClSq[I],SqVinc[Cont]);
            if (Var==0)
            {
                Trovato=1;
            }
            else
            {
                Cont++;
            }
        }
        if (Trovato==1)
        {
            ClPuFin[I]=ClPuFin[I]+3;
        }
    }
    for (I=0; I<20; I++)
    {
        printf("\n%s %d\n",ClSq[I],ClPuFin[I]);
        system("pause");
    }
        return 0;
}
