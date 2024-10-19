#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 0 ; i < T ; ++i){
    int X,P;
    scanf("%d %d", &X, &P);
    int sisa;
    int result;

    for(int i = 0 ; i <= P ; ++i){
      sisa = X % 2; 
      X /= 2;

      if(i == P){
        result = sisa;
      }
    }

    printf("%d\n", result);
  }
  
  return 0;
}