#ifndef TAKTIK_H
#define TAKTIK_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"

struct TAKTIK{
	int a;
	
	int (*atak)(int populasyon);
    void (*yoket)(struct TAKTIK*);
};
typedef struct TAKTIK* Taktik;

//int uret(int populasyon);
Taktik taktikOlustur();
void taktikYoket(const Taktik);

#endif