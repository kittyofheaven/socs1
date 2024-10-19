#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    int N;
    scanf("%d", &N);

    long long result = 0;
    for(int j = 0; j < N ; ++j ){
      long long input;
      scanf("%lld", &input);
      result += input;
    }

    printf("Case #%d: %lld\n", i, result);
  }

  return 0;
}