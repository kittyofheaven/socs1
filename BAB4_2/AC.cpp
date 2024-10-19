#include <stdio.h>

void candy(int kasus){
  long long int N, M, temp, min = 1000001;
  scanf("%lld %lld", &N, &M);

  for(int i = 0; i < N; ++i){
    scanf("%lld", &temp);
    if(temp < min) min = temp;
  }

  printf("Case #%d: %lld\n", kasus, M/min);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    candy(i);
  }
}