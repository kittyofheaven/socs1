#include <stdio.h>

int main(){
  int x[5] = {1,2,3,4,5};

  printf("x array address: %d\n", &x);
  for(int i = 0; i < 5; ++i){
    printf("%d: %d\n",x[i], &x[i]);
  }

  return 0;
}