// Sezione delle include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    // Sezione dichiarativa
    char S1[20],S2[20],S3[20],S4[20],SF1[20],SF2[20],SV[20];
    int PB1,PB2,PB3,PB4,PC1,PC2,PC3,PC4,F1,F2,F3,F4,R1,R2,FV,PBSF1,PBSF2,PCSF1,PCSF2,SFF1,SFF2;
    printf("Torneo di Calcio\n\nBenvenuti!\nInserire il nome delle 4 squadre per iniziare:\n\n1-");
    scanf("%s",S1);
    printf("\n2-");
    scanf("%s",S2);
    printf("\n3-");
    scanf("%s",S3);
    printf("\n4-");
    scanf("%s",S4);

    /* Initializes random number generator */
    srand(time(NULL));

    // Calcola Forza
    PB1=rand()%50+1;
    PC1=rand()%50+1;
    F1=PB1+PC1;
    F1=(100*F1)/100;

    PB2=rand()%50+1;
    PC2=rand()%50+1;
    F2=PB2+PC2;
    F2=(100*F2)/100;

    PB3=rand()%50+1;
    PC3=rand()%50+1;
    F3=PB3+PC3;
    F3=(100*F3)/100;

    PB4=rand()%50+1;
    PC4=rand()%50+1;
    F4=PB4+PC4;
    F4=(100*F4)/100;

    printf("\nLa forza delle squadre e' la corrispondente:\n\n1-%s=%d\n2-%s=%d\n3-%s=%d\n4-%s=%d\n",S1,F1,S2,F2,S3,F3,S4,F4);
    system("pause");

    // Sezione esecutiva

    // S1 VS S2
    printf("\n\nPrima partita: %s contro %s\n",S1,S2);
    system("pause");
    FV=F1-F2;
    if (FV<=10&&FV>=-10)
    {
        printf("\n\nVi e' un pareggio!\nVia con i rigori!!");

        // Rigori
        R1=rand()%5+1;
        R2=rand()%5+1;
        while (R1==R2)
        {
            printf("\n\nI rigori continuano!!!");
            R1=rand()%5+1;
            R2=rand()%5+1;
        }
        if (R1>R2)
        {
            strcpy(SF1,S1);
            PBSF1=PB1;
        }
        else
        {
            strcpy(SF1,S2);
            PBSF1=PB2;
        }
    }
    else if (F1>F2)
    {
        strcpy(SF1,S1);
        PBSF1=PB1;
    }
    else
    {
        strcpy(SF1,S2);
        PBSF1=PB2;
    }
    printf("\n\nLa squadra vincitrice della partita e':%s\n",SF1);
    system("pause");

    // S3 VS S4
    printf("\n\nSeconda partita: %s contro %s\n",S3,S4);
    system("pause");
    FV=F3-F4;
    if (FV<=10&&FV>=-10)
    {
        printf("\n\nVi e' un pareggio!\nVia con i rigori!!");

        // Rigori
        R1=rand()%5+1;
        R2=rand()%5+1;
        while (R1==R2)
        {
            printf("\n\nI rigori continuano!!!");
            R1=rand()%5+1;
            R2=rand()%5+1;
        }
        if (R1>R2)
        {
            strcpy(SF2,S3);
            PBSF2=PB3;
        }
        else
        {
            strcpy(SF2,S4);
            PBSF2=PB4;
        }
    }
    else if (F3>F4)
    {
        strcpy(SF2,S3);
        PBSF2=PB3;
    }
    else
    {
        strcpy(SF2,S4);
        PBSF2=PB4;
    }
    printf("\n\nLa squadra vincitrice della partita e':%s\n",SF2);
    system("pause");

    // Calcola Forza Squadre Finali

    PCSF1=rand()%50+1;
    SFF1=PBSF1+PCSF1;
    SFF1=(100*SFF1)/100;

    PCSF2=rand()%50+1;
    SFF2=PBSF2+PCSF2;
    SFF2=(100*SFF2)/100;

    // SF1 VS SF2
    printf("\n\nFinali: %s contro %s\n",SF1,SF2);
    system("pause");
    FV=SFF1-SFF2;
    if (FV<=10&&FV>=-10)
    {
        printf("\n\nVi e' un pareggio!\n\nVia con i rigori!!");

        // Rigori
        R1=rand()%5+1;
        R2=rand()%5+1;
        while (R1==R2)
        {
            printf("\n\nI rigori continuano!!!");
            R1=rand()%5+1;
            R2=rand()%5+1;
        }
        if (R1>R2)
        {
            strcpy(SV,SF1);
        }
        else
        {
            strcpy(SV,SF2);
        }
    }
    else if (SFF1>SFF2)
    {
        strcpy(SV,SF1);
    }
    else
    {
        strcpy(SV,SF2);
    }
    printf("\n\nLa squadra vincitrice del torneo e':%s\n",SV);
}
