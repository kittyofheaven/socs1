#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);

  for(int kasus = 1; kasus <= T; ++kasus){
    int N;
    scanf("%d", &N);

    long long X[N];
    for(int i = 0; i < N; ++i){
      scanf("%lld", &X[i]);
    }

    printf("Case #%d:", kasus);
    for(int i = N-1; i >= 0; --i){
      printf(" %lld", X[i]);
      // if(i != N-1) {
      //   printf(" ");
      // }
    }
    printf("\n");
  }

  return 0;
}