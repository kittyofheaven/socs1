#include <stdio.h>

int main(){
  long long A,B;
  scanf("%lld %lld", &A, &B);

  long long N = B - A + 1;
  long long result = N / 2.0 * (2*A + (N-1));  

  printf("%lld\n", result);

  
  return 0;
}