#include <stdio.h>

int main(){
  int w;
  scanf("%d", &w);
  if(w == 2){
    printf("NO\n");
    return 0;
  }
  (w&1) ? printf("NO\n") : printf("YES\n");
  return 0;
}