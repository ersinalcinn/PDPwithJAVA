#include "uretimA.h"

int uretA(long populasyon)
{
    int artis = 1 + (rand() % 10);
    return (artis);
}

void yoketA(const UretimA this)
{
    if(this == NULL) return;
    this->Super->yoket(this->Super);
	free(this);
}

UretimA uretimAOlustur()
{
    UretimA this = (UretimA)malloc(sizeof(struct URETIMA));
    this->uret = &uretA;
    this->yoket = &yoketA;
    this->Super = uretimOlustur();
    return this;
}