#include <stdio.h>

void soorting(int kasus){
  int a, b;
  scanf("%d %d", &a, &b);
  if(a < b){
    printf("%d %d\n", a, b);
  } else {
    printf("%d %d\n", b, a);
  }
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    soorting(i);
  }
}