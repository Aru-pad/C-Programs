#include <stdio.h>
#include <stdlib.h>

int Menu(int*);
int Somma(int,int);
int Sottr(int,int);
int Molt(int,int);
float Divis(float,float);


int main()
{
    int Scelta;
    Scelta=Menu(&Scelta);

    while (Scelta!=5)
    {
        int A,B,Ris;
        printf("\n\nInserire i due numeri con cui eseguire l'operazione scelta: ");
        scanf("%i ",&A);
        scanf("%i",&B);

        if (Scelta==1)
            {
                Ris=Somma(A,B);
            }
            else if (Scelta==2)
            {
                Ris=Sottr(A,B);
            }
            else if (Scelta==3)
            {
                Ris=Molt(A,B);
            }
            else
            {
                Ris=Divis(A,B);
            }
            printf("\n\nIl risultato e':%f",Ris);
            Scelta=Menu(&Scelta);
    }
}

int Menu(int *xScelta)
{
    printf("\nScegli tra una delle seguenti operazioni:\n1-Somma\n2-Sottrazione\n3-Moltiplicazione\n4-Divisione\n5-Fine");
    scanf("&d",&*xScelta);

    while (*xScelta<1 || *xScelta>5)
    {
        printf("Scelta errata.")
        scanf("&d",&*xScelta);
    }

    return *xScelta;
}

int Somma(int xa,int xb)
{
    int xRis;
    xRis=xa+xb;
    return xRis;
}

int Sottr(int xa,int xb)
{
    int xRis;
    xRis=xa+xb;
    return xRis;
}

int Molt(int xa,int xb)
{
    int xRis;
    xRis=xa*xb;
    return xRis;
}

float Divis(float xa,float xb)
{
    float xRis;
    xRis=xa/xb;
    return xRis;
}
