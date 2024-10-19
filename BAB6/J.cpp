#include <stdio.h>

long long int rec(long long int N, long long int *count){
  (*count)++;
  if(N == 1) return 1;
  else if ((N&1) == 1) return rec((N*3)+1, count);
  else return rec(N/2, count);
}

void epicGame(int kasus){
  long long int N, count = 0;
  scanf("%lld", &N);
  rec(N, &count);
  printf("Case #%d: ", kasus);
  (count&1) ? printf("Lili\n") : printf("Jojo\n");
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    epicGame(i);
  }
  return 0;
}