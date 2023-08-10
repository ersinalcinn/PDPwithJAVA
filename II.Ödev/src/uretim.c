#include "uretim.h"

void uretimYoket(const Uretim this)
{
    if(this == NULL) return;
	free(this);
}

Uretim uretimOlustur()
{
    Uretim this = (Uretim)malloc(sizeof(struct URETIM));
    this->yoket = &uretimYoket;
    return this;
}