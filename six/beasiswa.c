#include <stdio.h>

int is_eligible(float ipk, int pendapatan_ortu) {
  if(ipk >= 3.25 && pendapatan_ortu <= 4000000) {
    return 1;
  } else if (ipk >= 3.00 && pendapatan_ortu <= 2500000) {
    return 2;
  } else {
    return 0;
  }
}

int lolos_ke_jalur(int jumlah_prestasi) {
  return jumlah_prestasi >= 2? 1 : 2;
}

void cetak_info_hasil(int code) {
  switch (code){
  case 11:
    printf("Selamat anda lolos beasiswa jalur penuh!");
    break;
  case 12:
    printf("Selamat anda lolos beasiswa jalur reguler!");
    break;
  case 2:
    printf("Anda masuk daftar cadangan!");
    break;
  default:
    printf("Maaf anda tidak lolos beasiswa!");
    break;
  }
  printf("");
}

int main() {
  float ipk = 0;
  int jumlah_prestasi = 0, pendapatan_ortu = 0;

  int INTERNAL_ipk_INPCOUNTER = 0;

  while(ipk <= 0 || ipk > 4.0){
    if(INTERNAL_ipk_INPCOUNTER != 0){
      printf("Error: IPK harus dalam skala 0 - 4.00!\n");
    }

    printf("Masukan IPK anda (skala 0 - 4.00): ");
    scanf("%f", &ipk);
    INTERNAL_ipk_INPCOUNTER++;
  }
  printf("Masukkan jumlah prestasi: ");
  scanf("%d", &jumlah_prestasi);
  
  printf("Masukkan pendapatan orang tua: Rp.");
  scanf("%d", &pendapatan_ortu);
  
  switch (is_eligible(ipk, pendapatan_ortu)){
    case 1:
      int jalur = lolos_ke_jalur(jumlah_prestasi);
      cetak_info_hasil(jalur == 1? 11: 12);
      break;
    case 2:
      cetak_info_hasil(2);
      break;
    default:
      cetak_info_hasil(0);
      break;
  }

  return 0;
}
