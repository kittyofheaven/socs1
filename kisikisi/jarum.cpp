#include <stdio.h>

int penjumlahanBil(int bilangan){
  int result = 0;;
  while (bilangan>0){
    result += bilangan%10;
    bilangan /= 10;
  }
  return result;
}

int main(){
  int N,J;
  scanf("%d %d", &N, &J);
  int count = 0;
  for(int i = 1; i <= N; ++i){
    if(penjumlahanBil(i) == J) count++;
  }

  printf("%d\n", count);
}