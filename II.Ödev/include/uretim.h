#ifndef URETIM_H
#define URETIM_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"

struct URETIM{
	int a;
	
	int (*uret)(int populasyon);
    void (*yoket)(struct URETIM*);
};
typedef struct URETIM* Uretim;

//int uret(int populasyon);
Uretim uretimOlustur();
void uretimYoket(const Uretim);

#endif
