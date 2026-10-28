#include <stdio.h>

int hitung_ongkir(int jarak) {
  if(jarak <= 5) {
    return 10000;
  } else if(jarak > 15) {
    return 300000;
  } else {
    return jarak * 2000;
  }
}

int main() {
  int jarak;
  
  printf("Masukkan jarak : ");
  scanf("%d", &jarak);

  int ongkir = hitung_ongkir(jarak);
  printf("Jumlah ongkir adalah %d", ongkir);
  
  return 0;
}