#include <stdio.h>

int main(void) {
  char nama_mhs[100];
  printf("Sistem Rekap Nilai Mahasiswa\n");
  printf("Masukkan Nama Mahasiswa: ");
  scanf("%99[^\n]", nama_mhs);

  float total_nilai_berbobot = 0;
  float total_bobot = 0;
  int jumlah_komponen = 0;
  char lanjut_tambah_komp = 'y';

  while (lanjut_tambah_komp == 'y' || lanjut_tambah_komp == 'Y') {
    char nama_komponen[100];
    int nilai;
    int bobot;

    printf("\nMasukkan Detail Komponen\n");
    printf("Nama Komponen: ");
    scanf(" %99[^\n]", nama_komponen);

    printf("Nilai (0-100): ");
    scanf("%d", &nilai);
    
    while (nilai < 0 || nilai > 100) {
      printf("Nilai harus berada pada rentang 0-100.\n");
      printf("Nilai: ");
      scanf("%d", &nilai);
    }

    printf("Bobot (lebih dari 0): ");
    scanf("%d", &bobot);
    while (bobot <= 0) {
      printf("Bobot harus lebih dari 0.\n");
      printf("Bobot: ");
      scanf("%d", &bobot);
    }

    total_nilai_berbobot += (float)nilai * bobot;
    total_bobot += bobot;
    jumlah_komponen++;

    printf("Tambah komponen lagi [y/N]: ");
    scanf(" %c", &lanjut_tambah_komp);
    if (lanjut_tambah_komp != 'y' && lanjut_tambah_komp != 'Y' &&
        lanjut_tambah_komp != 'n' && lanjut_tambah_komp != 'N') {
      lanjut_tambah_komp = 'n';
    }
  }

  float nilai_akhir = total_nilai_berbobot / total_bobot;
  char predikat;
  if (nilai_akhir >= 80) {
    predikat = 'A';
  } else if (nilai_akhir >= 60) {
    predikat = 'B';
  } else {
    predikat = 'C';
  }

  int persentase_kehadiran;
  printf("Persentase Kehadiran (0-100): ");
  scanf("%d", &persentase_kehadiran);
  while (persentase_kehadiran < 0 || persentase_kehadiran > 100) {
    printf("Persentase kehadiran harus berada pada rentang 0-100.\n");
    printf("Persentase Kehadiran: ");
    scanf("%d", &persentase_kehadiran);
  }

  char *status_kelulusan =
      (predikat == 'A' || predikat == 'B') && persentase_kehadiran > 75
          ? "Lulus"
          : "Tidak lulus";

  printf("\nHasil Rekap Mahasiswa atas nama %s\n", nama_mhs);
  printf("Jumlah Komponen: %d\n", jumlah_komponen);
  printf("Total Bobot: %.0f\n", total_bobot);
  printf("Nilai Akhir: %.2f\n", nilai_akhir);
  printf("Predikat: %c\n", predikat);
  printf("Status Kelulusan: %s\n", status_kelulusan);

  return 0;
}
