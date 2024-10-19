#include <stdio.h>

long long int joRec(long long int N, long long int a, long long int b){
  if(N == 0){
    return a;
  } else if(N == 1){
    return b;
  } else return joRec(N-1,a , b) - joRec(N-2, a , b);
}

void jojonaci(int kasus){
  long long int N, a, b, result;
  scanf("%lld %lld %lld", &N, &a, &b);
  result = joRec(N, a, b);
  printf("Case #%d: %lld\n", kasus, result);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    jojonaci(i);
  }
}