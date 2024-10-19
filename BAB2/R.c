#include<stdio.h>

int main(){
  double a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;

  scanf("(%lf+%lf)x(%lf-%lf)", &a, &b, &c, &d); getchar();
  scanf("(%lf+%lf)x(%lf-%lf)", &e, &f, &g, &h); getchar();
  scanf("(%lf+%lf)x(%lf-%lf)", &i, &j, &k, &l); getchar();
  
  double result1 = (a+b) * (c-d);
  double result2 = (e+f) * (g-h);
  double result3 = (i+j) * (k-l);

  printf("%.0lf %.0lf %.0lf\n", result1, result2, result3);
  
  return 0;
}