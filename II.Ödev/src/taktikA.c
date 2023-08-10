#include "taktikA.h"

int atakA(long populasyon)
{
    long atak = (rand() % 1001);
    return (atak);
}

TaktikA taktikAOlustur()
{
    TaktikA this = (TaktikA)malloc(sizeof(struct TAKTIKA));
    this->atak = &atakA;
    this->yoket = &yoketTA;
    this->Super = taktikOlustur();
    return this;
}

void yoketTA(const TaktikA this)
{
    if(this == NULL) return;
    this->Super->yoket(this->Super);
	free(this);
}

