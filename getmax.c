#include <stdio.h>

int get_max(int x, int y, int z) {
  int max = x;

  if (max < y){
    max = y;
  }
  if (max < z){
    max = z;
  }

  return max;
}

int main() {
  int x, y, z;
  printf("Masukan nilai pertama: ");
  scanf("%d", &x);
  printf("Masukan nilai kedua: ");
  scanf("%d", &y);
  printf("Masukan nilai ketiga: ");
  scanf("%d", &z);

  int max = get_max(x, y, z);

  printf("Nilai tertinggi adalah: %d", max);

  return 0;
}
