#include <stdio.h>

int main(){
  long long A,B;
  scanf("%lld %lld", &A, &B);

  long long result = 0;

  for(int i = A ; i <= B ; ++i){
    result +=i;
  }

  printf("%lld\n", result);

  
  return 0;
}