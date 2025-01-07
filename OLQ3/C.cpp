#include <stdio.h>

int main(){
  long long N;
  scanf("%lld", &N);
  ((N & 1) == 1) ? printf("%lld = %lld + %lld\n", N, N/2, N/2 +1) : printf("%lld = %lld + %lld\n", N, N/2, N/2);
  return 0;
}