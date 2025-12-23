#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int not;
    long long numara;
}Ogrenci;

int main() {
    FILE *dosya;
    Ogrenci ogr;
    int frekans [101]={0};
    int modNot=-1;
    int maxSiklik=0;


    /*Kullanıcı kendi ogrenci.dat dosyasını çalıştıracaksa cmake-build-debug
    dosyasındaki dosya yerine kendi ogrenci.dat dosyasını koymalı
    ogrenci.dat dosyası formatı "ogrencino numara\n" şeklinde olmalıdır*/

    dosya=fopen("ogrenci.dat","r");
    if (dosya==NULL) {
        printf("Kullanici adi bulunamadi\n");
        return 1;
    }

    //Frekans hesaplama
    while (fscanf(dosya,"%lld %d", &ogr.numara, &ogr.not)!=EOF) {
        if (ogr.not>=0 && ogr.not<=100) {
            frekans[ogr.not]++;
        }
    }

    //Modu bulma
    for (int i=0;i<101;i++) {
        if (frekans[i]>maxSiklik) {
            maxSiklik=frekans[i];
            modNot=i;
        }
    }

    //Ekrana yazdırma
    if (modNot!=-1 && maxSiklik>0) {
        printf("Sonuclar:\nYigilma olan not: %d (%d ogrenci\n", modNot, maxSiklik);
        printf("---------------------\n");

        rewind (dosya); //Dosyayı başa sarma
        while (fscanf(dosya,"%lld %d", &ogr.numara, &ogr.not)!=EOF) {
            if (ogr.not==modNot) {
                printf("%lld\t%d\n",ogr.numara, ogr.not);
            }
        }

    }
    fclose(dosya);
    return 0;
}