#include <stdio.h>
void colSum(int kasus){
  int N;
  scanf("%d", &N); getchar();

  int matrices[N][N]; 

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      scanf("%d", &matrices[i][j]);
    }
  }

  long long sum[N];
  for(int i = 0; i < N; ++i){
    sum[i] = 0;
    for(int j = 0; j < N; ++j){
      sum[i] += matrices[j][i];
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
  scanf("%d", &T); getchar();
  for(int i = 1; i <= T; ++i){
    colSum(i);
  }
  return 0;
}