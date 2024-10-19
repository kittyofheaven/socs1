#include <stdio.h>

int main(){

  int T;
  scanf("%d", &T);

  int a[T], b[T], c[T], d[T];

  for(int i = 0 ; i < T ; ++i){
    scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
  }
  for(int i = 0 ; i < T ; ++i){
    double result = (a[i]/1.0) + (b[i]/2.0) + (b[i]/2.0) + (c[i]/3.0) + (d[i]/4.0) + (c[i]/3.0) + (a[i]/1.0) + (b[i]/2.0) + (b[i]/2.0) + (c[i]/3.0) + (d[i]/4.0) + (c[i]/3.0);
    printf("%.2lf\n", result);
  }
}
