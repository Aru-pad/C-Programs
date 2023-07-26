//Software che verifica quale tra due commedie di un teatro ha venduto più biglietti

//Sezione delle include
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Sezione dichiarative
    int Cod_1Com;
    int Cod_2Com;
    int Bigl_1;
    int Bigl_2;
    int N_posti;
    int f;

    //Sezione eseguibile

    printf("Inserire il codice univoco della prima commedia \n");
    scanf("%d",&Cod_1Com);
    printf("Inserire il codice univoco della seconda commedia \n");
    scanf("%d",&Cod_2Com);
    printf("Inserire il numero di posti di entrambe le sale \n");
    scanf("%d",&N_posti);
    printf("Inserire il numero di biglietti venduti della prima commedia \n");
    scanf("%d",&Bigl_1);
    printf("Inserire il numero di biglietti venduti della seconda commedia \n");
    scanf("%d",&Bigl_2);

    //Verifica Input
    if (N_posti < 0)
    {
        printf("Errore nell'inserimento dei dati. Posti non validi. \n");
        f = 0;
    }
    if (Cod_1Com < 0)
    {
        printf("Errore nell'inserimento dei dati della commedia %d . Codice non valido. \n", Cod_1Com);
        f = 0;
    }
    if (Cod_2Com < 0)
    {
        printf("Errore nell'inserimento dei dati della commedia %d . Codice non valido. \n", Cod_2Com);
        f = 0;
    }
    if (Cod_1Com == Cod_2Com)
    {
        printf("I codici delle due commedie sono uguali. \n");
        f = 0;
    }
    if (Bigl_1 < 0)
    {
        printf("Errore nell'inserimento dei dati della commedia %d . Biglietti venduti non validi. \n", Cod_1Com);
        f = 0;
    }
    if (Bigl_2 < 0)
    {
        printf("Errore nell'inserimento dei dati dalla commedia %d . Biglietti non validi. \n", Cod_2Com);
        system("pause");
        f = 0;
    }
    if (f == 0)
    {
        system("pause");
        return 0;
    }
    //Fine verifica Input
    //Verifica e Visualizza Output
    if (Bigl_1 > Bigl_2)
    {
        if (Bigl_1 == N_posti)
        {
                printf("La commedia %d ha esaurito i posti. \n", Cod_1Com);
        }
        else
        {
            if (Bigl_1 < N_posti)
            {
                printf("La commedia %d ha venduto piu' biglietti. \nBiglietti venduti: %d \n", Cod_1Com, Bigl_1);
            }
            else
            {
                printf("I posti della commedia %d sono insufficienti. \n", Cod_1Com);
            }
        }
    }
    else
    {
        if (Bigl_1 == Bigl_2)
        {
            if (Bigl_1 == N_posti)
            {
                printf("Le commedie %d e %d hanno esaurito i posti. \n", Cod_1Com, Cod_2Com);
            }
            else
            {
                printf("Le commedie %d e %d hanno venduto la stessa quantità di biglietti. \n",Cod_1Com, Cod_2Com);
            }
        }
        else
        {
            if (Bigl_2 > N_posti)
            {
                printf("I posti della commedia %d sono insufficienti. \n", Cod_2Com);
            }
            else
            {
                if (Bigl_2 == N_posti)
                {
                    printf("La commedia %d ha esaurito i posti. \n", Cod_2Com);
                }
                else
                {
                    printf("La commedia %d ha venduto piu' biglietti. \nBiglietti venduti: %d \n", Cod_2Com, Bigl_2);
                }
            }
        }
    }
    system("pause");
    return 0;
}
