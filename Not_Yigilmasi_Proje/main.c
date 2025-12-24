#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// YAPILAR
typedef struct {
    int not;
    long long numara;
} Ogrenci;

//  FONKSİYON PROTOTİPLERİ
void veriOlustur();
void analizYap();

// MAİN
int main() {

    printf("Veri Uretiliyor\n");
    veriOlustur();

    printf("\n"); // Boşluk bırak

    // Oluşan veriyi analiz et
    printf("Analiz Basliyor\n");
    analizYap();

}

//  VERİ OLUŞTURMA FONKSİYONU
void veriOlustur() {
    FILE *dosya;
    dosya = fopen("ogrenci.dat", "w"); // "w" modu dosyayı sıfırdan yaratır

    if (dosya == NULL) {
        perror("Dosya olusturulamadi");
        exit(1);
    }

    int notlar;
    int ogrenciSayisi = 100;

    srand(time(NULL)); // Rastgelelik çekirdeği

    for (int i = 0; i < ogrenciSayisi; i++) {
        long long numara = 1000000000 + rand() % 9000000000;
        notlar = rand() % 101;
        fprintf(dosya, "%lld %d\n", numara, notlar);
    }

    fclose(dosya);
    printf(">> 'ogrenci.dat' dosyasi %d ogrenci icin basariyla olusturuldu.\n", ogrenciSayisi);
}

//  ANALİZ FONKSİYONU
void analizYap() {
    FILE *dosya;
    Ogrenci ogr;
    int frekans[101] = {0};
    int maxSiklik = 0;

    // Dosyayı okumak için açıyoruz
    dosya = fopen("ogrenci.dat", "r");

    if (dosya == NULL) {
        printf("Hata: ogrenci.dat dosyasi bulunamadi!\n");
        return;
    }

    // Frekans Hesaplama
    while (fscanf(dosya, "%lld %d", &ogr.numara, &ogr.not) != EOF) {
        if (ogr.not >= 0 && ogr.not <= 100) {
            frekans[ogr.not]++;
        }
    }

    // Max Sıklığı Bulma
    for (int i = 0; i < 101; i++) {
        if (frekans[i] > maxSiklik) {
            maxSiklik = frekans[i];
        }
    }

    // Sonuçları Yazdırma
    if (maxSiklik > 0) {
        printf(" Analiz Sonuclari:\n");
        printf("Yigillma frekansi (Tekrar Sayisi): %d\n", maxSiklik);

        // Mod olan notları ekrana bas
        printf("Yigilma olan notlar: ");
        for(int i=0; i<101; i++){
            if(frekans[i] == maxSiklik){
                printf("%d ", i);
            }
        }
        printf("\n---------------------\n");

        // Mod notunu alan öğrencileri listeleme
        rewind(dosya); // Dosyayı başa sar
        printf("Bu notu alan ogrenciler:\n");

        while (fscanf(dosya, "%lld %d", &ogr.numara, &ogr.not) != EOF) {
            if (frekans[ogr.not] == maxSiklik) {
                printf("%lld\t%d\n", ogr.numara, ogr.not);
            }
        }
    }

    fclose(dosya);
}