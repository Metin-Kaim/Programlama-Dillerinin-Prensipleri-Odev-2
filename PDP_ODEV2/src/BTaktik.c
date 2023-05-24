#include "BTaktik.h"

BTaktik BTaktik_Olustur()
{
    BTaktik this;
    this = (BTaktik)malloc(sizeof(struct BTAKTIK));
    this->super = new_Taktik();

    this->super->Savas = &BSavas;
    this->yoket = &BTaktikYokEt;
    return this;
}

int BSavas()
{
    int value = rand()%101;
	if(value < 30)
    return rand() % 501;
	else
	return 500 + (rand() % 501);
}
void BTaktikYokEt(const BTaktik this)
{
    if (this == NULL)
        return;
    this->super->yoket(this->super);
    free(this);
}