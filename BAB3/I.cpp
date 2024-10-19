#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);
  int A[T], B[T], C[T];

  for(int i = 0 ; i < T ; ++i){
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
  }

  for(int i = 0 ; i < T ; ++i){
    double cashback = (A[i] * B[i] / 100.0)  > C[i] ? C[i] : A[i] * B[i] / 100.0;
    printf("Case #%d: %.0lf\n", i+1, cashback);
  }
  return 0;
}