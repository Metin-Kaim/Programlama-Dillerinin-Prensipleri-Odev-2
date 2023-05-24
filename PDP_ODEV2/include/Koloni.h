#ifndef KOLONI_H
#define KOLONI_H

#include "stdio.h"
#include "stdlib.h"
#include <time.h> 

struct KOLONI
{
    int populasyon;
    int yemekStogu;
    char sembol;
    int savasabilirMi;
    int kazanma;
    int kaybetme;
};
typedef struct KOLONI* Koloni;

Koloni koloniOlustur(int,char);
void KoloniYokEt(const Koloni);

#endif