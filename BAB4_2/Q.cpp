#include <stdio.h>
#include <math.h>

int main(){
  int T;
  scanf("%d", &T);
  
  for(int i = 1 ; i <= T ; ++i){
    int N, X;
    scanf("%d %d", &N, &X);

    int result;
    if(N - X < X) { // buka dari belakang
      if((N&1)==1){ // ganjil
        result = (N-X) / 2;
      } else { // genap
        result = ceil((N-X) / 2.0);
      }

    } else {
      result = X / 2;
    }

    printf("Case #%d: %d\n", i, result);
  }

  return 0;
}