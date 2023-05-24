#ifndef TAKTIK_H
#define TAKTIK_H

#include "stdio.h"
#include "stdlib.h"
#include <time.h> 

struct TAKTIK
{
    int (*Savas)();

    void (*yoket)(struct TAKTIK *);
};

typedef struct TAKTIK *Taktik;

Taktik new_Taktik();
void TaktikYokEt(const Taktik);

#endif