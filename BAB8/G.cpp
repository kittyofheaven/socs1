#include <stdio.h>

void pisang(int kasus){
  long long int N, K, jumlah = 0;
  scanf("%lld %lld", &N, &K);
  for(int i = 0; i < N; ++i){
    long long int temp = -1;
    scanf("%lld", &temp);
    if(K <= temp) jumlah++;
  }
  printf("Case #%d: %lld\n", kasus, jumlah);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    pisang(i);
  }
}