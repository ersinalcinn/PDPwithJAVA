#include "koloni.h"



Koloni newKoloni(char sembol, int populasyon)
{
    Koloni this;
    static int i = 0;
    if (i == 0)
    {
        i = 1 + (rand() % 5);
    }
    if (i > 50)
    {
        printf("50 den az koloni olusturunuz!");
        exit(0);
    }
    
    char *codex = "n~!@#$%^&*()_+-=[]{};:'\",./<>|\\qwezxcasdQWEASDZXCpfghFGH";

    this = (Koloni)malloc(sizeof(struct KOLONI));
    this->sembol = codex[i++];
    this->populasyon = populasyon;
    this->yemek = populasyon * populasyon;
    this->kazanma = 0;
    this->kaybetme = 0;


    this->hasar = &hasarKoloni;
    this->savas = &savas;
    this->yoket = &deleteKoloni;
    this->printKoloni = &printKoloni;
    
    if (rand() % 2 == 0)
    {
        this->uretim = uretimAOlustur();
        this->uretimTip = 'a';
    }
    else
    {
        this->uretim = uretimBOlustur();
        this->uretimTip = 'b';
    }

    if (rand() % 2 == 0)
    {
        this->taktik = taktikAOlustur();
        this->taktikTip = 'a';
    }
    else
    {
        this->taktik = taktikBOlustur();
        this->taktikTip = 'b';
    }


    // uretim,yemek

    return this;
}

void printKoloni(Koloni koloni)
{
    printf("%c\t\t%d\t\t%d\t\t%d\t\t%d\n", koloni->sembol, koloni->populasyon, koloni->yemek, koloni->kazanma, koloni->kaybetme);
}

int hasarKoloni(Koloni this)
{
    if (this->taktikTip == 'a')
    {
        return(((TaktikA)(this->taktik))->atak(this->populasyon));
    }

    if (this->taktikTip == 'b')
    {
        return(((TaktikB)(this->taktik))->atak(this->populasyon));
    }

}
void    savas(Koloni koloni1, Koloni koloni2)
{
    int atak1 = koloni1->hasar(koloni1);
    int atak2 = koloni2->hasar(koloni2);

    if (atak1 > atak2)
    {
        koloni2->populasyon -= (koloni2->populasyon * ((atak1 - atak2) / 10)) / 100;
        koloni1->yemek += (koloni2->yemek * ((atak1 - atak2) / 10)) / 100;
        koloni2->yemek -= (koloni2->yemek * ((atak1 - atak2) / 10)) / 100;
        koloni1->kazanma++;
        koloni2->kaybetme++;
 
    }

    else if (atak1 < atak2)
    {
        koloni1->populasyon -= (koloni1->populasyon * ((atak1 - atak2) / 10)) / 100;
        koloni2->yemek += (koloni1->yemek * ((atak1 - atak2) / 10)) / 100;
        koloni1->yemek -= (koloni1->yemek * ((atak1 - atak2) / 10)) / 100;
        koloni2->kazanma++;
        koloni1->kaybetme++;

    }

    else
    {
        if ((rand() % 2) == 0)
        {
            koloni2->kazanma++;
            koloni1->kaybetme++;

        }
        else
        {
            koloni1->kazanma++;
            koloni2->kaybetme++;


        }
    }

    if(koloni1->populasyon <= 0 || koloni1->yemek <= 0)
    {
        koloni1->populasyon = 0;
        koloni1->yemek = 0;

    }

    if(koloni2->populasyon <= 0 || koloni2->yemek <= 0)
    {
        koloni2->populasyon = 0;
        koloni2->yemek = 0;
    }


}

void    deleteKoloni(Koloni this)
{
    if (this->taktikTip == 'a')
    {
        (((TaktikA)(this->taktik))->yoket((TaktikA)(this->taktik)));
    }

    if (this->taktikTip == 'b')
    {
        (((TaktikB)(this->taktik))->yoket((TaktikB)(this->taktik)));
    }


    if (this->uretimTip == 'a')
    {
        ((UretimA)(this->uretim))->yoket((UretimA)(this->uretim));
    }

    if (this->uretimTip == 'b')
    {
        ((UretimB)(this->uretim))->yoket((UretimB)(this->uretim));
    }
    free(this);

}
