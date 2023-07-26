//Sezione delle includ

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    /* Initializes random number generator */
   srand(time(NULL));

    //Asseganzione I

    char Gioc_1;
    Gioc_1 = 'A';
    char Gioc_2;
    Gioc_2 = 'B';
    char Gioc_3;
    Gioc_3 = 'C';
    int dad_1;
    int dad_2;
    int dad_3;
    int dad_4;
    int dad_5;
    int dad_6;
    int dad_7;
    int dad_8;
    int dad_9;
    int dad_10;
    int dad_11;
    int dad_12;
    int dad_13;
    int dad_14;
    int dad_15;
    int dad_16;
    int dad_17;
    int dad_18;
    int Punt_1;
    int Punt_2;
    int Punt_3;

    //Sezione esecutiva

    dad_1=rand()&6+1;
    dad_2=rand()&6+1;
    dad_3=rand()&6+1;
    dad_4=rand()&6+1;
    dad_5=rand()&6+1;
    dad_6=rand()&6+1;
    Punt_1=dad_1+dad_2+dad_3+dad_4+dad_5+dad_6;
    printf("%c lancia per primo i dati totalizzando %d punti\n",Gioc_1,Punt_1);

    dad_7=rand()&6+1;
    dad_8=rand()&6+1;
    dad_9=rand()&6+1;
    dad_10=rand()&6+1;
    dad_11=rand()&6+1;
    dad_12=rand()&6+1;
    Punt_2=dad_7+dad_8+dad_9+dad_10+dad_11+dad_12;
    printf("%c lancia per primo i dati totalizzando %d punti\n",Gioc_2,Punt_2);

    dad_13=rand()&6+1;
    dad_14=rand()&6+1;
    dad_15=rand()&6+1;
    dad_16=rand()&6+1;
    dad_17=rand()&6+1;
    dad_18=rand()&6+1;
    Punt_3=dad_13+dad_14+dad_15+dad_16+dad_17+dad_18;
    printf("%c lancia per primo i dati totalizzando %d punti\n",Gioc_3,Punt_3);

    //Sezione della selezione del punteggio totale
    //Verifica Punt_1 e Visualizza_O
    if (Punt_1 == Punt_2)
    {
        if (Punt_1 == Punt_3)
        {
          scanf("%c, %c, %c hanno totalizzato lo stesso punteggio. Parità: %d",Gioc_1,Gioc_2,Gioc_3,Punt_1);
        }
        else
            if (Punt_1 < Punt_3)
        {
            scanf("%c, %c hanno totalizzato lo stesso punteggio: %d. Mentre, con punteggio superiore vince: %c totalizzando %d",Gioc_1,Gioc_2,Punt_1,Gioc_3,Punt_3);
        }
    }
}
