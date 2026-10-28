#include <stdio.h>

void splash() {
  printf("===========================================================================\n");
  printf("            <=+ Halo, Selamat datang di Koperasi Sejahtera +=>             \n");
  printf("===========================================================================\n\n");
  printf("Simulasikan perkembangan saldo anda di Koperasi Sejahtera! \n");
  printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n\n");
}

int hitung_bunga_perbulan(int total_saldo, int persentase_bunga) {
  return (total_saldo * persentase_bunga) / 100;
}

int tambah_saldo(int total_saldo, int jumlah_setoran) {
  return total_saldo + jumlah_setoran;
}

void cetak_saldo_perbulan(int n_bulan, int total_saldo_final, int bunga){
  printf("Saldo bulan ke %d adalah Rp.%d (bunga: Rp. %d) \n", n_bulan, total_saldo_final, bunga);
}

int main(void)
{
  splash();
  int saldo_awal, total_bulan, setoran_perbulan;
  
  // Ambil input
  printf("Masukkan saldo awal anda: ");
  scanf(" %d", &saldo_awal);
  
  printf("Masukkan jangka tabungan anda dalam bulan: ");
  scanf(" %d", &total_bulan);

  printf("Masukkan jumlah setoran perbulan anda dalam jangka %d bulan : ", total_bulan);
  scanf(" %d", &setoran_perbulan);

  int totalSaldo = saldo_awal;

  for(int bulan_n = 1; bulan_n <= total_bulan; bulan_n++ ){
    if(bulan_n  != 1) {
      totalSaldo = tambah_saldo(totalSaldo, setoran_perbulan);
    }

    int bunga = hitung_bunga_perbulan(totalSaldo, 1);
    totalSaldo = tambah_saldo(totalSaldo, bunga);

    cetak_saldo_perbulan(bulan_n, totalSaldo, bunga);

  }
  

  return 0;
}
