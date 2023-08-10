#include "taktikB.h"

int atakB(long populasyon)
{
    int atak = ((populasyon % 1001) * rand()) % 1001;
    return (atak);
}

TaktikB taktikBOlustur()
{
    TaktikB this = (TaktikB)malloc(sizeof(struct TAKTIKB));
    this->atak = &atakB;
    this->yoket = &yoketTB;
    this->Super = taktikOlustur();
    return this;
}

void yoketTB(const TaktikB this)
{
    if(this == NULL) return;
    this->Super->yoket(this->Super);
	free(this);
}