#ifndef TAKTIKB_H
#define TAKTIKB_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"

#include "taktik.h"

struct TAKTIKB{
	Taktik Super;
	
	int (*atak)(long populasyon);
    void (*yoket)(struct TAKTIKB*);
};
typedef struct TAKTIKB* TaktikB;

TaktikB taktikBOlustur();
int atakB(long populasyon);
void yoketTB(const TaktikB);

#endif