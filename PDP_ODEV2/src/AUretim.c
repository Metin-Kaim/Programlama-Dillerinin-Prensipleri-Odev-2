#include "AUretim.h"

AUretim AUretim_Olustur()
{
    AUretim this;
    this = (AUretim)malloc(sizeof(struct AURETIM));
    this->super = new_Uretim();

    this->super->Uret = &AUret;
    this->yoket = &AUretimYokEt;
    return this;
}

int AUret()
{
	int value = rand()%101;
	if(value < 60)
    return rand() % 6;
	else
	return 5 + (rand() % 6);
}
void AUretimYokEt(const AUretim this)
{
    if (this == NULL)
        return;
    this->super->yoket(this->super);
    free(this);
}