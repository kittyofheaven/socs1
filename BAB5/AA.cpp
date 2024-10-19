#include <stdio.h>
#include <string.h>

int main(){
  int N;
  scanf("%d", &N);

  long long A[N];
  memset(A, 0, sizeof(A));
  // for(int i = 0; i < N; ++i){
  //   A[i]=0;
  // }

  int count = 0;
  for(int i = 0; i < N; ++i){
    long long temp;
    scanf("%lld", &temp);

    char alreadyInsideArray = 0;
    for(int j = 0; j < i; ++j){
      if(temp == A[j]) alreadyInsideArray = 1;
    }

    A[i] = temp;

    if (alreadyInsideArray == 0) count++;
  }

  printf("%d\n", count);

  return 0;
}