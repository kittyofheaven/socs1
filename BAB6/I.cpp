#include <stdio.h>

long long int mem[31] = {0};

long long int fibbonaci(int N, long long int *count){
  (*count)++;
  if (N==0) {
    return 0;
  } else if (N == 1){
    return 1;
  } else{
    return fibbonaci(N-1, count) + fibbonaci(N-2, count);
  }
}

void fiboCount(int kasus){
  int N;
  long long int count = 0;
  scanf("%d", &N);
  fibbonaci(N, &count);
  printf("Case #%d: %lld\n",kasus, count);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    fiboCount(i);
  }
}