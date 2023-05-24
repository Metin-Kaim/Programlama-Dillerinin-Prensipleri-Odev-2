#include "Oyun.h"

Oyun oyunOlustur()
{
    Oyun this;
    this = (Oyun)malloc(sizeof(struct OYUN));
    this->SavasSonrasi = &savasSonrasi;
    this->oyunBaslat = &oyunBaslat;
    this->yoket = &oyunYokEt;
    return this;
}

void savasSonrasi(int aSavas, int bSavas, int winner, int loser, Koloni *colonies)
{
    int fark = aSavas - bSavas;
    fark = (fark * 100) / 1000; // 1000'e oranı
    int farkPopulasyon = ceil((colonies[loser]->populasyon * fark) / 100.0);
	
    colonies[loser]->populasyon -= farkPopulasyon;

    int farkYemek = ceil((colonies[loser]->yemekStogu * fark) / 100); // b'nın yemek stoğunun %x'i
    colonies[loser]->yemekStogu -= farkYemek;
    colonies[winner]->yemekStogu += farkYemek;

    colonies[winner]->kazanma++;
    colonies[loser]->kaybetme++;
}

void oyunBaslat(Oyun this)
{
    ATaktik aTaktik = ATaktik_Olustur();
    BTaktik bTaktik = BTaktik_Olustur();
    AUretim aUretim = AUretim_Olustur();
    BUretim bUretim = BUretim_Olustur();

#pragma region -Get Input From User-

    unsigned int len_max = 128;
    unsigned int current_size = 0;

    char *pStr = malloc(len_max);
    current_size = len_max;

    printf("\nDeger Girin:");

    if (pStr != NULL)
    {
        int c = EOF;
        unsigned int i = 0;
        // accept user input until hit enter or end of file
        while ((c = getchar()) != '\n' && c != EOF)
        {
            pStr[i++] = (char)c;

            // if i reached maximize size then realloc size
            if (i == current_size)
            {
                current_size = i + len_max;
                pStr = realloc(pStr, current_size);
            }
        }

        pStr[i] = '\0';
    }
#pragma endregion

    int uzunluk = strlen(pStr);
    int countOfColonies = 0;
    for (int i = 0; i < uzunluk; i++) // Get Count Of Values
    {
        if (pStr[i] == ' ')
        {
            countOfColonies++;
        }
        if (pStr[i] != ' ' && i == uzunluk - 1)
        {
            countOfColonies++;
        }
    }

    int *values = malloc(sizeof(int) * countOfColonies); // kullanicidan alinan veriler

    int sayac = 0;
    int sayi = 0;

    for (int i = 0; i < uzunluk; i++) // Set all values to int array one by one
    {
        if (pStr[i] != ' ')
        {
            sayi *= 10;
            sayi += pStr[i] - '0';
        }
        else
        {
            values[sayac] = sayi;
            sayi = 0;
            sayac++;
        }
        if (pStr[i] != ' ' && i == uzunluk - 1)
        {
            values[sayac] = sayi;
            sayi = 0;
            sayac++;
        }
    }

    free(pStr);
    Koloni *colonies = malloc(sizeof(struct KOLONI) * countOfColonies);
    int *semboller = malloc(sizeof(int) * countOfColonies);
    int sembolBoolean = 1;

    for (int i = 0; i < countOfColonies; i++) // koloni sayısı kadar koloni olustur
    {
        int sembolsayac = 0;
        do
        {
            sembolsayac++;
            sembolBoolean = 1;
            int sembol = 1 + (rand() % 254);
            for (int j = 0; j < i; j++)
            {
                if (sembol == semboller[j])
                {
                    sembolBoolean = 0;
                    break;
                }
            }
            if (sembolsayac >= 255)
            {
                semboller[i] = sembol;
                colonies[i] = koloniOlustur(values[i], sembol);
                break;
            }
            if (sembolBoolean == 1) // secilen sembol diger sembollerle ayni degil
            {
                sembolsayac = 0;
                semboller[i] = sembol;
                colonies[i] = koloniOlustur(values[i], sembol); // create colony
            }

        } while (sembolBoolean == 0);
    }

    free(values);
    free(semboller);

    int turSayisi = 0;
    while (1) // Savas dongusu
    {
        turSayisi++;

        int savasabilirKoloniSayisi = 0;
        for (int i = 0; i < countOfColonies; i++)
        {
            if (colonies[i]->savasabilirMi != 0)
            {
                savasabilirKoloniSayisi++;
            }
        }
        if (savasabilirKoloniSayisi == 1)
            break;
        else
            savasabilirKoloniSayisi = 0;

        for (int i = 0; i < countOfColonies - 1; i++) // BATTLE
        {
            for (int j = i + 1; j < countOfColonies; j++)
            {
                if (colonies[i]->savasabilirMi == 0 || colonies[j]->savasabilirMi == 0)
                    continue;

                int aSavas = aTaktik->super->Savas();
                int bSavas = bTaktik->super->Savas();
                if (aSavas > bSavas) // lose second colony (colonies[j]) a->i, b->j
                {
                    this->SavasSonrasi(aSavas, bSavas, i, j, colonies);
                }
                else if (aSavas < bSavas) // lose first colony (colonies[i])
                {
                    this->SavasSonrasi(aSavas, bSavas, j, i, colonies);
                }
                else // aSavas == bSavas
                {
                    if (colonies[i]->populasyon > colonies[j]->populasyon)
                    {
                        this->SavasSonrasi(aSavas, bSavas, i, j, colonies);
                    }
                    else if (colonies[i]->populasyon < colonies[j]->populasyon)
                    {
                        this->SavasSonrasi(aSavas, bSavas, j, i, colonies);
                    }
                    else
                    {
                        int rnd = rand() % 2;
                        if (rnd == 0)
                        {
                           this->SavasSonrasi(aSavas, bSavas, i, j, colonies);
                        }
                        else
                        {
                            this->SavasSonrasi(aSavas, bSavas, j, i, colonies);
                        }
                    }
                }
                if (colonies[j]->populasyon <= 0 || colonies[j]->yemekStogu <= 0)
                {
                    colonies[j]->savasabilirMi = 0;
                }
                if (colonies[i]->populasyon <= 0 || colonies[i]->yemekStogu <= 0)
                {
                    colonies[i]->savasabilirMi = 0;
                }
            }
        }

        printf("-------------------------------------------------------------------------------------------------------\n");
        printf("Tur Sayisi: %d\n", turSayisi);
        printf("Koloni  Populasyon      Yemek Stogu     Kazanma  Kaybetme\n");
        for (int i = 0; i < countOfColonies; i++) // her turda yemek stogu ve populasyon guncelleme
        {
            if (i % 2 == 0)
            {
                colonies[i]->yemekStogu += aUretim->super->Uret();
            }
            else
            {
                colonies[i]->yemekStogu += bUretim->super->Uret();
            }

            colonies[i]->populasyon += ceil((colonies[i]->populasyon * 20) / 100.0);
            int artiYemek = ceil(colonies[i]->populasyon * 2.0);
            colonies[i]->yemekStogu -= artiYemek;

            if (colonies[i]->populasyon <= 0 || colonies[i]->yemekStogu <= 0)
            {
                colonies[i]->savasabilirMi = 0;
            }
            if (colonies[i]->savasabilirMi != 0) // savasabilir
                printf("%2c%11d%18d%13d%9d\n", colonies[i]->sembol, colonies[i]->populasyon, colonies[i]->yemekStogu, colonies[i]->kazanma, colonies[i]->kaybetme);
            else
            {
                printf("%2c%10c%c%17c%c%12c%c%8c%c\n", colonies[i]->sembol, '-', '-', '-', '-', '-', '-', '-', '-');
            }
        }
    }

    aTaktik->yoket(aTaktik);
    bTaktik->yoket(bTaktik);
    aUretim->yoket(aUretim);
    bUretim->yoket(bUretim);
    free(colonies);
}

void oyunYokEt(Oyun this)
{
    if (this == NULL)
        return;
    free(this);
}