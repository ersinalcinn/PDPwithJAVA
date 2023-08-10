#include "uretimB.h"

int uretB(long populasyon)
{
    int artis = 1 + ((populasyon % 10) * rand()) % 10;
    return (artis);
}

void yoketB(const UretimB this)
{
    if(this == NULL) return;
    this->Super->yoket(this->Super);
	free(this);
}

UretimB uretimBOlustur()
{
    UretimB this = (UretimB)malloc(sizeof(struct URETIMB));
    this->uret = &uretB;
    this->yoket = &yoketB;
    this->Super = uretimOlustur();
    return this;
}