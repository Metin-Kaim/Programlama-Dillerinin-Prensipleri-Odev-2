#ifndef AURETIM_H
#define AURETIM_H

#include "Uretim.h"

struct AURETIM{
    Uretim super;

    void (*yoket) (struct AURETIM*);
};
typedef struct AURETIM* AUretim;

AUretim AUretim_Olustur();
int AUret();
void AUretimYokEt(const AUretim);

#endif