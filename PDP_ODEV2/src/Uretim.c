#include "Uretim.h"

Uretim new_Uretim()
{
    Uretim this;
    this = (Uretim)malloc(sizeof(struct URETIM));

    this->yoket = &UretimYokEt;

    return this;
}
void UretimYokEt(const Uretim this)
{
    if (this == NULL)
        return;

    free(this);
}