#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_paziente{
    char Nome[20];
    char Cognome[20];
    char Indirizzo[20];
    int Telefono;
    int GP;
    int MP;
    int AP;
    float OP;
}t_paziente;
t_paziente Pren,App,Appoggio;


int Menu();

int main()
{
    FILE *puntafile,*puntaFile;
    int GP2,MP2,AP2,Scelta,f,a,GPC,MPC,APC,c;
    float OP2;
    char R,R1;
    puntafile=fopen("Prenotazioni.dat","wb");

    if (puntafile)
    {
         printf("\nInserire le informazioni relative alla prenotazione: ");
         printf("\n\nNome: ");
         fflush(stdin);
         gets(Pren.Nome);
         fflush(stdin);
         printf("\nCognome: ");
         fflush(stdin);
         gets(Pren.Cognome);
         fflush(stdin);
         printf("\nIndirizzo: ");
         fflush(stdin);
         gets(Pren.Indirizzo);
         fflush(stdin);
         printf("\nNumero di telefono: ");
         fflush(stdin);
         scanf("%d",&Pren.Telefono);
         printf("\nData prenotazione: ");
         printf("Giorno: ");
         fflush(stdin);
         scanf("%d",&GP2);

         while (GP2>31 || GP2<1)
         {
            printf("Inserire data corretta. Giorno: ");
            fflush(stdin);
            scanf("%d",&GP2);
         }
         Pren.GP=GP2;

         printf("Mese: ");
         fflush(stdin);
         scanf("%d",&MP2);
         while (MP2>12 || MP2<1)
         {
            printf("Inserire data corretta. Mese: ");
            fflush(stdin);
            scanf("%d",&MP2);
         }
         Pren.MP=MP2;

         printf("Anno: ");
         fflush(stdin);
         scanf("%d",&AP2);
         while (AP2<2018)
         {
            printf("Inserire data corretta. Anno: ");
            fflush(stdin);
            scanf("%d",&AP2);
         }
         Pren.AP=AP2;

         printf("Ora: ");
         fflush(stdin);
         scanf("%f",&OP2);
         while (OP2>20 || OP2<8)
         {
            printf("Inserire orario corretto. Ora: ");
            fflush(stdin);
            scanf("%d",&OP2);
         }
         Pren.OP=OP2;

         fwrite(&Pren,sizeof(Pren),1,puntafile);
         fclose(puntafile);
    }
    else exit(1);

    system("cls");
    printf("Inserire un'altra prenotazione?[S/N]");
    fflush(stdin);
    scanf("%c",&R1);

    while (R1=='S' || R1=='s')
    {
         system("cls");
         printf("\nInserire le informazioni relative alla prenotazione: ");
         printf("\n\nNome: ");
         fflush(stdin);
         gets(App.Nome);
         fflush(stdin);
         printf("\nCognome: ");
         fflush(stdin);
         gets(App.Cognome);
         fflush(stdin);
         printf("\nIndirizzo: ");
         fflush(stdin);
         gets(App.Indirizzo);
         fflush(stdin);
         printf("\nNumero di telefono: ");
         fflush(stdin);
         scanf("%d",&App.Telefono);
         printf("\nData prenotazione: ");
         printf("Giorno: ");
         fflush(stdin);
         scanf("%d",&GP2);

         while (GP2>31 || GP2<1)
         {
            printf("Inserire data corretta. Giorno: ");
            fflush(stdin);
            scanf("%d",&GP2);
         }
         App.GP=GP2;

         printf("Mese: ");
         fflush(stdin);
         scanf("%d",&MP2);
         while (MP2>12 || MP2<1)
         {
            printf("Inserire data corretta. Mese: ");
            fflush(stdin);
            scanf("%d",&MP2);
         }
         App.MP=MP2;

         printf("Anno: ");
         fflush(stdin);
         scanf("%d",&AP2);
         while (AP2<2018)
         {
            printf("Inserire data corretta. Anno: ");
            fflush(stdin);
            scanf("%d",&AP2);
         }
         App.AP=AP2;

         printf("Ora: ");
         fflush(stdin);
         scanf("%f",&OP2);
         while (OP2>20 || OP2<8)
         {
            printf("Inserire orario corretto. Ora: ");
            fflush(stdin);
            scanf("%d",&OP2);
         }
         while (!feof(puntafile))
         {
             if (OP2==Pren.OP || OP2==Pren.OP+0.15 || OP2==Pren.OP-0.15)
             {
                 printf("E' gia' presente un appuntamento in questo orario. Scriverne un altro di orario: ");
                 fflush(stdin);
                 scanf("%d",&OP2);
             }
         }
         App.OP=OP2;

         puntafile=fopen("Prenotazioni.dat","rb");
         puntaFile=fopen("Appoggio.dat","ab");

         while (!feof(puntafile))
         {
             f=0;
             if (App.AP<=Pren.AP && App.MP<=Pren.MP && App.GP<=Pren.GP)
             {
                 if (App.OP<Pren.OP)
                 {
                     strcpy(Appoggio.Nome,App.Nome);
                     strcpy(Appoggio.Cognome,App.Cognome);
                     strcpy(Appoggio.Indirizzo,App.Indirizzo);
                     Appoggio.Telefono=App.Telefono;
                     Appoggio.GP=App.GP;
                     Appoggio.MP=App.MP;
                     Appoggio.AP=App.AP;
                     Appoggio.OP=App.OP;
                 }
                 else f=1;
             }
             else f=1;

             if (f==1)
             {
                strcpy(Appoggio.Nome,Pren.Nome);
                strcpy(Appoggio.Cognome,Pren.Cognome);
                strcpy(Appoggio.Indirizzo,Pren.Indirizzo);
                Appoggio.Telefono=Pren.Telefono;
                Appoggio.GP=Pren.GP;
                Appoggio.MP=Pren.MP;
                Appoggio.AP=Pren.AP;
                Appoggio.OP=Pren.OP;
             }
         }
         fclose(puntafile);
         fclose(puntaFile);

         puntafile=fopen("Appoggio.dat","rb");
         puntaFile=fopen("Prenotazioni.dat","ab");

         while (!feof(puntafile))
         {
             strcpy(Pren.Nome,Appoggio.Nome);
             strcpy(Pren.Cognome,Appoggio.Cognome);
             strcpy(Pren.Indirizzo,Appoggio.Indirizzo);
             Pren.Telefono=Appoggio.Telefono;
             Pren.GP=Appoggio.GP;
             Pren.MP=Appoggio.MP;
             Pren.AP=Appoggio.AP;
             Pren.OP=Appoggio.OP;
         }

         fclose(puntafile);
         fclose(puntaFile);

         puntafile=fopen("Appoggio.dat","wb");
         fclose(puntafile);

         printf("Inserire un'altra prenotazione?[S/N]");
         fflush(stdin);
         scanf("%c",&R1);
    }

    system("cls");
    printf("Continuare col programma?[S/N]");
    scanf("%c",&R);

    while (R!='s' || R!='S' && a==0)
    {
        if (R!='N' || R!='n')
        {
            printf("Inserire una risposta valida[S/N]: ");
            scanf("%c",&R);
        }
        else a=1;
    }

    while (R=='s' || R=='S')
    {
        Scelta=Menu();

        if (Scelta==1)
        {
            puntafile=fopen("Prenotazioni.dat","rb");
            if (puntafile)
            {
                while (!feof(puntafile))
                {
                    fread(&Pren,sizeof(Pren),1,puntafile);
                    printf("\nNome: %s",Pren.Nome);
                    fflush(stdin);
                    printf("\nCognome: %s",Pren.Cognome);
                    fflush(stdin);
                    printf("\nIndirizzo: %s",Pren.Indirizzo);
                    fflush(stdin);
                    printf("\nTelefono: %d",Pren.Telefono);
                    fflush(stdin);
                    printf("\nData Prenotazione: %d/%d/%d",Pren.GP,Pren.MP,Pren.AP);
                    fflush(stdin);
                    printf("\nOra Prenotazione: %f",Pren.OP);
                    fflush(stdin);
                    system("pause");
                }
                fclose(puntafile);
            }
            else exit(1);
        }
        else if(Scelta==2)
        {
            system("cls");
            printf("\nInserire le informazioni relative alla prenotazione: ");
            printf("\n\nNome: ");
            fflush(stdin);
            gets(App.Nome);
            fflush(stdin);
            printf("\nCognome: ");
            fflush(stdin);
            gets(App.Cognome);
            fflush(stdin);
            printf("\nIndirizzo: ");
            fflush(stdin);
            gets(App.Indirizzo);
            fflush(stdin);
            printf("\nNumero di telefono: ");
            fflush(stdin);
            scanf("%d",&App.Telefono);
            printf("\nData prenotazione: ");
            printf("Giorno: ");
            fflush(stdin);
            scanf("%d",&GP2);

            while (GP2>31 || GP2<1)
            {
                    printf("Inserire data corretta. Giorno: ");
                    fflush(stdin);
                    scanf("%d",&GP2);
            }
            App.GP=GP2;

            printf("Mese: ");
            fflush(stdin);
            scanf("%d",&MP2);
            while (MP2>12 || MP2<1)
            {
                    printf("Inserire data corretta. Mese: ");
                    fflush(stdin);
                    scanf("%d",&MP2);
            }
            App.MP=MP2;

            printf("Anno: ");
            fflush(stdin);
            scanf("%d",&AP2);
            while (AP2<2018)
            {
                printf("Inserire data corretta. Anno: ");
                fflush(stdin);
                scanf("%d",&AP2);
            }
            App.AP=AP2;

            printf("Ora: ");
            fflush(stdin);
            scanf("%f",&OP2);
            while (OP2>20 || OP2<8)
            {
                printf("Inserire orario corretto. Ora: ");
                fflush(stdin);
                scanf("%d",&OP2);
            }
            while (!feof(puntafile))
            {
                if (OP2==Pren.OP || OP2==Pren.OP+0.15 || OP2==Pren.OP-0.15)
                {
                    printf("E' gia' presente un appuntamento in questo orario. Scriverne un altro di orario: ");
                    fflush(stdin);
                    scanf("%d",&OP2);
                }
            }
            App.OP=OP2;

            puntafile=fopen("Prenotazioni.dat","rb");
            puntaFile=fopen("Appoggio.dat","ab");

            while (!feof(puntafile))
            {
                f=0;
                if (App.AP<=Pren.AP && App.MP<=Pren.MP && App.GP<=Pren.GP)
                {
                    if (App.OP<Pren.OP)
                    {
                        strcpy(Appoggio.Nome,App.Nome);
                        strcpy(Appoggio.Cognome,App.Cognome);
                        strcpy(Appoggio.Indirizzo,App.Indirizzo);
                        Appoggio.Telefono=App.Telefono;
                        Appoggio.GP=App.GP;
                        Appoggio.MP=App.MP;
                        Appoggio.AP=App.AP;
                        Appoggio.OP=App.OP;
                    }
                    else f=1;
                }
                else f=1;

                if (f==1)
                {
                    strcpy(Appoggio.Nome,Pren.Nome);
                    strcpy(Appoggio.Cognome,Pren.Cognome);
                    strcpy(Appoggio.Indirizzo,Pren.Indirizzo);
                    Appoggio.Telefono=Pren.Telefono;
                    Appoggio.GP=Pren.GP;
                    Appoggio.MP=Pren.MP;
                    Appoggio.AP=Pren.AP;
                    Appoggio.OP=Pren.OP;
                }
            }
            fclose(puntafile);
            fclose(puntaFile);

            puntafile=fopen("Appoggio.dat","rb");
            puntaFile=fopen("Prenotazioni.dat","ab");

            while (!feof(puntafile))
            {
                strcpy(Pren.Nome,Appoggio.Nome);
                strcpy(Pren.Cognome,Appoggio.Cognome);
                strcpy(Pren.Indirizzo,Appoggio.Indirizzo);
                Pren.Telefono=Appoggio.Telefono;
                Pren.GP=Appoggio.GP;
                Pren.MP=Appoggio.MP;
                Pren.AP=Appoggio.AP;
                Pren.OP=Appoggio.OP;
            }

            fclose(puntafile);
            fclose(puntaFile);

            puntafile=fopen("Appoggio.dat","wb");
            fclose(puntafile);

            printf("Inserire un'altra prenotazione?[S/N]");
            fflush(stdin);
            scanf("%c",&R1);
        }
        else
        {
            c=0;
            system("cls");
            printf("Inserire la data del giorno del quale si desidera visualizzare le relative prenotazioni:");
            scanf("%d",&GPC);
            printf("/");
            scanf("%d",&MPC);
            printf("/");
            scanf("%d",&APC);
            printf("/");
            puntafile=fopen("Prenotazioni.dat","rb");
            while (!feof(puntafile))
            {
                if (Pren.GP==GPC)
                {
                    if (Pren.MP==MPC)
                    {
                        if (Pren.AP==APC)
                        {
                            fread(&Pren,sizeof(Pren),1,puntafile);
                            printf("\nNome: %s",Pren.Nome);
                            fflush(stdin);
                            printf("\nCognome: %s",Pren.Cognome);
                            fflush(stdin);
                            printf("\nIndirizzo: %s",Pren.Indirizzo);
                            fflush(stdin);
                            printf("\nTelefono: %d",Pren.Telefono);
                            fflush(stdin);
                            printf("\nData Prenotazione: %d/%d/%d",Pren.GP,Pren.MP,Pren.AP);
                            fflush(stdin);
                            printf("\nOra Prenotazione: %f",Pren.OP);
                            fflush(stdin);

                            system("pause");

                            c=1;
                        }
                    }
                }
            }
            if (c==0)
            {
                printf("Non e' stato trovato nessun appuntamento per il giorno indicato");
                system("pause");
            }
        }
    }
    system("cls");
    printf("Continuare col programma?[S/N]");
    scanf("%c",&R);

    while (R!='s' || R!='S' && a==0)
    {
        if (R!='N' || R!='n')
        {
            printf("Inserire una risposta valida[S/N]: ");
            scanf("%c",&R);
        }
        else a=1;
    }
}


int Menu()
{
    system("cls");
    int xScelta;
    printf("\nScegliere tra:\n1-Visualizzare tutti gli appuntamenti registrati\n2-Inserire un nuovo appuntamento in maniera ordinata\n3-Visualizzare le prenotazioni di una giornata scelta\n\nScelta attuale:");
    fflush(stdin);
    scanf("%d",&xScelta);

    while ( xScelta<=0 || xScelta>=7)
    {
        printf("\nScelta errata. Porre scelta corretta.\n\n\nScegliere tra:\n1-Visualizzare tutti gli appuntamenti registrati\n2-Inserire un nuovo appuntamento in maniera ordinata\n3-Visualizzare le prenotazioni di una giornata scelta\n\nScelta attuale:");
        fflush(stdin);
        scanf("%d",&xScelta);
    }

    return xScelta;
}
