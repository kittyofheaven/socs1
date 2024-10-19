#include <stdio.h>

int main(){
  long long int number, bitKeberapa;
  scanf("%lld %lld", &number, &bitKeberapa);
  printf("%lld\n",((number>>(bitKeberapa - 1)) & 1));
}