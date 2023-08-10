#ifndef URETIMB_H
#define URETIMB_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"

#include "uretim.h"

struct URETIMB{
	Uretim Super;
	
	int (*uret)(long populasyon);
    void (*yoket)(struct URETIMB*);
};
typedef struct URETIMB* UretimB;

UretimB uretimBOlustur();
int uretB(long populasyon);
void yoketB(const UretimB);

#endif