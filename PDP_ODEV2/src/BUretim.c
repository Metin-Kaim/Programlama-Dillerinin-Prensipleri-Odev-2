#include "BUretim.h"

BUretim BUretim_Olustur()
{
    BUretim this;
    this = (BUretim)malloc(sizeof(struct BURETIM));
    this->super = new_Uretim();

    this->super->Uret = &BUret;
    this->yoket = &BUretimYokEt;
    return this;
}
int BUret()
{
    int value = rand()%101;
	if(value < 30)
    return rand() % 6;
	else
	return 5 + (rand() % 6);
}
void BUretimYokEt(const BUretim this)
{
    if (this == NULL)
        return;
    this->super->yoket(this->super);
    free(this);
}