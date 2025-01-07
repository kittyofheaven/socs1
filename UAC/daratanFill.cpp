#include <stdio.h>

void daratanFill(char arr[51][51], int X, int Y, int maxX, int maxY, int *count){
  
  if(arr[X][Y] == '.' || arr[X][Y] == 'X') {
    return;
  }
  int arrH = arr[X][Y] - '0';

  if(X >= 0 && X < maxX && Y>=0 && Y < maxY){
    arr[X][Y] = 'X';
    (*count)++;
    daratanFill(arr, X-1, Y, maxX, maxY, count);
    daratanFill(arr, X+1, Y, maxX, maxY, count);
    daratanFill(arr, X, Y-1, maxX, maxY, count);
    daratanFill(arr, X, Y+1, maxX, maxY, count);
  }

  return;
}

void banjirFill(char arr[51][51], int X, int Y, int maxX, int maxY, int height){
  
  if(arr[X][Y] == 'E' || arr[X][Y] == '.') {
    return;
  }
  int arrH = arr[X][Y] - '0';
  // printf("%d\n", height);
  if(arrH > height){
    return;
  }

  if(X >= 0 && X < maxX && Y>=0 && Y < maxY){
    arr[X][Y] = '.';
    banjirFill(arr, X-1, Y, maxX, maxY, height);
    banjirFill(arr, X+1, Y, maxX, maxY, height);
    banjirFill(arr, X, Y-1, maxX, maxY, height);
    banjirFill(arr, X, Y+1, maxX, maxY, height);
  }

  return;
}

int main(){
  int N, M;
  scanf("%d %d", &N, &M); getchar();

  char arr[51][51];
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      scanf("%c", &arr[i][j]); getchar();
    }
  }

  int X, Y; //asal banjir;
  scanf("%d %d", &X, &Y); getchar();
  banjirFill(arr, X, Y, N, M, arr[X][Y] - '0');

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      printf("%c ", arr[i][j]);
    }
    printf("\n");
  }

  int daratCount = 0;
  int maxDarat = 0;
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      if(arr[i][j] == 'E'){
        daratCount = 0;
        daratanFill(arr, i, j, N, M, &daratCount);
        printf("darat : %d\n", daratCount);
        if(maxDarat < daratCount) maxDarat = daratCount;
      }
    }
  }

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      printf("%c ", arr[i][j]);
    }
    printf("\n");
  }

  printf("Max daratan : %d\n", maxDarat);
}