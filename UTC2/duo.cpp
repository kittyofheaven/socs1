#include <stdio.h>
void Duo(int kasus){
  int N;
  scanf("%d", &N);

  long long setCount = 0;
  long long prevX = 0;

  for(int i = 0; i < N; ++i){
    long long x;
    scanf("%lld", &x);
    // printf("x: %lld %lld\n", prevX, x);
    if(x == prevX){
      setCount ++;
      prevX = 0;
    } else {
      prevX = x;
    }
  }

  printf("Case #%d: %lld\n", kasus, setCount);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    Duo(i);
  }
  return 0;
}