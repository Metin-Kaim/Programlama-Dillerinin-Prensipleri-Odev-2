#ifndef URETIM_H
#define URETIM_H

#include "stdio.h"
#include "stdlib.h"
#include <time.h>

struct URETIM
{
     int (*Uret)();

    void (*yoket)(struct URETIM *);
};

typedef struct URETIM *Uretim;

Uretim new_Uretim();
void UretimYokEt(const Uretim);

#endif