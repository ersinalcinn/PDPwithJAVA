#ifndef TAKTIKA_H
#define TAKTIKA_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"

#include "taktik.h"

struct TAKTIKA{
	Taktik Super;
	
	int (*atak)(long populasyon);
    void (*yoket)(struct TAKTIKA*);
};
typedef struct TAKTIKA* TaktikA;

int atakA(long populasyon);
TaktikA taktikAOlustur();
void yoketTA(const TaktikA);

#endif
