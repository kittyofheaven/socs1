#include <stdio.h>

int main(){
  int a,b,c,d,e,f;
  scanf("%d + %d =", &a, &b); getchar();
  scanf("%d + %d =", &c, &d); getchar();
  scanf("%d + %d =", &e, &f); getchar();
  
  printf("%d\n", a+b);
  printf("%d\n", c+d);
  printf("%d\n", e+f);
}