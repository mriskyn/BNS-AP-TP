#include <stdio.h>
#include <string.h>

void reset() {
  printf("\033[0m");
}

void red(char string[]) {
  printf("\033[0;31m");
  printf("%s",string);
  reset();
}

void green(char string[]) {
  printf("\033[0;32m");
  printf("%s",string);
  reset();
}

void yellow(char string[]) {
  printf("\033[0;33m");
  printf("%s",string);
  reset();
}

void blue(char string[]) {
  printf("\033[0;34m");
  printf("%s",string);
  reset();
}

void purple(char string[]) {
  printf("\033[0;35m");
  printf("%s",string);
  reset();
}

void cyan(char string[]) {
  printf("\033[0;36m");
  printf("%s",string);
  reset();
}


void input(float *inputBelanja) {
    printf("Masukkan total belanja Anda                     : Rp ");
    scanf("%f", inputBelanja);
}

void process(float totalBelanja, float *hargaYangHarusDibayar, int jumlahTransaksi) {
    float diskon = 0.0;
    if (totalBelanja < 200000) {
        diskon = 0.0;
    } else if (totalBelanja >= 200000 && totalBelanja <= 500000) {
        diskon = 0.1;
    } else if (totalBelanja > 500000 && totalBelanja <= 1000000) {
        diskon = 0.2;
    } else if (totalBelanja > 1000000) {
        diskon = 0.3;
    }

    float diskonNominal = totalBelanja * diskon; 
    *hargaYangHarusDibayar = totalBelanja - diskonNominal;

    if (jumlahTransaksi >= 4) {
        diskon = 0.2;
        diskonNominal = *hargaYangHarusDibayar * diskon;

        *hargaYangHarusDibayar -= diskonNominal;
    }
}

void output(float hargaYangHarusDibayar) {
    green("\n----------------------------------");
    printf("\nHarga yang harus dibayar setelah diskon: %.2f\n", hargaYangHarusDibayar);
    green("----------------------------------\n");
}

int main() {
    float inputBelanja, totalBelanja, hargaYangHarusDibayar;
    int jumlahTransaksi = 0;

    green("----------------------------------\n");
    cyan("=+=+"), yellow(" MENGHITUNG TOTAL BELANJA ") ,cyan("+=+=\n");
    green("----------------------------------\n\n");

    while(1){
        char lanjut[6];
        jumlahTransaksi += 1;
        
        input(&inputBelanja);
        totalBelanja += inputBelanja;

        printf("Apakah ingin melanjutkan transaksi? (ya/tidak)  : ");
        scanf("%s", lanjut);


        if (strcmp(lanjut, "tidak") == 0){
            break;
        } else if (strcmp(lanjut, "ya") == 0){
            continue;
        } else {
            printf("===== ERROR =====\n");
            printf("Input salah");
            return 0;
        }
    }

    process(totalBelanja, &hargaYangHarusDibayar, jumlahTransaksi);
    
    output(hargaYangHarusDibayar);
    return 0;
}
