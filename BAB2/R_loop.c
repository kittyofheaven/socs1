#include<stdio.h>

int main(){
  double a[3], b[3], c[3], d[3];

  for(int i = 0 ; i < 3 ; ++i){
    scanf("(%lf+%lf)x(%lf-%lf)", &a[i], &b[i], &c[i], &d[i]); getchar();
  }

  double result[3];

  for(int i = 0 ; i < 3 ; ++i){
    result[i] = (a[i]+b[i]) * (c[i]-d[i]); 
  }

  printf("%.0lf %.0lf %.0lf\n", result[0], result[1], result[2]);
  
  return 0;
}