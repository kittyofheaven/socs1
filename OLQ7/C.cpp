#include <stdio.h>
int jobonaci(int N){
  if(N==0) return 0;
  else if(N<=2) return 1;
  else return jobonaci(N-1) + jobonaci (N-3);
}
int main(){
  int number;
  scanf("%d", &number);
  printf("%d\n", jobonaci(number));
  return 0;
}