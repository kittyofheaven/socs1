#include <stdio.h>

int main(){
  long long a,b,c,d;

  scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

  (a*b) == (c-d) ? printf("True\n") : printf("False\n");

  return 0;
}