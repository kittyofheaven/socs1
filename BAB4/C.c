#include <stdio.h>

int main(){
  int A, B;
  scanf("%d %d", &A, &B);

  for(int i = A ; i < A+B ; ++i){
    printf("%d\n", i);
  }

  return 0;
}