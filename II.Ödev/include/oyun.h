#ifndef OYUN_H
#define OYUN_H

#include "koloni.h"



struct OYUN
{
    int tur;

    Koloni *koloniler;


    Koloni* (*getKoloniler)(int *ac, char *av);
    void    (*printKoloniler)(Koloni *koloniler, int sayi);

    void   (*uretKoloniler)(Koloni *koloniler, int sayi);
    void   (*turetKoloniler)(Koloni *koloniler, int sayi);
    void    (*yedirKoloniler)(Koloni *koloniler, int sayi);
    void    (*savastirKoloniler)(Koloni *koloniler, int sayi);
    void    (*deleteOyun)(struct OYUN* oyun, int sayi);
    void    (*deleteKoloniler)(Koloni *koloniler, int sayi);
};

typedef struct OYUN *Oyun;

Oyun  newOyun(int *ac, char *av);



boolean isGood(Koloni *koloniler, int sayi);
Koloni *getKoloniler(int *ac, char *av);

void    printKoloniler(Koloni *koloniler, int sayi);

void    uretKoloniler(Koloni *koloniler, int sayi);
void    turetKoloniler(Koloni *koloniler, int sayi);
void    yedirKoloniler(Koloni *koloniler, int sayi);
void    savastirKoloniler(Koloni *koloniler, int sayi);

void    deleteKoloniler(Koloni *koloniler, int sayi);
void    deleteOyun(Oyun oyun, int sayi);

int     getAc(const char *str);
#endif