//Sezione delle include

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Sezione dichiarativa

    int Scelta,Contatore;
    float PR1,PR2,PR3;

    //Sezione del esecutiva del menu

    printf("Scegli:\n 1-Calcolo costo pavimento\n 2-Massimo prezzo\n 3-Conteggio\n\n\n");
    scanf("%d",Scelta);
    if (Scelta>=1&&Scelta<=3)
    {
        if (Scelta=1)
        {
            //Sezione calcolo costo pavimento
            float PR,MQ,Costo;
            print("Avete selezionato: Calcolo costo pavimento\n\n");
            printf("Inserire il prezzo unitario\n");
            scanf("%f",&PR);
            printf("Inserire i metri quadri\n");
            scanf("%f",&MQ);
            if (MQ>0||PR>0)
            {
                Costo=MQ*PR;
                printf("Il costo della pavimentazione e' %f\n",Costo);
                system("pause");
            }
            else
            {
                printf("Errore, dati non validi");
                system("pause");
            }
        }
        else
        {
            if (Scelta=2)
            {
                //Sezione massimo prezzo

            }
        }
    }
}
