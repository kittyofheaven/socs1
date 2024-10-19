#include <stdio.h>

void summerVacation(int kasus){
  int N;
  scanf("%d", &N);
  int count = 0;
  int numArr[N];
  for(int i = 0; i < N; ++i){
    scanf("%d", &numArr[i]);
  }

  char sumFlag[1000] = {0};
  for(int i = 0; i < N; ++i){
    for(int j = i+1; j < N; ++j){
        sumFlag[(numArr[i] + numArr[j]) - 1] = 1;
    }
  }

  for(int i = 0; i < N; ++i){
    if(sumFlag[numArr[i] - 1]){
      count++;
    }
  }
  printf("Case #%d: %d\n", kasus, count);
}

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    summerVacation(i);
  }

  return 0;
}