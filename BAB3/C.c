#include <stdio.h>

int main(){
  int T; // testcase
  scanf("%d", &T);

  int A[T], B[T]; //buat array dengan panjang T
  for(int i = 0 ; i < T; ++i){ 
    scanf("%d %d", &A[i], &B[i]);
    getchar();
  }

  for(int i = 0 ; i < T; ++i){
    A[i] >= B[i] ? printf("Case #%d: Go-Jo\n", i+1) : printf("Case #%d: Bi-Pay\n", i+1);
  }

  return 0;
}