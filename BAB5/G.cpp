#include <stdio.h>

void starshipCrusader(int kasus){
  int N;
  scanf("%d", &N);
  long long testResult[N];
  long long temp;
  long long failureCount = 0;

  for(int i =0; i < N; ++i){
    scanf("%lld", &testResult[i]);
  }

  for(int i =0; i < N; ++i){
    scanf("%lld", &temp);
    if(testResult[i] < temp){
      failureCount++;
    }
  }

  printf("Case #%d: %lld\n", kasus, failureCount);

}

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    starshipCrusader(i);
  }


  return 0;
}