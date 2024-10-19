#include <stdio.h>

int threeOn(int number){
  int count = 0;
  while(number>0){
    if(number & 1) count++;
    if(count >= 3) return 1;
    number>>=1;
  }
  return 0;
}

void binaryThree(int kasus){
  int N;
  scanf("%d", &N);
  int arr[N];
  for(int i = 0; i < N; ++i){
    scanf("%d", &arr[i]);
  }

  int threeCount = 0;
  int zeroCount = 0;
  int temp;
  for(int i = 0; i < N-1; ++i){
    for(int j = i+1; j < N; ++j){
      temp = arr[i]^arr[j];
      (threeOn(temp)) ? threeCount++ : zeroCount++;
    }
  }

  printf("Case #%d: %d %d\n", kasus, threeCount, zeroCount);
}


int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    binaryThree(i);
  }
}