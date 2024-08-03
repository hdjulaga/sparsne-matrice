#include "matrica.h"
#include <stdio.h>
#include <stdlib.h>


void inicmatricu(struct Cvor **prvi)
{
    struct Cvor *novi;
        novi=(struct Cvor *) malloc(sizeof(struct Cvor));
        if (novi==0)
        {
            printf("Nedovoljno memorije...");
            exit(1);
        }
        *prvi=novi;
        *prvi=KRAJ;
    return;
}

void dodajcvor(struct Cvor **prvi,int r)
{
    struct Cvor *novi, *privremeno,*trazicvor,* trazi;

    int vr,i;


        novi=(struct Cvor *) malloc(sizeof(struct Cvor));
        if (novi==0)
        {
            printf("Nedovoljno memorije...");
            exit(1);
        }

        novi->BrojReda=r;
        if(*prvi==KRAJ)
        {
            novi->slijedecired=KRAJ;
            novi->startreda=0;
            *prvi=novi;
            printf("\nCvor %d (Red) matrice je dodat.\n",novi->BrojReda);
            printf("-----------------------------------------------------------------\n");
            return;
        }
        else
        {
            for(trazicvor=*prvi;trazicvor != KRAJ;trazicvor=trazicvor->slijedecired)
                    {
                        privremeno=trazicvor->slijedecired;
                        if (privremeno!=0 && trazicvor->BrojReda<r && privremeno->BrojReda>r)
                        {
                            novi->slijedecired=privremeno;
                             novi->startreda=0;
                            trazicvor->slijedecired=novi;
                            printf("\nCvor %d (Red) matrice je dodat.\n",trazicvor->BrojReda);
                            printf("-----------------------------------------------------------------\n");
                            return;
                        }
                        if (trazicvor==*prvi && trazicvor->BrojReda>r)
                        {
                            novi->slijedecired=trazicvor;
                             novi->startreda=0;
                             *prvi=novi;
                            printf("\nCvor %d (Red) matrice je dodat na pocetak.\n",novi->BrojReda);
                            printf("-----------------------------------------------------------------\n");
                            return;
                        }
                        if (privremeno==0 && trazicvor->BrojReda<r)
                        {
                            novi->slijedecired=0;
                             novi->startreda=0;
                            trazicvor->slijedecired=novi;
                            printf("\nCvor %d (Red) matrice  je dodat kao zadnji element.\n",novi->BrojReda);
                            printf("-----------------------------------------------------------------\n");
                            return;
                        }

                    }
        }


    return;
}

void dodaj(struct Cvor **prvi,int r, int k, float vr)
{
    struct Red *rednovi,*trazired,*privremeno;
    struct Cvor * trazi, *traziprivremeno1,*traziprivremeno2;
    int i;
    float vrpom;

    rednovi=(struct Red *) malloc(sizeof(struct Red));
    if (rednovi==0)
    {
        printf("Nedovoljno memorije...");
        exit(1);
    }
    rednovi->vrijednost=vr;
    rednovi->BrojKolone=k;
    traziprivremeno1=*prvi;
    for(trazi=*prvi;trazi!=KRAJ;trazi=trazi->slijedecired)
    {
        if (trazi->BrojReda==r)
        {


            if(vr!=0 && trazi->startreda==0)
            {
                rednovi->slijedecakolona=0;
                trazi->startreda=rednovi;
                printf("\nElement matrice sa vrijednoscu %7.2f je dodat na pocetak %d. liste - u %d. kolonu %d. reda, i trenutno je jedini element u ovoj listi-jedini razlicit od nule u ovom redu.\n",vr,r,k,r);
                printf("-----------------------------------------------------------------\n");
                return;
            }
            else
            {
                trazired=trazi->startreda;
                if (vr!=0 && trazired->BrojKolone>k)
                {
                    rednovi->slijedecakolona=trazi->startreda;
                    trazi->startreda=rednovi;
                    printf("\nElement matrice sa vrijednoscu %7.2f je dodat na pocetak %d. liste - u %d. koloni %d. reda.\n",vr,r,k,r);
                    printf("-----------------------------------------------------------------\n");
                    return;
                }
                else
                {
                    for(trazired=trazi->startreda;trazired != 0;trazired=trazired->slijedecakolona)
                    {
                        privremeno=trazired->slijedecakolona;
                        if (vr!=0 && privremeno!=0 && trazired->BrojKolone<k && privremeno->BrojKolone>k)
                        {
                            rednovi->slijedecakolona=privremeno;
                            trazired->slijedecakolona=rednovi;
                            printf("\nElement matrice sa vrijednoscu %7.2f je dodat izmedju elemenata u %d. i %d. koloni, %d. liste - u %d.kolonu %d. reda.\n",vr,trazired->BrojKolone,privremeno->BrojKolone,r,k,r);
                            printf("-----------------------------------------------------------------\n");
                            return;
                        }
                        if (vr!=0 && privremeno==0 && trazired->BrojKolone<k)
                        {
                            rednovi->slijedecakolona=0;
                            trazired->slijedecakolona=rednovi;
                            printf("\nElement matrice sa vrijednoscu %7.2f je dodat kao zadnji element, %d. liste - u %d. kolonu %d. reda.\n",vr,r,k,r);
                            printf("-----------------------------------------------------------------\n");
                            return;
                        }
                        if (vr!=0 && trazired->BrojKolone==k)
                        {
                            vrpom=trazired->vrijednost;
                            trazired->vrijednost=vr;
                            printf("\nOvaj element matrice u redu %d i koloni %d je vec postojao i samo mu je promijenjena vrijednost sa %7.2f na %7.2f.\n",r,k,vrpom,vr);
                            printf("-----------------------------------------------------------------\n");
                            return;
                        }
                        if (vr==0 && trazired->BrojKolone==k && trazired==trazi->startreda)
                        {
                            vrpom=trazired->vrijednost;
                            trazi->startreda=privremeno;
                            printf("\nS obzirom da ste za vrijednost unijeli 0, prvi element %d.liste - u %d.koloni u %d.redu je IZBRISAN!\nStara vrijednost za ovaj element je bila:%7.2f.\n",r,k,r,vrpom);
                            printf("-----------------------------------------------------------------\n");
                            free(trazired);
                            if(trazi->startreda==KRAJ) //delociraj cvor ukoliko nema elemenata
                            {
                                i=trazi->BrojReda;
                                if (trazi==*prvi)
                                {
                                    if (trazi->slijedecired==KRAJ)
                                    {
                                    free(trazi);
                                    *prvi=KRAJ;
                                    printf("\nDealociran jedini cvor koji pretstavlja %d.Red matrice.\n",i);
                                     printf("--------------------------------------------------------\n");
                                    } else
                                    {
                                        *prvi=trazi->slijedecired;
                                        free(trazi);
                                        printf("\nDealociran prvi cvor koji pretstavlja %d.Red matrice.\n",i);
                                        printf("--------------------------------------------------------\n");
                                    }
                                }
                                else
                                {
                                    if(trazi->slijedecired!=KRAJ)
                                    {
                                        traziprivremeno2=trazi->slijedecired;
                                        traziprivremeno1->slijedecired=traziprivremeno2;
                                        free(trazi);
                                        printf("\nDealociran cvor koji pretstavlja %d.Red matrice.\n",i);
                                        printf("----------------------------------------------------\n");
                                    } else
                                    {
                                        traziprivremeno1->slijedecired=KRAJ;
                                        free(trazi);
                                        printf("\nDealociran zadnji cvor koji pretstavlja %d.Red matrice.\n",i);
                                        printf("----------------------------------------------------\n");
                                    }
                                }

                            }
                            return;
                        }
                        if (vr==0 && privremeno!=0 && privremeno->BrojKolone==k)
                        {
                            vrpom=privremeno->vrijednost;
                            trazired->slijedecakolona=trazired->slijedecakolona->slijedecakolona;
                            printf("\nS obzirom da ste za vrijednost unijeli 0, ovaj element %d.liste - u %d.koloni u %d.redu je IZBRISAN!\nStara vrijednost za ovaj element je bila:%7.2f.\n",r,k,r,vrpom);
                            printf("-----------------------------------------------------------------\n");
                            free(privremeno);
                            return;
                        }
                    }
                }
            }
            printf("\nUnijeli ste vrijednost NULA, ali ovaj element nije ni postojao sa vrijednoscu razlicitom od NULA tako da je stanje u matrici ostalo nepromijenjeno!\n");

        }
        if(traziprivremeno1!=trazi)
        {
           traziprivremeno1=trazi;
        }
    }
return;
}

void ispiskaolista(struct Cvor **prvi)
{
    struct Cvor *element;
    struct Red *elementreda;
    int i=1;
    printf("\nIspis matrice kao liste elemenata:\n");
    printf("--------------------------------------------------------------\n");
    if(*prvi==KRAJ)
    {
        printf("Sve liste su prazne (dealocirane).\n");
        printf(" PRVI");
        printf("\n  |");
        printf("\n  v");
        printf("\n KRAJ \n ");
        return;
    }

    printf(" PRVI");
    printf("\n  |");
    printf("\n  v");

    for(element=*prvi;element!=KRAJ;element=element->slijedecired)
    {
        printf("\n %d.red ",element->BrojReda);
        if(element->startreda==0)
        {
            printf("->KrajReda.");
        }
        else
        {
            for(elementreda=element->startreda;elementreda!=0;elementreda=elementreda->slijedecakolona)
            {
                printf("->kol:%d vr:%7.2f",elementreda->BrojKolone,elementreda->vrijednost);
            }
            printf("->KrajReda.");

        }
        printf("\n  |");
        printf("\n  v");
        i++;
    }

    printf("\n KRAJ \n ");

    return;
}

void ispiskaomatrica(struct Cvor **prvi,int m,int n)
{
    struct Cvor *element;
    struct Red *elementreda;
    int brkol,i=1,j;
    float nula=0.00;
    printf("\nIspis matrice na standardni nacin:\n");
    printf("---------------------------------\n");
    if(*prvi==KRAJ)
    {
        printf("Svi elementi matrice su nula.\n");
        for(j=1;j<=n;j++)
        printf("\t Kol:%d",j);
        printf("\n");
        for(i=1;i<=m;i++)
        {
            printf("%d.red ",i);
            brkol=1;
          while (brkol<=n)
            {
                printf("%7.2f\t",nula);
                brkol=brkol+1;
            }
            printf("\n");

        }

        return;
    }

    for(j=1;j<=n;j++)
        printf("\t Kol:%d",j);
    printf("\n");
    j=1;

    for(element=*prvi;element!=KRAJ;element=element->slijedecired)
    {
        for(i=j;i<element->BrojReda;i++)
        {
            printf("%d.red ",i);
            brkol=1;
          while (brkol<=n)
            {
                printf("%7.2f\t",nula);
                brkol=brkol+1;
            }
            printf("\n");
        }
            printf("%d.red ",element->BrojReda);
            brkol=1;
            for(elementreda=element->startreda;elementreda!=0;elementreda=elementreda->slijedecakolona)
            {

                while (brkol<=n)
                {
                    if(brkol==elementreda->BrojKolone)
                    {
                        printf("%7.2f\t",elementreda->vrijednost);
                        brkol=brkol+1;
                        break;
                    }
                    else
                    {
                        printf("%7.2f\t",nula);
                    }
                    brkol=brkol+1;
                }
            }
            while (brkol<=n)
            {
                printf("%7.2f\t",nula);
                brkol=brkol+1;
            }
            printf("\n");
        j=element->BrojReda+1;
    }
    if(j<=m)
    {
       for(i=j;i<=m;i++)
        {
            printf("%d.red ",i);
            brkol=1;
          while (brkol<=n)
            {
                printf("%7.2f\t",nula);
                brkol=brkol+1;
            }
            printf("\n");
        }
    }
    return;
}
int trazicvor(struct Cvor **prvi,int r)
{
   struct Cvor * trazi;
    int i;
    int nadjencvor=0;
    for(trazi=*prvi,i=1;trazi!=KRAJ;trazi=trazi->slijedecired,i++)
    {
        if (trazi->BrojReda==r)
        {
            nadjencvor=1;
            break;
        }
    }
    return nadjencvor;
}
float trazi(struct Cvor **prvi,int r, int k)
{
    struct Red *trazired;
    struct Cvor * trazi;
    int i;
    float vrijednost=0.0;

    for(trazi=*prvi,i=1;trazi!=KRAJ;trazi=trazi->slijedecired,i++)
    {
        if (i==r)
        {
            for(trazired=trazi->startreda;trazired != 0;trazired=trazired->slijedecakolona)
            {
                if (trazired->BrojKolone==k)
                {
                    vrijednost=trazired->vrijednost;
                    break;
                }
            }
            break;
         }
    }

return vrijednost;
}

void saberimatrice(struct Cvor ** prviA1,struct Cvor ** prviB1, struct Cvor ** prviC1)
{
    struct Red *traziredA,*traziredB;
    struct Cvor * traziA,*traziB;
    int redA,redB,kolonaA,kolonaB;
    float vrA,vrB,vrC;
    int imacvor;
    printf("\nProlazak kroz matricu A i B....");
    printf("\n-------------------------------");
    for(traziA=*prviA1;traziA!=KRAJ;traziA=traziA->slijedecired)
    {
        imacvor=trazicvor(prviC1,traziA->BrojReda);
        if(imacvor==0)
        {
            dodajcvor(prviC1,traziA->BrojReda);
        }
        redA=traziA->BrojReda;
            for(traziredA=traziA->startreda;traziredA != 0;traziredA=traziredA->slijedecakolona)
            {
                kolonaA=traziredA->BrojKolone;
                vrA=traziredA->vrijednost;
                vrB=trazi(prviB1,redA,kolonaA);
                vrC=vrA+vrB;
                printf("\nVrijednost elementa u %d.redu i %d.koloni matrice C je: %7.2f = %7.2f + %7.2f ",redA,kolonaA,vrC,vrA,vrB);


                dodaj(prviC1,redA,kolonaA,vrC);

            }
     }
    printf("\nProlazak kroz matricu B i A....");
    printf("\n-------------------------------\n");
     for(traziB=*prviB1;traziB!=KRAJ;traziB=traziB->slijedecired)
    {
        redB=traziB->BrojReda;

            for(traziredB=traziB->startreda;traziredB != 0;traziredB=traziredB->slijedecakolona)
            {
                kolonaB=traziredB->BrojKolone;
                vrB=traziredB->vrijednost;
                vrA=trazi(prviA1,redB,kolonaB);
                if (vrA==0.0)
                {
                    imacvor=trazicvor(prviC1,traziB->BrojReda);
                    if(imacvor==0)
                    {
                        dodajcvor(prviC1,traziB->BrojReda);
                    }
                    vrC=vrA+vrB;
                    printf("\nVrijednost elementa u %d.redu i %d.koloni matrice C je %7.2f =%7.2f + %7.2f ",redB,kolonaB,vrC,vrA,vrB);
                    dodaj(prviC1,redB,kolonaB,vrC);
                }

            }
     }

    return;
}

void dealocmatricu(struct Cvor **prvi,int m)
{
    struct Red *trazired,*privremeno1,*privremeno2;
    struct Cvor * trazi, *traziprivremeno1,*traziprivremeno2;
    int i,j;

    for(trazi=*prvi;trazi!=KRAJ;trazi=trazi->slijedecired)
    {
        while(trazi->startreda!=0)
        {
            if (trazi->startreda->slijedecakolona==0)
            {
                free(trazi->startreda);
                trazi->startreda=0;
                printf("\nDealociran prvi element liste u %d.Redu.\n",trazi->BrojReda);
            }
            else
            {
                    for(trazired=trazi->startreda;trazired->slijedecakolona != 0;trazired=trazired->slijedecakolona)
                    {
                        privremeno1=trazired->slijedecakolona;
                        privremeno2=trazired->slijedecakolona->slijedecakolona;

                        if (privremeno2==0)
                        {
                            trazired->slijedecakolona=0;
                            free(privremeno1);
                            printf("\nDealociran element liste u %d.Redu.\n",trazi->BrojReda);

                            break;
                        }
                    }
              }
        }
        printf("\nLista elemenata u %d.Redu je dealocirana.\n",trazi->BrojReda);
        printf("--------------------------------------\n");
    }

  for(j=1;j<=m;j++)
    {
        if (j==m)
        {
            free(trazi);
            *prvi=KRAJ;
            printf("\nDealociran %d.Red.\n",m-j+1);
            printf("-------------------------\n");
        }
        else
        {
           for(trazi=*prvi;trazi->slijedecired != 0;trazi=trazi->slijedecired)
           {
              traziprivremeno1=trazi->slijedecired;
              traziprivremeno2=trazi->slijedecired->slijedecired;
              if (traziprivremeno2==0)
              {
                 i=traziprivremeno1->BrojReda;
                 trazi->slijedecired=0;
                 free(traziprivremeno1);
                 printf("\nDealociran %d.Red.\n",i);
                 break;
              }
          }
       }
    }
return;
}


