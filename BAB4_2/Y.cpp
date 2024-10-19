#include <stdio.h>

void frame(int kasus){
  int N,M;
  scanf("%d %d", &N, &M);

  printf("Case #%d:\n", kasus);
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      if(i == 0 || i == N-1){
        printf("#");
      } else {
        if ( j==0 || j == M-1){
          printf("#");
        } else {
          printf(" ");
        }
      }
    }
    printf("\n");
  }

}


int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    frame(i);
  }
  return 0;
}