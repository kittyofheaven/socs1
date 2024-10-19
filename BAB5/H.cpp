#include <stdio.h>

void allTheWind(int kasus){
  int N;
  scanf("%d", &N);

  long long map[N][N];
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      scanf("%lld", &map[i][j]);
    }
  }

  long long sum[N];

  for(int i = 0; i < N; ++i){
    sum[i] = 0;
    for(int j = 0; j < N; ++j){
      sum[i] += map[j][i];
    }
  }

  printf("Case #%d:", kasus);
  for(int i = 0; i < N; ++i){
    printf(" %lld", sum[i]);
  }
  printf("\n");

}

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    allTheWind(i);
  }

}