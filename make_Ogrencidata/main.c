#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    FILE *dosya;
    dosya=fopen("ogrenci.dat","w");
    if (dosya==NULL) {
        perror("Dosya olusturulamadi");
        return 1;
    }
    int notlar;
    int ogrenciSayisi = 100;

    srand(time(NULL));
    for (int i=0;i<ogrenciSayisi;i++) {
        long long numara = 1000000000 +rand()%9000000000;
        notlar = rand() % 101;
        fprintf(dosya,"%lld %d\n",numara, notlar);
    }
    fclose(dosya);
    printf("ogrenci.dat dosyasi 100 ogrenci icin olusturuldu.\n");
    

    return 0;
}