#include <stdio.h>

int main(){
  int N = 1;
  int Q;
  scanf("%d", &Q);

  int hasil = 0;
  for(int i = 0; i < Q; ++i){
    N = (2 * N + 1);
  }

  printf("%d\n", N);

  return 0;
}