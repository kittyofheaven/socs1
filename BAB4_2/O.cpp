#include <stdio.h>

void stayOrSwap(int kasus){
  int N, K, M;
  scanf("%d %d %d", &N, &M, &K);
  int temp;
  for(int i = 0; i < N; ++i){
    scanf("%d", &temp);
    if(temp > K && temp <=M){
      K = temp;
    }
  }
  printf("Case #%d: %d\n", kasus, K);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    stayOrSwap(i);
  }
}