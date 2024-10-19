#include <stdio.h>
#include <math.h>

int main(){
  int a,b,t;
  scanf("%d %d %d", &a, &b, &t);
  double result;
  result = (sqrt((a*t)*(a*t) + (b*t)*(b*t))) / t;
  printf("%.3lfm/s\n", result);
}