#include <stdio.h>

int main(){
  int X, Y;
  scanf("%d %d", &X, &Y);
  int matrix[X][Y];

  for(int i = 0; i < X; ++i){
    for(int j = 0; j < Y; ++j){
      scanf("%d", &matrix[i][j]);
    }
  }

  int T;
  scanf("%d", &T);
  for(int i = 0; i < T; ++i){
    int tempI, tempJ, value;
    scanf("%d %d %d", &tempI, &tempJ, &value);
    matrix[tempI-1][tempJ-1] = value;
  }

  for(int i = 0; i < X; ++i){
    for(int j = 0; j < Y; ++j){
      printf("%d", matrix[i][j]);
      if(j != Y-1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}