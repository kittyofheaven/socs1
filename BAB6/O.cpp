#include <stdio.h>

void rec(char map[101][101], int N, int M, int x, int y, int *food){
  if (x < 0 || x >= M || y < 0 || y >= N || map[y][x] == '#') return;

  if(map[y][x] == '*'){
    (*food)++;
  }
  map[y][x] = '#';

  if(map[y][x+1] != '#' && x+1 < M)  rec(map, N, M, x+1 , y, food);
  if(map[y][x-1] != '#' && x-1 >= 0) rec(map, N, M, x-1 , y, food);
  if(map[y+1][x] != '#' && y+1 < N) rec(map, N, M, x , y+1, food); 
  if(map[y-1][x] != '#' && y-1 >= 0) rec(map, N, M, x , y-1, food);
}

void pacmon(int kasus){
  int N,M,x=-1,y=-1;
  scanf("%d %d", &N, &M); getchar();
  char maps[101][101];
  for(int i = 0; i < N; ++i){ // i representasi y, j representasi x.
    for(int j = 0; j < M; ++j){
      scanf("%c", &maps[i][j]);
      if(maps[i][j] == 'P') {
        x = j;
        y = i;
      }
    }
    getchar();
  }

  // for(int i = 0; i < N; ++i){
  //   for(int j = 0; j < N; ++j){
  //     printf("%c", maps[i][j]);
  //   }
  //   printf("\n");
  // }
  int food = 0;
  if (x == -1 || y == -1) {
      printf("Case #%d: 0\n", kasus);
      return;
  }
  rec(maps, N, M, x, y, &food);
  printf("Case #%d: %d\n",kasus, food);
}

int main(){
  int T;
  scanf("%d", &T); getchar();
  for(int i = 1; i <= T; ++i){
    pacmon(i);
  }
  return 0;
}