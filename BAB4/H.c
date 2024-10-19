#include <stdio.h>

int main(){

  int N;
  scanf("%d", &N); // jumlah kandang
  long long animals[N];

  for(int i = 0 ; i < N ; ++i){
    scanf("%lld", &animals[i]);
  }

  long long result = 0;
  for(int i = 0 ; i < N ; ++i){
    result+=animals[i];
  }

  printf("%lld\n", result);
}
