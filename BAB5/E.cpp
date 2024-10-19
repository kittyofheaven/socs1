#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);

  for(int kasus = 1; kasus <= T; ++kasus){
    int X;
    scanf("%d", &X);

    long long matrix[X][X];
    for(int i = 0; i < X; ++i){
      for(int j = 0; j < X; ++j){
        matrix[i][j] = 0;
      }
    }

    for(int i = 0; i < X; ++i){
      for(int j = 0; j < X; ++j){
        scanf("%lld" ,&matrix[i][j]);
      }
    }

    long long sum[X];
    for(int i = 0; i < X; ++i){
      sum[i] = 0;
    }

    for(int i = 0; i < X; ++i){
      for(int j = 0; j < X; ++j){
        sum[i] += matrix[j][i];
      }
    }

    printf("Case #%d: ", kasus);
    for(int i = 0; i < X; ++i){
      printf("%lld", sum[i]);
      if(i != X-1){
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}