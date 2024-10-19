#include <stdio.h>

int main(){
  double N[4], P[4];

  for (int i = 0; i < 4; ++i)
  {
    scanf("%lf %lf", &N[i], &P[i]);
  }

  for (int i = 0; i < 4; ++i)
  {
    printf("$%.2lf\n", P[i] / (100-N[i]) * 100);
  }

  return 0;
}