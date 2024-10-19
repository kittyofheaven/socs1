#include <stdio.h>

void froggerRace(int kasus){
  long long int K, count = 0, jump = 1;
  scanf("%lld", &K);
  while(K>0){
    K-= jump;
    jump+=1;
    count++;
  }
  printf("Case #%d: %lld\n", kasus, count);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    froggerRace(i);
  }
}