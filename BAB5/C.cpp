#include <stdio.h>

int main(){
  int N;
  scanf("%d", &N);
  int item[N];

  for(int i = 0; i < N; ++i){
    scanf("%d", &item[i]);
  }

  int Q;
  scanf("%d", &Q);
  for(int i = 1; i <= Q; ++i){
    int A, B;
    scanf("%d %d", &A, &B);
    item[A-1] = B;
    
    printf("Case #%d:", i);
    for(int j = 0; j < N; ++j){
      printf(" %d", item[j]);
    }
    printf("\n");
  }

  return 0;
}