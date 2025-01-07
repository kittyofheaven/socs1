#include <stdio.h>

void boxOfChocolate(int kasus){
  int N, M;
  scanf("%d %d", &N, &M);

  long long total = 0;
  long long temp = 0;
  long long maxWeight = 0;
  
  for(int i = 0; i < N; ++i){
    maxWeight = 0;
    for(int j = 0; j < M; ++j){
      scanf("%lld", &temp);
      if(temp > maxWeight){
        maxWeight = temp;
      }
    }
    total+=maxWeight;
  }

  printf("Case #%d: %lld\n", kasus, total);

}

int main(){
  int T;
  scanf("%d", &T);
  
  for(int i = 1; i <= T; ++i){
    boxOfChocolate(i);
  }
}