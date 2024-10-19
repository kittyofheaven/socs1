#include <stdio.h>

int main(){
  int A[4], B[4];

  for(int i = 0 ; i < 4 ; ++i){
    scanf("%d %d", &A[i], &B[i]);
  }

  for(int i = 0 ; i < 4 ; ++i){
    printf("%d\n", A[i] * B[i]);
  }


  return 0;
}