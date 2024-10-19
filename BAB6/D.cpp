#include <stdio.h>

long long F(int N){
  if(N == 1){
    return 1;
  } else if((N & 1) == 1){
    return F(N-1) + F(N+1);
  } else {
    return F(N/2);
  }
}

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    long long N;
    scanf("%lld", &N);

    printf("Case #%d: %lld\n",i,F(N));
  }

  return 0;
}