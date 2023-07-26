#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void RandCasNere(char[][5]);
void ContCasNere(char[][5]);

int main()
{
    char CruciV[5][5];

    RandCasNere(CruciV);
}


void RandCasNere(char xCruciV[][5])
{

    srand(time(NULL));

    int NCasNere,C,RI,RJ;
    printf("Quante caselle nere si desidera randomizzare?");
    scanf("%d",&NCasNere);

    for (C=0; C!=NCasNere; C++)
    {
        RI=rand()%5+1;
        RJ=rand()%5+1;
        xCruciV[RI][RJ]='*';
    }
}

