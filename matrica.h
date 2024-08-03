#ifndef MATRICA_H
#define MATRICA_H

#define KRAJ (struct Cvor *) 0

struct Cvor
{
    int BrojReda;
    struct Cvor *slijedecired;
    struct Red *startreda;
};

struct Red
{
    int BrojKolone;
    float vrijednost;
    struct Red *slijedecakolona;
};



void inicmatricu(struct Cvor **prvi);
void dodajcvor(struct Cvor **prvi,int r);
void dodaj(struct Cvor **prvi,int r, int k, float vr);
void ispiskaolista(struct Cvor **prvi);
void ispiskaomatrica(struct Cvor **prvi,int m,int n);
int trazicvor(struct Cvor **prvi,int r);
float trazi(struct Cvor **prvi,int r, int k);
void saberimatrice(struct Cvor ** prviA1,struct Cvor ** prviB1,struct Cvor ** prviC1);
void dealocmatricu(struct Cvor **prvi,int m);

#endif
