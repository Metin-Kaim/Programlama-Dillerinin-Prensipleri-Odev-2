#include "ATaktik.h"

ATaktik ATaktik_Olustur()
{
    ATaktik this;
    this = (ATaktik)malloc(sizeof(struct ATAKTIK));
    this->super = new_Taktik();

    this->super->Savas = &ASavas;
    this->yoket = &ATaktikYokEt;
    return this;
}

int ASavas()
{
	int value = rand()%101;
	if(value < 60)
    return rand() % 501;
	else
	return 500 + (rand() % 501);
}
void ATaktikYokEt(const ATaktik this)
{
    if (this == NULL)
        return;
    this->super->yoket(this->super);
    free(this);
}