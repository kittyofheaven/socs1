#include <stdio.h>

int main(){
  int N;
  scanf("%d", &N);
  long long jumlah_hewan = 0;

  for(int i = 0 ; i < N ; ++i){
    int hewan;
    scanf("%d", &hewan);
    jumlah_hewan += hewan;
  }

  printf("%lld\n", jumlah_hewan);
  
  return 0;
}