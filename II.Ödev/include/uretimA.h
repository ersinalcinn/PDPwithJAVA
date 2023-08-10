#ifndef URETIMA_H
#define URETIMA_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"

#include "uretim.h"

struct URETIMA{
	Uretim Super;
	
	int (*uret)(long populasyon);
    void (*yoket)(struct URETIMA*);
};
typedef struct URETIMA* UretimA;

UretimA uretimAOlustur();
int uretA(long populasyon);
void yoketA(const UretimA);

#endif
