// Sezione delle include

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Sezione dichiarativa

    int Giorno,Piano,P1,P2,P3,T1,T2,T3,D1,D2,D3,S1,S2,S3,C_SAL,C_DIS;
    Piano=0;
    C_SAL=0;
    C_DIS=0;

    // Sezione esecutiva

    printf("Inserire 1 per iniziare la giornata");
    scanf("%d",&Giorno);

    while (Giorno==1)
    {
        // Leggi Chiamata

        /* Initializes random number generator */
        srand(time(NULL));

        printf("Inserire il Piano che si vuole raggiungere");
        scanf("%d",&P1);
        while (P1>5 || P1<0)
        {
            printf("Inserire Piano esistente");
            scanf("%d",&P1);
        }
        T1=rand()%60+1;
        printf("Si vuole salire o scendere?");
        scanf("%d",&D1);
        while (D1>1 || D1<0)
        {
            printf("Inserire Salita o Discesa correttta");
            scanf("%d",&D1);
        }

        printf("Inserire il Piano che si vuole raggiungere");
        scanf("%d",&P2);
        while (P2>5 || P2<0)
        {
            printf("Inserire Piano esistente");
            scanf("%d",&P2);
        }
        T2=rand()%60+1;
        printf("Si vuole salire o scendere?");
        scanf("%d",&D2);
        while (D2>1 || D2<0)
        {
            printf("Inserire Salita o Discesa correttta");
            scanf("%d",&D2);
        }

        printf("Inserire il Piano che si vuole raggiungere");
        scanf("%d",&P3);
        while (P3>5 || P3<0)
        {
            printf("Inserire Piano esistente");
            scanf("%d",&P3);
        }
        T3=rand()%60+1;
        printf("Si vuole salire o scendere?");
        scanf("%d",&D3);
        while (D3>5 || D3<0)
        {
            printf("Inserire Salita o Discesa correttta");
            scanf("%d",&D3);
        }

        // Gestione Movimento

        if (T1==T2)
        {
            if (T1==T3)
            {
                S1=Piano-P1;
                S2=Piano-P2;
                S3=Piano-P3;
                if (S1<=S2)
                {
                    if (S1<=S3)
                    {
                        Piano=P3;
                        printf("Piano attuale %d",Piano);
                        if (D3==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P2;
                        printf("Piano attuale %d",Piano);
                        if (D2==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P1;
                        printf("Piano attuale %d",Piano);
                        if (D1==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                    }
                    else
                    {
                        Piano=P1;
                        printf("Piano attuale %d",Piano);
                        if (D1==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P2;
                        printf("Piano attuale %d",Piano);
                        if (D2==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P3;
                        printf("Piano attuale %d",Piano);
                        if (D3==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                    }
                }
                if (S1<=S3)
                {
                    if (S2<=S3)
                    {
                        Piano=P1;
                        printf("Piano attuale %d",Piano);
                        if (D1==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P2;
                        printf("Piano attuale %d",Piano);
                        if (D2==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P3;
                        printf("Piano attuale %d",Piano);
                        if (D3==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                    }
                    else
                    {
                        Piano=P1;
                        printf("Piano attuale %d",Piano);
                        if (D1==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P3;
                        printf("Piano attuale %d",Piano);
                        if (D3==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P2;
                        printf("Piano attuale %d",Piano);
                        if (D2==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                    }
                }
                if (S2<=S3)
                {
                        Piano=P2;
                        printf("Piano attuale %d",Piano);
                        if (D2==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P3;
                        printf("Piano attuale %d",Piano);
                        if (D3==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P1;
                        printf("Piano attuale %d",Piano);
                        if (D1==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                }
                else
                {
                        Piano=P3;
                        printf("Piano attuale %d",Piano);
                        if (D3==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P2;
                        printf("Piano attuale %d",Piano);
                        if (D2==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P1;
                        printf("Piano attuale %d",Piano);
                        if (D1==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                }
            }
            else
            {
                S1=Piano-P1;
                S2=Piano-P2;
                if (S1<=S2)
                {
                    if (T2>T3)
                    {
                        Piano=P3;
                        printf("Piano attuale %d",Piano);
                        if (D3==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P2;
                        printf("Piano attuale %d",Piano);
                        if (D2==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P1;
                        printf("Piano attuale %d",Piano);
                        if (D1==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                    }
                    else
                    {
                        Piano=P2;
                        printf("Piano attuale %d",Piano);
                        if (D2==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P1;
                        printf("Piano attuale %d",Piano);
                        if (D1==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P3;
                        printf("Piano attuale %d",Piano);
                        if (D3==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                    }
                }
                else
                {
                    if (T1>T3)
                    {
                        Piano=P1;
                        printf("Piano attuale %d",Piano);
                        if (D1==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P2;
                        printf("Piano attuale %d",Piano);
                        if (D2==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P3;
                        printf("Piano attuale %d",Piano);
                        if (D3==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                    }
                    else
                    {
                        Piano=P1;
                        printf("Piano attuale %d",Piano);
                        if (D1==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P2;
                        printf("Piano attuale %d",Piano);
                        if (D2==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                        Piano=P3;
                        printf("Piano attuale %d",Piano);
                        if (D3==1)
                        {
                            C_SAL=C_SAL+1;
                        }
                        else
                        {
                            C_DIS=C_DIS+1;
                        }
                    }
                }
            }
        }
        else
        {

        }
    }
}
