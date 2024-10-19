#include <stdio.h>
#include <math.h>

int main(){
  double L,B,H;

  scanf("%lf %lf %lf", &L, &B, &H);

  double luas_segitiga = H * B / 2.0;
  double luas_persegi = L*B;

  double luas_minimum_prisma =  luas_segitiga*2 + luas_persegi*3;

  printf("%.3lf\n", luas_minimum_prisma);
}