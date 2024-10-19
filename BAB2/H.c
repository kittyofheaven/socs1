#include <stdio.h>

int main(){
  int a[3], b[3], c[3], d[3];

  for(int i = 0 ; i < 3 ; ++i){
    scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
  }
  for(int i = 0 ; i < 3 ; ++i){
    double result = (a[i]/1.0) + (b[i]/2.0) + (c[i]/3.0) + (d[i]/4.0) + (b[i]/2.0) + (c[i]/3.0) + (d[i]/4.0) + (c[i]/3.0) + (c[i]/3.0) + (d[i]/4.0) + (c[i]/3.0) + (b[i]/2.0) + (d[i]/4.0) + (c[i]/3.0) + (b[i]/2.0) + (a[i]/1.0);
    printf("%.2lf\n", result);
  }
}
