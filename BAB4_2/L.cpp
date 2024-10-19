#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1 ; i <= T ; ++i){
    int A, B;
    scanf("%d %d", &A, &B);

    int botolKosong = 0;
    int telahDiminum = 0;
    while(A >0){
      telahDiminum++;
      botolKosong++;
      A--;
      if(botolKosong == B){
        A++;
        botolKosong = 0;
      }
    }

    printf("Case #%d: %d\n", i, telahDiminum);
  }
  
  return 0;
}