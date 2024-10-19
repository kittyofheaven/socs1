#include <stdio.h>

int fFunc(int N, int *count){
  if(N == 0) return 1;
  if (N == 1) return 2;
  if(N % 3 == 0){
    *count+=1;
  }
  if(N % 5 == 0) return N * 2;

  return fFunc(N-1, count) + N + fFunc(N-2, count) + N - 2;
}


int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1 ; i <= T ; ++i){
    int N;
    scanf("%d", &N);
    int count = 0;
    int result = fFunc(N, &count);
    printf("Case #%d: %d %d\n", i, result, count);
  }
  return 0;
}