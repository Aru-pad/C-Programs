// Sezione delle include

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char N[15],C[15],AI[15];

int LetturaDatiGenerali(N[],C[],int[],int[],int[],char[],int[],int[],int[],int[],int[],int *);

int Menu();

void Aggiorna(int [],int [],int[],int[],int[],N[],C[],int,char*);

int RicercaAlunno(N[],C[],int);

int InsAl(int,N[],C[],int[],int[],int[],char[],int[],int[],int[],int[],int[],int);

int CancAl(int,N[],C[],int[],int[],int[],char[],int[],int[],int[],int[],int[]);

void MediaClasse(int[],int[],int[],int[],int);

void VerificaOrd(int,C[]);

void AlInsuf(C[],AI[],int [],int[],int[],int[],int);

void Modifica(N[],C[],int[],int[],int[],char[],int,int);




int main()
{
    N Nomi[35];
    C Cognomi[35];
    AI AlIns[35];
    int GN[35];
    int MN[35];
    int AN[35];
    char Rip[35];
    int NVal[35];
    int Val1[35];
    int Val2[35];
    int Val3[35];
    int Assenze[35];

    int Scelta,NAl,AA;
    char R1,R2;

    NAl=LetturaDatiGenerali(Nomi,Cognomi,GN,MN,AN,Rip,NVal,Val1,Val2,Val3,Assenze,&AA);

    Scelta=Menu();

    while (Scelta!=6)
    {
        printf("Aggiornare valutazioni e/o assenze?[S/N]");
        fflush(stdin);
        scanf("%c",&R1);

        if (R1=='N' || R1=='n')
        {
        }
        else
        {
            while (R1=='S' || R1=='s')
            Aggiorna(NVal,Val1,Val2,Val3,Assenze,Nomi,Cognomi,NAl,&R1);
        }

        system("cls");

        switch (Scelta){
        case 1: NAl=InsAl(NAl,Nomi,Cognomi,GN,MN,AN,Rip,NVal,Val1,Val2,Val3,Assenze,AA);
                break;
        case 2: NAl=CancAl(NAl,Nomi,Cognomi,GN,MN,AN,Rip,NVal,Val1,Val2,Val3,Assenze);
                break;
        case 3: MediaClasse(NVal,Val1,Val2,Val3,NAl);
                break;
        case 4: VerificaOrd(NAl,Cognomi);
                break;
        case 5: AlInsuf(Cognomi,AlIns,NVal,Val1,Val2,Val3,NAl);
                break;
        }

        system("cls");

        printf("\nSi desidera modificare nome e cognome o data di nascita o eventuale ripetenza di un alunno?[S/N]");
        fflush(stdin);
        scanf("%c",&R2);

        if (R2=='S' || R2 =='s')
        {
             Modifica(Nomi,Cognomi,GN,MN,AN,Rip,NAl,AA);
        }

        Scelta=Menu();

    }
}


int LetturaDatiGenerali(N XNomi[],C XCognomi[],int XGN[],int XMN[],int XAN[],char XRip[],int XNVal[],int XVal1[],int XVal2[],int XVal3[],int XAssenze[], int *XAA)
{

    int XNAl,XI,G,AMin;
    fflush(stdin);
    printf("Inserire il numero totale di studenti nella classe[Max 35]:");
    scanf("%d",&XNAl);
    fflush(stdin);

    fflush(stdin);
    printf("Inserire anno attuale:");
    scanf("%d",&*XAA);

    AMin=*XAA-30;

    for (XI=0; XI<XNAl; XI++)
    {
        fflush(stdin);
        printf("\n\nInserire le informazioni relative all'alunno:\n\nNome:");
        gets(XNomi[XI]);
        fflush(stdin);
        printf("\nCognome:");
        gets(XCognomi[XI]);
        fflush(stdin);
        printf("\nData di nascita[Giorno]:");
        scanf("%d",&XGN[XI]);
        fflush(stdin);
        while (XGN[XI]<0 || XGN[XI]>31)
        {
            printf("\nGiorno errato. Inserire data corretta.\n\nData di nascita[Giorno]:");
            scanf("%d",&XGN[XI]);
            fflush(stdin);
        }
        printf("\nData di nascita[Mese]:");
        scanf("%d",&XMN[XI]);
        fflush(stdin);
        while (XMN[XI]<0 || XMN[XI]>12)
        {
            printf("\nMese errato. Inserire data corretta.\n\nData di nascita[Mese]:");
            scanf("%d",&XMN[XI]);
            fflush(stdin);
        }
        printf("\nData di nascita[Anno]:");
        scanf("%d",&XAN[XI]);
        fflush(stdin);
        while (XAN[XI]<AMin || XAN[XI]>*XAA)
        {
            printf("\nAnno errato. Inserire data corretta.\n\nData di nascita[Anno]:");
            scanf("%d",&XAN[XI]);
            fflush(stdin);
        }
        printf("L'alunno in considerazione e' ripetente?[S/N]");
        scanf("%c",&XRip[XI]);
        fflush(stdin);
        G=0;
        while (XRip[XI]!='S' && XRip[XI]!='s' && G==0)
        {
            if (XRip[XI]=='N' || XRip[XI]=='n')
            {
                G=1;
            }
            else
            {
            printf("\n\nRispondere correttamente alla domanda.\n\n\nL'alunno in considerazione e' ripetente?[S/N]");
            scanf("%c",&XRip[XI]);
            fflush(stdin);
            }
        }
        printf("\n\nDi quante valutazioni disponde lo studente?[Max 3]\n0-Digitare 0 per nessuna valutazione\n1-Digitare 1 per una valutazione\n2-Digitare 2 per due valutazioni\n3-Digitare 3 per tre valutazioni\nSelezione attuale:");
        scanf("%d",&XNVal[XI]);
        fflush(stdin);
        while (XNVal[XI]<0 || XNVal[XI]>3)
        {
            printf("\n\nRispondere correttamente alla domanda.\n\n\nDi quante valutazioni disponde lo studente?[Max 3]\n0-Digitare 0 per nessuna valutazione\n1-Digitare 1 per una valutazione\n2-Digitare 2 per due valutazioni\n3-Digitare 3 per tre valutazioni\nSelezione attuale:");
            scanf("%d",&XNVal[XI]);
            fflush(stdin);
        }

        if (XNVal[XI]==1)
        {
            printf("\n\nInserire la valutazione:");
            scanf("%d",&XVal1[XI]);
            fflush(stdin);

            if (XVal1[XI]<0 || XVal1[XI]>10)
            {
                printf("\n\nValutazione errata. Minimo per la valutazione e' 0 mentre il massimo e' 10. Inserire valutazione valida:");
                scanf("%d",&XVal1[XI]);
                fflush(stdin);
            }
        }
        else if (XNVal[XI]==2)
        {
            printf("\n\nInserire prima valutazione:");
            scanf("%d",&XVal1[XI]);
            fflush(stdin);

            if (XVal1[XI]<0 || XVal1[XI]>10)
            {
                printf("\n\nValutazione errata. Minimo per la valutazione e' 0 mentre il massimo e' 10. Inserire valutazione valida:");
                scanf("%d",&XVal1[XI]);
                fflush(stdin);
            }

            printf("\n\nInserire seconda valutazione:");
            scanf("%d",&XVal2[XI]);
            fflush(stdin);

            if (XVal2[XI]<0 || XVal2[XI]>10)
            {
                printf("\n\nValutazione errata. Minimo per la valutazione e' 0 mentre il massimo e' 10. Inserire valutazione valida:");
                scanf("%d",&XVal2[XI]);
                fflush(stdin);
            }

        }
        else if (XNVal[XI]==3)
        {
            printf("\n\nInserire prima valutazione:");
            scanf("%d",&XVal1[XI]);
            fflush(stdin);

            if (XVal1[XI]<0 || XVal1[XI]>10)
            {
                printf("\n\nValutazione errata. Minimo per la valutazione e' 0 mentre il massimo e' 10. Inserire valutazione valida:");
                scanf("%d",&XVal1[XI]);
                fflush(stdin);
            }

            printf("\n\nInserire seconda valutazione:");
            scanf("%d",&XVal2[XI]);
            fflush(stdin);

            if (XVal2[XI]<0 || XVal2[XI]>10)
            {
                printf("\n\nValutazione errata. Minimo per la valutazione e' 0 mentre il massimo e' 10. Inserire valutazione valida:");
                scanf("%d",&XVal2[XI]);
                fflush(stdin);
            }

            printf("\n\nInserire terza valutazione:");
            scanf("%d",&XVal3[XI]);
            fflush(stdin);

            if (XVal3[XI]<0 || XVal3[XI]>10)
            {
                printf("\n\nValutazione errata. Minimo per la valutazione e' 0 mentre il massimo e' 10. Inserire valutazione valida:");
                scanf("%d",&XVal3[XI]);
                fflush(stdin);
            }

        }
        printf("\n\nInserire assenze totali di codesto alunno:");
        scanf("%d",&XAssenze[XI]);
        fflush(stdin);

        if (XAssenze[XI]<0)
            {
                printf("\n\nNumero di assenze errato. Assenze minime sono 0. Inserire numero di assenze valido:");
                scanf("%d",&XAssenze[XI]);
                fflush(stdin);
            }
    system("cls");
    }

    return XNAl;
}

int Menu()
{
    system("cls");
    int xScelta;
    printf("\nScegliere tra:\n1-Inserire alunno con relative informazioni\n2-Cancellare alunno con relative informazioni\n3-Media classe\n4-Verifica ordinamento\n5-Conteggio alunni media insufficiente con relativi nomi\n6-Fine programma\n\nScelta attuale:");
    fflush(stdin);
    scanf("%d",&xScelta);

    while ( xScelta<=0 || xScelta>=7)
    {
        printf("\nScelta errata. Porre scelta corretta.\n\n\nScegliere tra:\n1-Inserire alunno con relative informazioni\n2-Cancellare alunno con relative informazioni\n3-Media classe\n4-Verifica ordinamento\n5-Conteggio alunni media insufficiente con relativi nomi\n6-Fine programma\n\nScelta attuale:");
        fflush(stdin);
        scanf("%d",&xScelta);
    }

    return xScelta;
}

void Aggiorna(int zNVal[],int zVal1[],int zVal2[], int zVal3[], int zAssenze[],N zNomi[],C zCognomi[],int zNAl,char *R1)
{
    system("cls");

    int Scelta2,Scelta3,zI,Trovato;

    printf("\nChe elemento si desidera aggiornare?\n1-Assenze\n2-Valutazioni\nScelta attuale:");
    fflush(stdin);
    scanf("%d",&Scelta2);

    while (Scelta2>2 || Scelta2<1)
    {
        printf("\nScelta errata. Porre scelta corretta.\n\n\nChe elemento si desidera aggiornare?\n1-Assenze\n2-Valutazioni\nScelta attuale:");
        fflush(stdin);
        scanf("%d",&Scelta2);
    }

    if (Scelta2==1)
    {
        Trovato=RicercaAlunno(zNomi,zCognomi,zNAl);

        if (Trovato!=-1)
        {
            printf("\nInserire inserire il numero totale di assenze dell'alunno %s %s:",zNomi[Trovato],zCognomi[Trovato]);
            fflush(stdin);
            scanf("%d",&zAssenze[Trovato]);

             if (zAssenze[Trovato]<0)
            {
                printf("\n\nNumero di assenze errato. Assenze minime sono 0. Inserire numero di assenze valido:");
                scanf("%d",&zAssenze[Trovato]);
                fflush(stdin);
            }

        }
        else
        {
            printf("\n\nAlunno non presente nell'elenco.");
            fflush(stdin);
            system("pause");
        }
    }
    else
    {
        Trovato=RicercaAlunno(zNomi,zCognomi,zNAl);

        if (Trovato!=-1)
        {
            printf("\nQuale delle tre valutazioni si desira cambiare o aggiungere?[1/2/3]");
            fflush(stdin);
            scanf("%d",&Scelta3);
            while (Scelta3>3 || Scelta3<1)
            {
                printf("\nScelta errata. Porre scelta corretta.\n\nQuale delle tre valutazioni si desira cambiare o aggiungere?[1/2/3]");
                fflush(stdin);
                scanf("%d",&Scelta3);
            }

            if (Scelta3==1)
            {
                printf("Inserire la prima valutazione dell'alunno %s %s",zNomi[Trovato],zCognomi[Trovato]);
                fflush(stdin);
                scanf("%d",&zVal1[Trovato]);

                if (zVal1[Trovato]<0 || zVal1[Trovato]>10)
                 {
                     printf("\n\nValutazione errata. Minimo per la valutazione e' 0 mentre il massimo e' 10. Inserire valutazione valida:");
                     scanf("%d",&zVal1[Trovato]);
                     fflush(stdin);
                 }

                 if (zNVal[Trovato]==0)
                 {
                     zNVal[Trovato]=1;
                 }

            }
            else if (Scelta3==2)
            {
                printf("Inserire la seconda valutazione dell'alunno %s %s",zNomi[Trovato],zCognomi[Trovato]);
                fflush(stdin);
                scanf("%d",&zVal2[Trovato]);

                if (zVal2[Trovato]<0 || zVal2[Trovato]>10)
                 {
                     printf("\n\nValutazione errata. Minimo per la valutazione e' 0 mentre il massimo e' 10. Inserire valutazione valida:");
                     scanf("%d",&zVal2[Trovato]);
                     fflush(stdin);
                 }

                 if (zNVal[Trovato]==1)
                 {
                     zNVal[Trovato]=2;
                 }
            }
            else
            {
                printf("Inserire la terza valutazione dell'alunno %s %s",zNomi[Trovato],zCognomi[Trovato]);
                fflush(stdin);
                scanf("%d",&zVal3[Trovato]);

                 if (zVal3[Trovato]<0 || zVal3[Trovato]>10)
                 {
                     printf("\n\nValutazione errata. Minimo per la valutazione e' 0 mentre il massimo e' 10. Inserire valutazione valida:");
                     scanf("%d",&zVal3[Trovato]);
                     fflush(stdin);
                 }

                 if (zNVal[Trovato]==2)
                 {
                     zNVal[Trovato]=3;
                 }

            }
        }
        else
        {
            printf("\n\nAlunno non presente nell'elenco.");
            system("pause");
            fflush(stdin);
        }
    }

    printf("Aggiornare un'altra valutazione o assenza?[S/N]");
    fflush(stdin);
    scanf("%c",&*R1);

}

int RicercaAlunno(N xzNomi[],C xzCognomi[],int xzNAl)
{
    system("cls");

    char NDC[15],CDC[15];
    int xTrovato,zI;

    fflush(stdin);
    printf("\nInserire il nome e cognome dell'alunno di cui effettuare modifiche:\nNome:");
    gets(NDC);
    fflush(stdin);
    printf("\nCognome:");
    gets(CDC);
    fflush(stdin);

    xTrovato=-1;

    for (zI=0; zI<xzNAl && xTrovato==-1; zI++)
    {
        if (strcmp(xzNomi[zI],NDC)==0)
        {
            if (strcmp(xzCognomi[zI],CDC)==0)
            {
                xTrovato=zI;
            }
        }
    }
    return xTrovato;
}

int InsAl(int zNAl,N zNomi[],C zCognomi[],int zGN[],int zMN[],int zAN[],char zRip[],int zNVal[],int zVal1[],int zVal2[],int zVal3[],int zAssenze[],int zAA)
{
    system("cls");

    int POS,G,Amin;

    if (zNAl==35)
    {
        printf("Impossibile inserire un nuovo alunno, lista giunta al suo limite.\n");
        system("pause");
    }
    else
    {

        Amin=zAA-30;

        POS=zNAl;
        fflush(stdin);
        printf("\n\nInserire le informazioni relative all'alunno:\n\nNome:");
        gets(zNomi[POS]);
        fflush(stdin);
        printf("\nCognome:");
        gets(zCognomi[POS]);
        fflush(stdin);
        printf("\nData di nascita[Giorno]:");
        scanf("%d",&zGN[POS]);
        fflush(stdin);
        while (zGN[POS]<0 || zGN[POS]>31)
        {
            printf("\nGiorno errato. Inserire data corretta.\n\nData di nascita[Giorno]:");
            scanf("%d",&zGN[POS]);
            fflush(stdin);
        }
        printf("\nData di nascita[Mese]:");
        scanf("%d",&zMN[POS]);
        fflush(stdin);
        while (zMN[POS]<0 || zMN[POS]>12)
        {
            printf("\nMese errato. Inserire data corretta.\n\nData di nascita[Mese]:");
            scanf("%d",&zMN[POS]);
            fflush(stdin);
        }
        printf("\nData di nascita[Anno]:");
        scanf("%d",&zAN[POS]);
        fflush(stdin);
        while (zAN[POS]<Amin || zAN[POS]>zAA)
        {
            printf("\nAnno errato. Inserire data corretta.\n\nData di nascita[Anno]:");
            scanf("%d",&zAN[POS]);
            fflush(stdin);
        }
        printf("L'alunno in considerazione e' ripetente?[S/N]");
        scanf("%c",&zRip[POS]);
        fflush(stdin);
        G=0;
        while (zRip[POS]!='S' && zRip[POS]!='s' && G==0)
        {
            if (zRip[POS]=='N' || zRip[POS]=='n')
            {
                G=1;
            }
            else
            {
            printf("\n\nRispondere correttamente alla domanda.\n\n\nL'alunno in considerazione e' ripetente?[S/N]");
            scanf("%c",&zRip[POS]);
            fflush(stdin);
            }
        }
        printf("\n\nDi quante valutazioni disponde lo studente?[Max 3]\n0-Digitare 0 per nessuna valutazione\n1-Digitare 1 per una valutazione\n2-Digitare 2 per due valutazioni\n3-Digitare 3 per tre valutazioni\nSelezione attuale:");
        scanf("%d",&zNVal[POS]);
        fflush(stdin);
        while (zNVal[POS]<0 || zNVal[POS]>3)
        {
            printf("\n\nRispondere correttamente alla domanda.\n\n\nDi quante valutazioni disponde lo studente?[Max 3]\n0-Digitare 0 per nessuna valutazione\n1-Digitare 1 per una valutazione\n2-Digitare 2 per due valutazioni\n3-Digitare 3 per tre valutazioni\nSelezione attuale:");
            scanf("%d",&zNVal[POS]);
            fflush(stdin);
        }

        if (zNVal[POS]==1)
        {
            printf("\n\nInserire la valutazione:");
            fflush(stdin);
            scanf("%d",&zVal1[POS]);
        }
        else if (zNVal[POS]==2)
        {
            printf("\n\nInserire prima valutazione:");
            fflush(stdin);
            scanf("%d",&zVal1[POS]);
            printf("\n\nInserire seconda valutazione:");
            fflush(stdin);
            scanf("%d",&zVal2[POS]);
        }
        else if (zNVal[POS]==3)
        {
            printf("\n\nInserire prima valutazione:");
            fflush(stdin);
            scanf("%d",&zVal1[POS]);
            printf("\n\nInserire seconda valutazione:");
            fflush(stdin);
            scanf("%d",&zVal2[POS]);
            printf("\n\nInserire terza valutazione:");
            fflush(stdin);
            scanf("%d",&zVal3[POS]);
        }
        printf("\n\nInserire assenze totali di codesto alunno:");
        fflush(stdin);
        scanf("%d",&zAssenze[POS]);

        zNAl++;

    }

    return zNAl;
}

int CancAl(int cNAl,N cNomi[],C cCognomi[],int cGN[],int cMN[],int cAN[],char cRip[],int cNVal[],int cVal1[],int cVal2[],int cVal3[],int cAssenze[])
{
    system("cls");

    int cTrovato,cI;

    if (cNAl!=0)
    {
        cTrovato=RicercaAlunno(cNomi,cCognomi,cNAl);

        if (cTrovato!=-1)
        {
            if (cTrovato==cNAl-1)
            {
            }
            else
            {
                for (cI=cTrovato; cI!=cNAl-1; cI++)
                {
                    strcpy(cNomi[cI],cNomi[cI+1]);
                    strcpy(cCognomi[cI],cCognomi[cI+1]);
                    cGN[cI]=cGN[cI+1];
                    cMN[cI]=cMN[cI+1];
                    cAN[cI]=cAN[cI+1];
                    cRip[cI]=cRip[cI+1];
                    cNVal[cI]=cNVal[cI+1];
                    cVal1[cI]=cVal1[cI+1];
                    cVal2[cI]=cVal2[cI+1];
                    cVal3[cI]=cVal3[cI+1];
                    cAssenze[cI]=cAssenze[cI+1];
                }
            }
            cNAl=cNAl-1;
        }
        else
        {

        printf("\n\nTale alunno non e' presente nella lista.\n");
        system("pause");
        fflush(stdin);

        }
    }
    else
    {

    printf("\nNon e' presente nessun dato da cancellare.\n");
    system("pause");
    fflush(stdin);

    }

    return cNAl;

}

void MediaClasse(int mNVal[],int mVal1[],int mVal2[],int mVal3[],int mNAl)
{
    system("cls");

    int mI,xMedia;
    xMedia=0;
    for (mI=0; mI!=mNAl; mI++)
    {
        if (mNVal[mI]==1)
        {
            xMedia=xMedia+mVal1[mI];
        }
        else if (mNVal[mI]==2)
        {
            xMedia=xMedia+(mVal1[mI]+mVal2[mI])/2;
        }
        else if (mNVal[mI]==3)
        {
            xMedia=xMedia+(mVal1[mI]+mVal2[mI]+mVal3[mI])/3;
        }
    }

    xMedia=xMedia/mI;

    printf("La media della classe e':%d\n",xMedia);
    system("pause");

}

void VerificaOrd(int oNAl,C oCognomi[])
{

    system("cls");

    printf("\nVerifica Ordinamento in corso...\n");
    system("pause");
    fflush(stdin);

    int Ord,oI,oC;

    Ord=0;

    for (oI=0; oI!=oNAl && Ord==0; oI++)
    {
        for (oC=oI+1; oC!=oNAl && Ord==0; oC++)
        {
            if (strcmp(oCognomi[oI],oCognomi[oC])>0)
            {
                Ord=1;
            }
        }
    }

    if (Ord==1)
    {
        printf("\nLa lista degli alunni non e' disposta in maniera ordinata.\n");
        system("pause");
    }
    else
    {
        printf("\nLa lista degli alunni e' disposta in maniera ordinata.\n");
        system("pause");
    }
}

void AlInsuf(C iCognomi[],AI iAlIns[],int iNVal[],int iVal1[],int iVal2[],int iVal3[],int iNAl)
{

    printf("Verifica media in corso...\n");
    system("pause");

    int ContAl,I,I2,Val,iNAlIns;

    ContAl=0;
    I2=0;
    for (I=0; I!=iNAl; I++)
    {
        if (iNVal[I]==1)
        {
            if (iVal1[I]<6)
            {
                strcpy(iAlIns[I2],iCognomi[I]);
                ContAl++;
                I2++;
            }
        }
        else if (iNVal[I]==2)
        {
            Val=(iVal1[I]+iVal2[I])/2;
            if (Val<6)
            {
                strcpy(iAlIns[I2],iCognomi[I]);
                ContAl++;
                I2++;
            }
        }
        else if (iNVal[I]==3)
        {
            Val=(iVal1[I]+iVal2[I]+iVal3[I])/3;
            if (Val<6)
            {
                strcpy(iAlIns[I2],iCognomi[I]);
                ContAl++;
                I2++;
            }
        }
    }

    iNAlIns=I2;

    printf("\n\nGli alunni aventi come media l'insufficienza sono in totale:%d\n",ContAl);

    if (ContAl!=0)
    {
        printf("\n\nEcco il cognome di tali alunni:\n");

        for (I2=0; I2<iNAlIns; I2++)
        {
            printf("%s\n",iAlIns[I2]);
        }
    }
    system("pause");
}

void Modifica(N mNomi[],C mCognomi[],int mGN[],int mMN[],int mAN[],char mRip[],int mNAl,int mAA)
{

    system("cls");

    int Scelta4,mTrovato,mAMin,mG;

    mAMin=mAA-30;

    printf("\nCosa si desidera modificare?\n1-Nome e cognome\n2-Data Nascita\n3-Ripetenza");
    fflush(stdin);
    scanf("%d",&Scelta4);

    while (Scelta4>3 || Scelta4<1)
    {
        printf("\nScelta errata. Porre scelta corretta.\n\nCosa si desidera modificare?\n1-Nome e cognome\n2-Data Nascita\n3-Ripetenza");
        fflush(stdin);
        scanf("%d",&Scelta4);
    }

    mTrovato=RicercaAlunno(mNomi,mCognomi,mNAl);

    if (mTrovato!=-1)
    {
        if (Scelta4==1)
        {
            printf("\n\nInserire nuovo nome e cognome dell'alunno:\n\nNome:");
            gets(mNomi[mTrovato]);
            fflush(stdin);
            printf("\nCognome:");
            gets(mCognomi[mTrovato]);
            fflush(stdin);
        }
        else if (Scelta4==2)
        {
            printf("\nInserire nuova data di nascita:\nGiorno:");
            scanf("%d",&mGN[mTrovato]);
            fflush(stdin);
            while (mGN[mTrovato]<0 || mGN[mTrovato]>31)
            {
                printf("\nGiorno errato. Inserire data di nascita corretta.\n\nGiorno:");
                scanf("%d",&mGN[mTrovato]);
                fflush(stdin);
            }
            printf("\nMese:");
            scanf("%d",&mMN[mTrovato]);
            fflush(stdin);
            while (mMN[mTrovato]<0 || mMN[mTrovato]>12)
            {
                printf("\nMese errato. Inserire data di nascita corretta.\n\nMese:");
                scanf("%d",&mMN[mTrovato]);
                fflush(stdin);
            }
            printf("\nAnno:");
            scanf("%d",&mAN[mTrovato]);
            fflush(stdin);
            while (mAN[mTrovato]<mAMin || mAN[mTrovato]>mAA)
            {
                printf("\nAnno errato. Inserire data di nascita corretta.\n\nAnno:");
                scanf("%d",&mAN[mTrovato]);
                fflush(stdin);
            }
        }
        else
        {
            printf("\nAlunno Ripetente?[S/N]");
            scanf("%c",&mRip[mTrovato]);
            fflush(stdin);
            mG=0;
            while (mRip[mTrovato]!='S' && mRip[mTrovato]!='s' && mG==0)
            {
                if (mRip[mTrovato]=='N' || mRip[mTrovato]=='n')
                {
                    mG=1;
                }
                else
                {
                    printf("\n\nRispondere correttamente alla domanda.\n\n\nL'alunno in considerazione e' ripetente?[S/N]");
                    scanf("%c",&mRip[mTrovato]);
                    fflush(stdin);
                }
            }
        }
    }
}
