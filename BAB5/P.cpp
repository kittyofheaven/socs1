#include <stdio.h>

int main(){
  int N;
  scanf("%d", &N);

  int matriks[N*N];
  int count[(N*N) + 1];
  int tidakLengkapCount = 0;
  for(int i = 0; i < (N*N) + 1; ++i){
    count[i] = 0;
  }

  int temp;
  for(int i = 0; i < N*N; ++i){
    scanf("%d", &temp);
    if(temp !=0) count[temp]++;
  }

  for(int i = 1; i <= N; ++i){
    if(count[i] < N) tidakLengkapCount++;
  }

  printf("%d\n", tidakLengkapCount);

}