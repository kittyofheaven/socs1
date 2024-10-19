#include <stdio.h>

int main(){
  long long N;
  scanf("%lld", &N);

  long long result = 0;
  for(long long i = 1 ; i <= N ; i++){
    long long input;
    scanf("%lld", &input);
    result = input > 0 ? result + input : result;
  }

  printf("%lld\n", result);
  return 0;
}