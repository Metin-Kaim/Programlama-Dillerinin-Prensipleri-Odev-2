#ifndef BURETIM_H
#define BURETIM_H

#include "Uretim.h"

struct BURETIM{
    Uretim super;

    void (*yoket) (struct BURETIM*);
};
typedef struct BURETIM* BUretim;

BUretim BUretim_Olustur();
int BUret();
void BUretimYokEt(const BUretim);

#endif