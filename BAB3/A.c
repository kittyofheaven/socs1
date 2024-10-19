#include <stdio.h>

int main(){

  int N;
  scanf("%d", &N);

  if((N & 1) == 1){
    printf("ODD");
  } else {
    printf("EVEN");
  }

  printf("\n");
  return 0;
}