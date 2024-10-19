#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    int N;
    scanf("%d", &N);

    int odd = 0, even = 0;
    for(int i = 0; i < N; ++i){
      int input;
      scanf("%d", &input);
      ((input & 1) == 1) ? odd++ : even++;
    }
    printf("Odd group : %d integer(s).\n", odd);
    printf("Even group : %d integer(s).\n", even);
    printf("\n");
  }
  return 0;
}