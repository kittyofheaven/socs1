#include <stdio.h>

int memo[1001][1001];

void rec(long long int M, long long int N, long long int *result, bool isSpecial){

  long long int temp = 0;

  if(M <= 0) return;

  if (memo[M][N] != -1 && !isSpecial) {
    *result = (*result + memo[M][N]) % 1000000000; 
    return;
  }

  if(isSpecial && M>0) {
    temp += 1;
    rec(M-1, N-1, &temp, true);
  }
  else if(M > 0){
    temp += N-1;
    
    for(int i = 0; i < N-1; ++i){
      rec(M-1, N-1, &temp, false);
    }

    temp += 1;
    rec(M-1, N-1, &temp, true);
  }

  memo[M][N] = temp %  1000000000;
  *result += temp %  1000000000;
  return;
}

void weirdTree(int kasus){
  int M, N;
  scanf("%d %d", &M, &N);

  for (int i = 0; i <= M; ++i)
    for (int j = 0; j <= N; ++j)
      memo[i][j] = -1;

  long long int result = 0;
  rec(M,N,&result, false);
  printf("Case #%d: %lld\n", kasus, result);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    weirdTree(i);
  }
}