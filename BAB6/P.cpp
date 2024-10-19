#include <stdio.h>
int rec(int N){
  if(N & 1) return 1;
  else if(N == 0) return 0;
  else return rec(N-1)+rec(N-2);
}

int main(){
  int N;
  scanf("%d", &N);
  printf("%d\n", rec(N));
}