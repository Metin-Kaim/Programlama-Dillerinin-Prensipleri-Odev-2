#ifndef ATAKTIK_H
#define ATAKTIK_H

#include "Taktik.h"

struct ATAKTIK{
    Taktik super;

    void (*yoket) (struct ATAKTIK*);
};
typedef struct ATAKTIK* ATaktik;

ATaktik ATaktik_Olustur();
int ASavas();
void ATaktikYokEt(const ATaktik);

#endif