#ifndef OYUN_H
#define OYUN_H

#include "Koloni.h"
#include "Taktik.h"
#include "ATaktik.h"
#include "BTaktik.h"
#include "AUretim.h"
#include "BUretim.h"

#include <string.h>
#include <math.h>

struct OYUN
{
    void (*SavasSonrasi)(int , int , int , int , Koloni *);
    void (*oyunBaslat)(struct OYUN*);
    void (*yoket)(struct OYUN*);
};
typedef struct OYUN* Oyun;

Oyun oyunOlustur();
void savasSonrasi(int , int , int , int , Koloni *);
void oyunBaslat(Oyun);
void oyunYokEt(Oyun);
#endif