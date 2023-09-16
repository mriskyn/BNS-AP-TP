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

float checkDiscount(int jamMain)
{
  if (jamMain > 10)
  {
    return 0.20;
  }
  if (jamMain > 8)
  {
    return 0.20;
  }
  if (jamMain > 6)
  {
    return 0.15;
  }
  if (jamMain > 4)
  {
    return 0.10;
  }
}

int main()
{
  clearscr();
  // Deklarasi Variabel
  int jamMain;
  float hargaPerJam = 10000.0;
  float diskon = 0.0;
  float totalHarga;

  // Input
  printf("Masukkan jumlah jam main: ");
  scanf("%d", &jamMain);

  // Proses
  diskon = checkDiscount(jamMain);
  totalHarga = (1.0 - diskon) * jamMain * hargaPerJam;

  // Output
  printf("Total harga yang harus dibayarkan: Rp %.2f\n", totalHarga);

  return 0;
}