#include <stdio.h>

void egg(int kasus){
  long long int likes = 0, prev = 1, prev2 = 0;
  int N;
  scanf("%d", &N);
  if(N == 2) likes = prev;

  for(int i = 1; i < N-1; ++i){
    likes = prev + prev2;
    prev2 = prev;
    prev = likes;
    // printf("%lld %lld %lld\n", prev2, prev, likes);
  }
  printf("Case #%d: %lld\n", kasus, likes);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    egg(i);
  }
}