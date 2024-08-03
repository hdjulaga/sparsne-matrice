#include "matrica.h"
#include <stdio.h>
#include <stdlib.h>


struct Cvor * prviA, * prviB, * prviC;


void unosredkolona (int * r, int * k, int m, int n)
{
    int r1,k1;

    printf("\tUnesite broj reda:");
    scanf("%d",&r1);
    while (!(r1>0 && r1<=m))
    {
        printf("Broj reda mora biti veci od 0 i manji ili jednak max broju redova: %d.\nPokusajte ponovo.\n",m);
        printf("\tUnesite broj reda:");
        scanf("%d",&r1);
    }

    printf("\tUnesite broj kolone:");
    scanf("%d",&k1);
    while (!(k1>0 && k1<=n))
    {
        printf("Broj kolone mora biti veci od 0 i manji ili jednak max broju kolona: %d.\nPokusajte ponovo.\n",n);
        printf("\tUnesite broj reda:");
        scanf("%d",&k1);
    }

    *r=r1;
    *k=k1;
     return;
}

int izbornik(void)
{
    int izbor;
    printf("\n\n             I Z B O R N I K :");
    printf("\n   ============================================");
    printf("\n 1.Unos novog elementa u matricu A ");
    printf("\n 2.Citanje vrijednosti elementa iz matrice A ");
    printf("\n 3.Ispis matrice A ");
    printf("\n   --------------------------------------------");
    printf("\n 4.Unos novog elementa u matricu B ");
    printf("\n 5.Citanje vrijednosti elementa iz matrice B ");
    printf("\n 6.Ispis matrice B ");
    printf("\n   --------------------------------------------");
    printf("\n 7.Izracunav.,ispis i dealokacija matrice C=A+B ");
    printf("\n   --------------------------------------------");
    printf("\n 8.Izlaz - dealokacija matrica A,B ");
    printf("\n   ============================================");
    printf("\n          Izbor = ");
    scanf("%d",&izbor);
    return izbor;
}
int main(void)
{
    int izbor,m,n;
    int r, k;
    float vr;
    printf("\n*** S P A R S N E   M A T R I C E  ***\n");
    printf("--------------------------------------\n\n");
    printf("Inicijalizacija matrica: A, B.\n");
    printf("----------------------------------\n");
    printf("  Unesite broj redova:");
    scanf("%d",&m);
    printf("  Unesite broj kolona:");
    scanf("%d",&n);
    printf("\n-----------------------------------------------------------\n");
    inicmatricu(&prviA);
    inicmatricu(&prviB);

    printf("Inicijalizacije matrica A i B velicine %d redova x %d kolona\nje uspjesno izvrsena!!!",m,n);
    printf("\n-----------------------------------------------------------");
    printf("\nPritisnite bilo koju tipku za nastavak...");
    getch();
    int imacvor;
    do
    {
        switch(izbor=izbornik())
        {
            case 1:
                printf("\nAzuriranje elemenata matrice A.\n");
                printf("--------------------------------\n");
                unosredkolona(&r,&k,m,n);
                printf("\tUnesite vrijednost:");
                scanf("%f",&vr);
                printf("------------------------------------------\n");
                imacvor=trazicvor(&prviA,r);
                if(imacvor==0)
                {
                    dodajcvor(&prviA,r);
                }
                dodaj(&prviA,r,k,vr);
                ispiskaolista(&prviA);
                ispiskaomatrica(&prviA,m,n);
                printf("\n------------------------------------------");
                printf("\nPritisnite bilo koju tipku za nastavak...");
                getch();
                break;
            case 2:
                printf("\nCitanje vrijednosti elementa iz matrice A.\n");
                printf("------------------------------------------\n");
                unosredkolona(&r,&k,m,n);
                vr=trazi(&prviA,r,k);
                printf("\n-------------------------------------------------------\n");
                printf("Element u redu %d i koloni %d ima vrijednost: %7.2f ",r,k,vr);
                printf("\n-------------------------------------------------------");
                printf("\nPritisnite bilo koju tipku za nastavak...");
                getch();
                break;
            case 3:
                printf("\nIspis matrice A.\n");
                printf("--------- -------\n");
                ispiskaolista(&prviA);
                ispiskaomatrica(&prviA,m,n);
                printf("\n------------------------------------------");
                printf("\nPritisnite bilo koju tipku za nastavak...");
                getch();
                break;
            case 4:
                printf("\nAzuriranje elemenata matrice B.\n");
                printf("--------------------------------\n");
                unosredkolona(&r,&k,m,n);
                printf("\tUnesite vrijednost:");
                scanf("%f",&vr);
                imacvor=trazicvor(&prviB,r);
                if(imacvor==0)
                {
                    dodajcvor(&prviB,r);
                }
                dodaj(&prviB,r,k,vr);
                ispiskaolista(&prviB);
                ispiskaomatrica(&prviB,m,n);
                printf("\n------------------------------------------");
                printf("\nPritisnite bilo koju tipku za nastavak...");
                getch();
                break;
             case 5:
                printf("\nCitanje vrijednosti elementa iz matrice B.\n");
                printf("-----------------------------------------\n");
                unosredkolona(&r,&k,m,n);
                vr=trazi(&prviB,r,k);
                printf("\n-------------------------------------------------------\n");
                printf("Element u redu %d i koloni %d ima vrijednost: %7.2f ",r,k,vr);
                printf("\n-------------------------------------------------------");
                printf("\nPritisnite bilo koju tipku za nastavak...");
                getch();
                break;
            case 6:
                printf("\nIspis matrice B.\n");
                printf("-----------------\n");
                ispiskaolista(&prviB);
                ispiskaomatrica(&prviB,m,n);
                printf("\n------------------------------------------");
                printf("\nPritisnite bilo koju tipku za nastavak...");
                getch();
                break;
            case 7:
                printf("\nIzracunavanje matrice C kao zbir matrica A i B.\n");
                printf("-------------------------------------------------\n");
                inicmatricu(&prviC);
                printf("Inicijalizacije matrice C velicine %d redova x %d kolona\nje uspjesno izvrsena!!!",m,n);
                printf("\n-----------------------------------------------------------");
                saberimatrice(&prviA,&prviB,&prviC);
                printf("Pritisnite bilo koju tipku za ispis sabrane matrice C ...");
                getch();
                printf("\n\nIspis matrice C.\n");
                printf("-----------------\n");
                ispiskaolista(&prviC);
                ispiskaomatrica(&prviC,m,n);

                printf("\n------------------------------------------");
                printf("\nPritisnite bilo koju tipku za nastavak...");
                getch();
                printf("\n\nDealokacija matrice C.\n");
                printf("--------------------------------\n");
                dealocmatricu(&prviC,m);
                printf("\nIspis matrice C.\n");
                printf("--------- -------\n");
                ispiskaolista(&prviC);
                ispiskaomatrica(&prviC,m,n);
                printf("\n------------------------------------------");
                printf("\nPritisnite bilo koju tipku za nastavak...");
                getch();
                break;
            case 8:
                printf("\n\nDealokacija matrice A.\n");
                printf("--------------------------------\n");
                dealocmatricu(&prviA,m);
                printf("\nIspis matrice A.\n");
                printf("--------- -------\n");
                ispiskaolista(&prviA);
                ispiskaomatrica(&prviA,m,n);
                printf("\n------------------------------------------");
                printf("\nPritisnite bilo koju tipku za nastavak...");
                getch();
                printf("\n\nDealokacija matrice B.\n");
                printf("--------------------------------\n");
                dealocmatricu(&prviB,m);
                printf("\nIspis matrice B.\n");
                printf("--------- -------\n");
                ispiskaolista(&prviB);
                ispiskaomatrica(&prviB,m,n);
                printf("\n------------------------------------------");
                printf("\nPritisnite bilo koju tipku za nastavak...");
                getch();


                break;
            default:
                printf("\n Pogresan izbor - pokusajte ponovo.\n");
                printf("-----------------------------------\n");
        }
    } while(izbor!=8);
    return 0;
}
