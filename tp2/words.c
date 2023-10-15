#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearScreen()
{
#ifdef _WIN32
  system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || \
    (defined(__APPLE__) && defined(__MACH__))
  system("clear");
#else
#error "OS not supported."
#endif
}

int isVowel(char c)
{
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main()
{
  clearScreen();
  char input;
  char *months[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

  printf("======================================\n");
  printf("======= SEARCH VOWEL OF MONTHS =======\n");
  printf("======================================\n\n");

  while (1)
  {
    printf("\nMenu:\n");
    printf("1. Cari bulan dengan awalan huruf (A-Z)\n");
    printf("2. Keluar\n");
    printf("Pilihan: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
      printf("Masukkan huruf awal bulan (A-Z): ");
      scanf(" %c", &input);

      if (input < 'A' || input > 'Z')
      {
        printf("Input tidak valid. Masukkan huruf antara A-Z.\n");
        continue;
      }

      printf("Bulan-bulan yang awalannya '%c':\n", input);
      int i;
      int found = 0;

      for (i = 0; i < 12; i++)
      {
        if (months[i][0] == input)
        {
          printf("%s\n", months[i]);
          found = 1;
        }
      }

      if (!found)
      {
        printf("Tidak ada bulan yang awalannya '%c'.\n", input);
      }
      else
      {
        printf("Pilih bulan yang ingin Anda hitung (1-12): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 12)
        {
          printf("Input tidak valid. Masukkan angka antara 1-12.\n");
          continue;
        }

        choice--; // Adjust for 0-based indexing

        int vowelCount = 0;
        int nonVowelCount = 0;

        for (i = 0; i < strlen(months[choice]); i++)
        {
          if (isVowel(months[choice][i]))
            vowelCount++;
          else if (months[choice][i] != ' ')
            nonVowelCount++;
        }

        printf("Jumlah karakter vokal dalam '%s': %d\n", months[choice], vowelCount);
        printf("Jumlah karakter nonvokal dalam '%s': %d\n", months[choice], nonVowelCount);
      }
    }
    else if (choice == 2)
    {
      printf("Terima kasih, program selesai.\n");
      break;
    }
    else
    {
      printf("\nPilihan tidak valid. Masukkan 1 atau 2.\n");
    }
  }

  return 0;
}
