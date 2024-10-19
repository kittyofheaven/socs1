#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);
  int N[T];

  long long result[T];

  for(int i = 0 ; i < T; ++i){
    scanf("%d", &N[i]);

    long long A[N[i]];
    for(int j = 0 ; j < N[i] ; ++j){
      scanf("%lld", &A[j]);
    }

    result[i] = 0;
    for(int j = 0 ; j < N[i] ; ++j){
      result[i] += A[j];
    }
  }

  for(int i = 0 ; i < T ; ++i ){
    printf("Case #%d: %lld\n", i+1, result[i]);
  }
  return 0;
}