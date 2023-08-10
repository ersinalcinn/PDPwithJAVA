#ifndef KOLONI_H
#define KOLONI_H

#include <stdio.h>

#include <time.h>
#include <stdlib.h> 

#include "uretim.h"
#include "uretimA.h"
#include "uretimB.h"

#include "taktik.h"
#include "taktikA.h"
#include "taktikB.h"


typedef enum bool{false,true} boolean;
struct KOLONI
{
    char    sembol;
    long     populasyon;
    long     yemek;
    int     kazanma;
    int     kaybetme;

    char    uretimTip;
    char    taktikTip;

    void    *uretim;
    void    *taktik;

    int     (*hasar)(struct KOLONI *);
    void    (*savas)(struct KOLONI *koloni_a, struct KOLONI * koloni_b);
    void    (*yoket)(struct KOLONI *this);
    void    (*printKoloni)(struct KOLONI *koloni);
};

typedef struct KOLONI *Koloni;

Koloni  newKoloni(char sembol, int populasyon);

void    printKoloni(Koloni koloni);
int     hasarKoloni(Koloni this);
void    savas(Koloni koloni_a, Koloni koloni_b); 
void    deleteKoloni(Koloni this);

int     getSymbol(int i);



#endif