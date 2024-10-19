#include <stdio.h>

int main(){
  int N;
  scanf("%d", &N);
  int matriks[N][N];
  int colFlag[N][101];
  int rowFlag[N][101];
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < 101; ++j){
      colFlag[i][j] = 0;
      rowFlag[i][j] = 0;
    }
  }

  char isValid =1;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      scanf("%d", &matriks[i][j]);

      if(colFlag[j][matriks[i][j]]) isValid = 0;
      else colFlag[j][matriks[i][j]] = 1;

      if(rowFlag[i][matriks[i][j]]) isValid = 0;
      else rowFlag[i][matriks[i][j]] = 1;
    }
  }

  isValid ? printf("Yay\n") : printf("Nay\n");
}