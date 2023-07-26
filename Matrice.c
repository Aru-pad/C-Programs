#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char C[15][15];

void leggi_Ixriga(int[][20],int*,int*);
void leggi_Ixcolonna(int[][20],int*,int*);
void sommaxriga(int[][20],int*,int*);
void inizializzaC(C[][15],int*,int*);
void ContSNeri(C[][15],int*,int*);


int main()
{
    C CruciV[8][8];
    int Matr[10][20];
    int Scelta1,Scelta2,Scelta3;
    int N1,M1,N2,M2;

    printf("Scegliere tra:\n1-Somma tra valori di una matrice\n2-Conteggio numero di caselle nere generate casualmente in un cruciverba\n\nScelta attuale:");
    fflush(stdin);
    scanf("%d",&Scelta1);

    while (Scelta1<1 || Scelta1>2)
    {
        printf("Scelta errata. Porre scelta corretta.\n\nScegliere tra:\n1-Somma tra valori di una matrice\n2-Conteggio numero di caselle nere generate casualmente in un cruciverba\n\nScelta attuale:");
        fflush(stdin);
        scanf("%d",&Scelta1);
    }

    if (Scelta1==1)
    {
        printf("\nCome si desidera leggere la matrice?\n1-Per riga\n2-Per colonna\n\nScelta attuale:");
        fflush(stdin);
        scanf("%d",&Scelta2);

        while (Scelta1<1 || Scelta1>2)
        {
            printf("Scelta errata. Porre scelta corretta.\n\nCome si desidera leggere la matrice?\n1-Per riga\n2-Per colonna\n\nScelta attuale:");
            fflush(stdin);
            scanf("%d",&Scelta2);
        }

        if (Scelta2==1)
        {
            leggi_Ixriga(Matr,&N1,&M1);
        }
        else
        {
            leggi_Ixcolonna(Matr,&N1,&M1);
        }

        sommaxriga(Matr,&N1,&M1);

    }

    else
    {
        inizializzaC(CruciV,&N2,&M2);

        ContSNeri(CruciV,&N2,&M2);
    }

}

