// TODO:: Savaş sistemini yaz.
#include "ATaktik.h"
#include "BTaktik.h"
#include "AUretim.h"
#include "BUretim.h"
#include "Koloni.h"
#include "Oyun.h"


void SavasSonrasi(int aSavas, int bSavas, int winner, int loser, Koloni *colonies)
{
    int fark = aSavas - bSavas;
    fark = (fark * 100) / 1000; // 1000'e oranı
    int farkPopulasyon = ceil((colonies[loser]->populasyon * fark) / 100.0);
    // printf("pop:%d,fark:%d,fp:%d\n", colonies[loser]->populasyon, fark, farkPopulasyon);
    colonies[loser]->populasyon -= farkPopulasyon;

    int farkYemek = ceil((colonies[loser]->yemekStogu * fark) / 100); // b'nın yemek stoğunun %x'i
    colonies[loser]->yemekStogu -= farkYemek;
    colonies[winner]->yemekStogu += farkYemek;

    colonies[winner]->kazanma++;
    colonies[loser]->kaybetme++;
}

int main()
{
    Oyun oyun = oyunOlustur();
    
    oyun->oyunBaslat(oyun);
    
    oyun->yoket(oyun);

    return 0;
}