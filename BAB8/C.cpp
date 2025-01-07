#include <stdio.h>

int main(){
  int N, M;
  scanf("%d %d", &N, &M);

  int arr[N];
  for(int i = 0; i < N; ++i){
    scanf("%d", &arr[i]);
  }

  for(int i = 0; i < M; ++i){
    int temp = -1;
    scanf("%d", &temp);

    for(int j = 0; j < N; ++j){
      if(temp == arr[j]) arr[j] = -1;
    }
  }

  int max = -1;
  for(int i = 0; i < N; ++i){
    if(arr[i] > max) max = arr[i];
  }

  printf("Maximum number is %d\n", max);
  return 0;
}