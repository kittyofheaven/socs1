#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    int N;
    scanf("%d", &N);

    printf("Case #%d:", i);

    long long prevCut = 0;
    long long cut = 1;
    for(int j = 0; j < N; ++j){
      int temp = cut;
      cut = cut + prevCut + 1;
      prevCut = temp;
      printf(" %lld", cut);
    }
    printf("\n");





  }

  return 0;
}