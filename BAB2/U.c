#include <stdio.h>

int main(){

  int T;
  scanf("%d", &T);

  long long A[T], B[T];

  for(int i = 0 ; i < T ; ++i){
    scanf("%lld %lld", &A[i], &B[i]);
  }
  for(int i = 0 ; i < T ; ++i){

    double result = (A[i] * B[i]) / 360.0;
    printf("%.2f\n", result);
  }
}
