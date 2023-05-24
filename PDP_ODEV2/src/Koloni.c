#include "Koloni.h"

Koloni koloniOlustur(int populasyon,char sembol)
{
    Koloni this;
    this = (Koloni)malloc(sizeof(struct KOLONI));
    this->populasyon = populasyon;
    this->yemekStogu = populasyon * populasyon;
    this->sembol = sembol;
    this->savasabilirMi = 1;
    this->kaybetme = 0;
    this->kazanma = 0;
    return this;
}

void KoloniYokEt(const Koloni this)
{
    free(this);
}