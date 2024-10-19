#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    long long A, B;
    scanf("%lld %lld", &A, &B);

    long long terminum = 0;
    long long botolKosong = 0;

    while(A > 0){
      terminum++;
      A--;
      botolKosong++;

      if(botolKosong==B){
        A++;
        botolKosong = 0;
      }

    }

    printf("Case #%d: %lld\n", i, terminum);
  }
  return 0;
}