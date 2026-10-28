#include <stdio.h>

int celcius_to_fahrenheit(int temp_celcius) {
  return temp_celcius * 9/5 + 32;
}

int main (void) {
  int temp_in_c;

  printf("Masukan suhu dalam celcius : ");
  scanf("%d", &temp_in_c);

  int temp_in_f = celcius_to_fahrenheit(temp_in_c);

  printf("Suhu dalam fahrenheit adalah %d F", temp_in_f);

  return 0;
}
