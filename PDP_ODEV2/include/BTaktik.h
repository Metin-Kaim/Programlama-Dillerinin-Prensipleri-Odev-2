#ifndef BTAKTIK_H
#define BTAKTIK_H

#include "Taktik.h"

struct BTAKTIK{
    Taktik super;

    void (*yoket) (struct BTAKTIK*);
};
typedef struct BTAKTIK* BTaktik;

BTaktik BTaktik_Olustur();
int BSavas();
void BTaktikYokEt(const BTaktik);

#endif