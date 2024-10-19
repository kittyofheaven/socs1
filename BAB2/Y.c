#include <stdio.h>

int main(){

  int T;
  scanf("%d", &T);

  int P[T], N[T];

  for(int i = 0 ; i < T ; ++i){
    scanf("%d %d", &P[i], &N[i]);
  }
  for(int i = 0 ; i < T ; ++i){
    double result = P[i] / 100.0 * N[i];
    printf("%.2lf\n", result);
  }
}
