#include "Taktik.h"

Taktik new_Taktik()
{
    Taktik this;
    this = (Taktik)malloc(sizeof(struct TAKTIK));

    this->yoket = &TaktikYokEt;

    return this;
}
void TaktikYokEt(const Taktik this)
{
    if (this == NULL)
        return;

    free(this);
}