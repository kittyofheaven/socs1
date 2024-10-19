#include <stdio.h>
#include <math.h>

int main(){
  int X;
  double Y;

  scanf("%d %lf", &X, &Y);

  double hasil = X * 1.0 * pow((1 + (Y/100)), 3);

  printf("%.2lf\n", hasil);
  return 0;
}