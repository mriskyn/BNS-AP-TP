#include <stdio.h>
#include <stdlib.h>

void clearscr(void)
{
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "OS not supported."
#endif
}

int validateType(int scanfReturnValue) {
  if (scanfReturnValue == 0) {
    printf("Input harus angka\n");
    return 1;
  }

  return 0;
}

int main() {
    clearscr();
    // Deklarasi variabel jumlah mahasiswa
    int jumlahMahasiswa;

    printf("===== PERHITUNGAN NILAI MAHASISWA =====");

    // Error check tipe data
    printf("Masukkan jumlah mahasiswa: ");
    if (validateType(scanf("%d", &jumlahMahasiswa))){
      return 0;
    } 
    else if (jumlahMahasiswa < 10) {
        printf("Minimal input 10 mahasiswa\n");
        return 0;
    }

    // Deklarasi variabel untuk rata-rata nilai
    double totalNilai = 0.0;
    int jumlahTidakLulus = 0;

    for (int i = 1; i <= jumlahMahasiswa; i++) {
        printf("\nData Mahasiswa ke-%d\n", i);

        // Deklarasi variabel nilai
        double nilaiQuiz, nilaiTugas, nilaiAbsensi, nilaiPraktek, nilaiUAS;

        /* INPUT */
        // Input nilai quis
        printf("\tNilai Quiz\t: ");
        if (validateType(scanf("%lf", &nilaiQuiz))){ // Error check tipe data
            return 0;
        } else if (nilaiQuiz < 0) { // Error check angka kurang dari nol
            printf("Angka harus lebih dari atau sama dengan 0\n");
            return 0;
        }

        // Input nilai tugas
        printf("\tNilai Tugas\t: ");
        if (validateType(scanf("%lf", &nilaiTugas))){ // Error check tipe data
          return 0;
        } else if (nilaiTugas < 0) { // Error check angka kurang dari nol
            printf("Angka harus lebih dari atau sama dengan 0\n");
            return 0;
        }

        // Input nilai
        printf("\tNilai Absensi\t: ");
        if (validateType(scanf("%lf", &nilaiAbsensi))){ // Error check tipe data
          return 0;
        } else if (nilaiAbsensi < 0) { // Error check angka kurang dari nol
            printf("Angka harus lebih dari atau sama dengan 0\n");
            return 0;
        }


        // Input nilai praktek
        printf("\tNilai Praktek\t: ");
        if (validateType(scanf("%lf", &nilaiPraktek))){ // Error check tipe data
          return 0;
        } else if (nilaiPraktek < 0) { // Error check angka kurang dari nol
            printf("Angka harus lebih dari atau sama dengan 0\n");
            return 0;
        }

        // Input nilai UAS
        printf("\tNilai UAS\t: ");
        if (validateType(scanf("%lf", &nilaiUAS))){ // Error check tipe data
          return 0;
        } else if (nilaiUAS < 0) { // Error check angka kurang dari nol
            printf("Angka harus lebih dari atau sama dengan 0\n");
            return 0;
        }

        // Menghitung nilai akhir
        double nilaiAkhir = (nilaiQuiz + nilaiTugas + nilaiAbsensi + nilaiPraktek + nilaiUAS) / 5;

        // Menghitung rata-rata nilai
        totalNilai += nilaiAkhir;

        // Menentukan grade
        char grade;
        if (nilaiAkhir <= 55) {
            grade = 'E';
            jumlahTidakLulus++;
        } else if (nilaiAkhir <= 65) {
            grade = 'D';
            jumlahTidakLulus++;
        } else if (nilaiAkhir <= 75) {
            grade = 'C';
        } else if (nilaiAkhir <= 85) {
            grade = 'B';
        } else {
            grade = 'A';
        }

        // Menampilkan hasil untuk setiap mahasiswa
        printf("\tNilai Akhir: %.2lf\n", nilaiAkhir);
        printf("\tGrade: %c\n", grade);
    }

    // Menghitung rata-rata nilai
    double rataRata = totalNilai / jumlahMahasiswa;

    /* OUTPUT */
    // Menampilkan rata-rata nilai
    printf("\nRata-rata nilai seluruh mahasiswa: %.2lf\n", rataRata);

    // Menampilkan pesan jika ada mahasiswa yang tidak lulus
    if (jumlahTidakLulus > 0) {
        printf("Terdapat %d mahasiswa yang tidak lulus.\n", jumlahTidakLulus);
    } else {
        printf("Semua mahasiswa lulus!\n");
    }

    return 0;
}
