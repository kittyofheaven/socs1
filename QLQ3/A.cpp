#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 0 ; i < T; ++i){
    int A,B;
    scanf("%d %d", &A, &B);

    int output = ((A/B) << B);
    printf("%d\n", output);
  }

  return 0;
}