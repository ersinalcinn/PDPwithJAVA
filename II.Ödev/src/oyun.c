#include "oyun.h"

void    deleteOyun(Oyun oyun, int sayi)
{
    oyun->deleteKoloniler(oyun->koloniler, sayi);
    free(oyun);
}

Oyun  newOyun(int *ac, char *av)
{
    Oyun this = (Oyun)malloc(sizeof(struct OYUN));

    this->tur = 0;
    this->getKoloniler = &getKoloniler;
    this->printKoloniler = &printKoloniler;
    this->uretKoloniler = &uretKoloniler;
    this->turetKoloniler = &turetKoloniler;
    this->yedirKoloniler = &yedirKoloniler;
    this->savastirKoloniler = &savastirKoloniler;
    this->deleteOyun = &deleteOyun;
    this->deleteKoloniler = &deleteKoloniler;

    this->koloniler = this->getKoloniler(ac, av);

    return this;
}

int getAc(const char *str)
{
    const char *delim = " ";
    char *token;
    char *str_copy = strdup(str);
    int ac = 1;

    if (str_copy == NULL) {
        printf("malloc hata\n");
        exit(1);
    }

    token = strtok(str_copy, delim);

    while (token != NULL)
    {
        int number = atoi(token);
        if (number > 0)
        {
            ac++;
        }

        else
        {
            printf("lutfen gecerli bir input giriniz!(sadece pozitif sayilar ve bosluk)\n");
            exit(1);

        }

        token = strtok(NULL, delim);
    }

    free(str_copy);
    return (ac);
}

Koloni *getKoloniler(int *arc, char *av)
{
    Koloni *koloniler;

    *arc = getAc(av);
    int ac = *arc;
    const char *delim = " ";
    char *token;
    char *str_copy = strdup(av);
    
    koloniler = (Koloni *)malloc((sizeof(Koloni) + 1) * (ac - 1));
    token = strtok(str_copy, delim);

    int i = 1;
    while (token != NULL)
    {
        int number = atoi(token);
        if (number > 0)
        {
            koloniler[i - 1] = newKoloni(i + 33, number);
            i++;
        }

        token = strtok(NULL, delim);
    }
    koloniler[ac - 1] = NULL;
    
    return koloniler;
}

void printKoloniler(Koloni *koloniler, int sayi)
{
    printf("Koloni\t\tPop.\t\tYemek\t\tKazanma\t\tKaybetme\n");
    for (int i = 0; i < sayi; i++)
    {
        koloniler[i]->printKoloni(koloniler[i]);
    }
}

boolean isGood(Koloni *koloniler, int sayi)
{
    int kontrol = 0;

    for (int i = 0; i < sayi; i++)
    {
        if (koloniler[i]->populasyon == 0)
        {
            kontrol++;
        }
    }

    if (sayi - 1 <= kontrol)
    {
        return false;
    }
    return true;
}

void    uretKoloniler(Koloni *koloniler, int sayi)
{
    for (int i = 0; i < sayi; i++)
    {
        if (koloniler[i]->populasyon > 0)
        {
            if (koloniler[i]->uretimTip == 'a')
            {
                koloniler[i]->yemek += ((UretimA)(koloniler[i]->uretim))->uret(koloniler[i]->populasyon);
            }

            if (koloniler[i]->uretimTip == 'b')
            {
                koloniler[i]->yemek += ((UretimB)(koloniler[i]->uretim))->uret(koloniler[i]->populasyon);
            }

        }

        
    }
    
}

void    turetKoloniler(Koloni *koloniler, int sayi)
{
    for (int i = 0; i < sayi; i++)
    {
        if (koloniler[i]->populasyon > 0)
        {
            koloniler[i]->populasyon += koloniler[i]->populasyon / 5;

        }
    }
    
}

void    yedirKoloniler(Koloni *koloniler, int sayi)
{
    for (int i = 0; i < sayi; i++)
    {
        if (koloniler[i]->populasyon > 0)
        {
            koloniler[i]->yemek -= koloniler[i]->populasyon * 2;
            if (koloniler[i]->yemek < 0)
            {
                koloniler[i]->populasyon = 0;
                koloniler[i]->yemek = 0;
            }

        }
    }
    
}



void    savastirKoloniler(Koloni *koloniler, int sayi)
{
    for (int i = 0; i < sayi; i++)
    {
        for (int j = i + 1; j < sayi; j++)
        {
            if (koloniler[i]->populasyon > 0 && koloniler[j]->populasyon > 0)
            {
                
                koloniler[i]->savas(koloniler[i], koloniler[j]);
            }
            
        }
        
    }
    
}

void    deleteKoloniler(Koloni *koloniler, int sayi)
{
    for (int i = 0; i < sayi; i++)
    {
        koloniler[i]->yoket(koloniler[i]);
    }
    free(koloniler);
    
}