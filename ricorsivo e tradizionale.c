#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int fattoriale(int numero);
void contoallarovescia(int numero2);
int Menu();

int main()
{
    int Scelta;
    int n;
    int fatt;
    Scelta=Menu();

    if (Scelta==1)
    {
        system("cls");
        printf("Inserire un valore per n: ");
        scanf("%d",&n);
        if (n>=0)
        {
            fatt=fattoriale(n);
        }
        printf("\nIl fattoriale di %d e' %d",n,fatt);
    }
    else
    {
        n=0;
        system("cls");

        printf("Inserire un numero di partenza: ");
        scanf("%d",&n);
        contoallarovescia(n);
    }

    return 0;
}


int Menu()
{
    int xScelta;
    printf("\nScegliere tra:\n1-Fattoriale\n2-CountDown\nScelta attuale: ");
    scanf("%d",&xScelta);
    if (xScelta!=1 && xScelta!=2)
    {
        system("cls");
        printf("\nScelta errata. Scegliere tra:\n1-Fattoriale\n2-CountDown\nScelta attuale: ");
        scanf("%d",&xScelta);
    }

    return xScelta;
}

int fattoriale (int numero)
{
    if (numero==0)
        return 1;
    else
        return numero*fattoriale(numero-1);
}

void contoallarovescia(int numero2)
{
    if (numero2==0)
        printf("\nFine conto alla rovescia");
    else
    {
        printf("%d\n",numero2);
        contoallarovescia(numero2-1);
    }
}
