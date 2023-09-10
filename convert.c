#include <stdio.h>

int main() {
    double jarakKm;
    double jarakM;
    double jarakCm;
    
    printf("____________________________________________\n");
    printf("|      =-=-=-= KONVERTER KM =-=-=-=        |\n");
    printf("|                                          |\n");
    printf("|                                          |\n");
    printf("| Masukkan jarak dalam kilometer (km):");
    scanf("%lf", &jarakKm);
    
    jarakM = jarakKm * 1000;
    jarakCm = jarakKm * 100000;
    
    printf("|                                          |\n");
    printf("|                                          |\n");
    printf("| Hasil konversi ke meter (m): %.2lf\n", jarakM);
    
    printf("| Hasil konversi ke sentimeter (cm): %.2lf\n", jarakCm);

    printf("|                                          |\n");
    printf("| =-=-=-=                          =-=-=-= |\n");
    printf("|                                          |\n");
    printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");

    
    return 0;
}
