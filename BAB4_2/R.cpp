#include <stdio.h>

void absolute(long long int *number){
  *number = (*number < 0) ?  (*number * -1) : (*number);
}

void bibi(int kasus){
  int N;
  scanf("%d", &N);
  long long int prev = 2000000001, now, diff = 2000000001, minDiff = 2000000001;
  for(int i = 0; i < N; ++i){
    scanf("%lld", &now);
    diff = now - prev;
    absolute(&diff);
    // printf("%lld %lld %lld\n", prev, now, diff);
    if(diff < minDiff){
      minDiff = diff;
    }
    prev = now;
  }

  printf("Case #%d: %lld\n",kasus, minDiff);

}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    bibi(i);
  }
}