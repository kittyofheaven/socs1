#include <stdio.h>
#include <string.h>

void matrixCalculation(int kasus){
  int N;
  scanf("%d", &N); getchar();

  int matriks1[N][N]; // i = baris, j = kolom
  int matriks2[N][N];
  int matriks3[N][N]; 
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      scanf("%d", &matriks1[i][j]); getchar();
    }
  }

  getchar();
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      scanf("%d", &matriks2[i][j]); getchar();
    }
  }

  getchar();
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      scanf("%d", &matriks3[i][j]); getchar();
    }
  }

  int matriksHasil1[N][N];
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      matriksHasil1[i][j] = 0;
      for(int k = 0; k < N; ++k){
        matriksHasil1[i][j] += matriks1[i][k] * matriks2[k][j];
      }
    }
  }

  int matriksHasil2[N][N];
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      matriksHasil2[i][j] = 0;
      for(int k = 0; k < N; ++k){
        matriksHasil2[i][j] += matriksHasil1[i][k] * matriks3[k][j];
      }
    }
  }

  printf("Case #%d:\n", kasus);
  for(int i = 0; i < N; ++i){
    for(int j = 0; j< N; ++j){
      printf("%d", matriksHasil2[i][j]);
      if(j < N-1) printf(" ");
    }
    printf("\n");
  }
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    matrixCalculation(i);
  }
  return 0;
}