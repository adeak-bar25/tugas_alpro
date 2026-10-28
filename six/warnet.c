#include <stdio.h>
#include <math.h>

void splash() {
  printf("========================================================\n");
  printf("       Halo, Selamat datang di Warnet Klik Cepat        \n");
  printf("========================================================\n");
}

int hitung_jumlah_blok(int total_menit, int menit_per_blok) {
  int total = ceil((float) total_menit / menit_per_blok);

  if(total < 2) total = 2;

  return total;
}

int hitung_biaya_sewa(int jumlah_blok, int biaya_sewa){
  return jumlah_blok * biaya_sewa;
}

int hitung_diskon(int jumlah_total, int persentase_diskon) {
  return (jumlah_total * persentase_diskon) / 100;
}

int hitung_total_dengan_potongan(int total, int potongan) {
  return total - potongan;
}

void cetak_hasil(int total_blok, int total_biaya_sewa_sebelum_potongan, int persentase_potongan, int total_potongan, int total_final) {
  printf("========================================================\n");
  printf("Total Blok = %d \n", total_blok);
  printf("Total biaya sewa sebelum potongan = Rp. %d \n", total_biaya_sewa_sebelum_potongan);
  printf("Total Potongan = Rp. %d (%d%%) \n", total_potongan, persentase_potongan);
  printf("Total yang harus dibayar = Rp. %d \n", total_final);
  printf("========================================================\n");
}

int main(void){
  splash();
  int total_menit_sewa = 0;
  char punya_member = '-';

  printf("Masukan jumlah menit sewa komputer : ");
  scanf("%d", &total_menit_sewa);
  
  while (punya_member != 'y' && punya_member != 'n')
  {
    printf("Apakah anda punya member, tekan y jika ya, jika tidak tekan n [y|n]: ");
    scanf(" %c", &punya_member);
  }
  
  int total_blok = hitung_jumlah_blok(total_menit_sewa, 15);
  int total_biaya_sewa_sebelum_potongan =  hitung_biaya_sewa(total_blok, 1500);
  int potongan_persen = punya_member == 'y'? 10 : 0;
  int total_potongan = hitung_diskon(total_biaya_sewa_sebelum_potongan, potongan_persen);
  int total_biaya_sewa_setelah_potongan = hitung_total_dengan_potongan(total_biaya_sewa_sebelum_potongan, total_potongan);

  cetak_hasil(total_blok, total_biaya_sewa_sebelum_potongan, potongan_persen, total_potongan, total_biaya_sewa_setelah_potongan);
  return 0;
}
