// Sezione delle include

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char PP[15],PT[15];

int main()
{
    PP ParPoe[30];
    PT ParTes[30];
    int POS[30];
    int I,N,C,PDO,POSPO,V,ERRP,ERRPT,G;
    char R;
    char SO[4];
    char ParIns[15];

    //Poesia
    printf("Inserire numero totale di parole della poesia: ");
    scanf("%d",&N);

       //Verifica N
    while (N<7 || N>30)
    {
        printf("\nInserire valore corretto.\n\nMinimo:7;\nMassimo:30\n");
        scanf("%d",&N);
    }

    printf("\nInserire poesia\n");

    for (I=0; I<N; I++)
    {
        scanf("%s",ParPoe[I]);
        strcpy(ParTes[I],ParPoe[I]);
    }

    //Oscuramento
    PDO=(15*N)/100;
    strcpy(SO,"***");
    for (C=0; C<PDO; C++)
    {
        POSPO=rand()%N;
        strcpy(ParTes[POSPO],SO);
        POS[C]=POSPO;
    }

    printf("\nContinuare?[S/N]");
    fflush(stdin);
    scanf("%c",&R);

    while (R=='S')
    {
     system("cls");

    //Visualizza poesia
    printf("Ecco la poesia\n\nLeggerela attentamente prima di procedere con il Test.\n\n");
    for (I=0; I<N; I++)
    {
        printf("%s ",ParPoe[I]);
    }
    printf("\n\nQuando si e' pronti ");
    system("pause");
    system("cls");

    //Test
    V=30;
    printf("\nEcco il test. \nInserire al posto dei simboli *** la parola mancante\n\n");

    //Visualizza Test
    for (I=0; I<N; I++)
    {
        printf("%s ",ParTes[I]);
        fflush(stdin);
    }
    ERRPT=0;
    for (C=0; C<PDO; C++)
    {
        POSPO=POS[C];
        ERRP=0;
        G=0;
        while (ERRP<3 && G==0)
        {
            printf("\nInserire la parola:");
            scanf("%s",ParIns);
            if (strcmp(ParIns,ParPoe[POSPO])==0)
            {
                G=1;
            }
            else
            {
                ERRP=ERRP+1;
                ERRPT=ERRP+1;
                V=V-1;
                if (ERRP!=3)
                {
                    printf("\nErrato. Ritenta");
                }
            }
        }
        if (ERRP==3)
        {
            printf("La parola corretta e' %s",ParPoe[POSPO]);
        }
    }

    //Visualizza voto
    V=V/3;
    printf("\n\nIl voto finale e' %d\n",V);
    printf("\n\nIl numero totale di errori fatti e':%d\n\n",ERRPT);
    system("pause");

    printf("\nRipetere il test?[S/N]");
    fflush(stdin);
    scanf("%c",&R);
  }
  return 0;
}
