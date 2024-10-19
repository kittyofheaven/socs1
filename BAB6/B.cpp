#include <stdio.h>
#include <math.h>

void sumRec(int arr[], int N, int index, int currentSum){
  int left = 2 * index, right = (2 * index) + 1;

  if(index > N) return;

  currentSum += arr[index];

  if (left > N && right > N) {
      printf("%d\n", currentSum);
      return;
  }

  sumRec(arr, N, left, currentSum);
  sumRec(arr, N, right, currentSum);
}

void sumOfTheLeaves(int kasus){
  int N;
  scanf("%d", &N);
  int arr[N+1];
  for(int i = 1; i <= N; ++i){
    scanf("%d", &arr[i]);
  }
  printf("Case #%d:\n", kasus);
  sumRec(arr, N, 1, 0);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    sumOfTheLeaves(i);
  }
  return 0;
}