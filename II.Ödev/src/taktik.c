#include "taktik.h"

void taktikYoket(const Taktik this)
{
    if(this == NULL) return;
	free(this);
}

Taktik taktikOlustur()
{
    Taktik this = (Taktik)malloc(sizeof(struct TAKTIK));
    this->yoket = &taktikYoket;
    return this;
}