#include <stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubleSort(int *count, int *arr, int len){
  for(int i = 0; i < len; ++i){
    for(int j = 0; j < len-1; ++j){
      if(arr[j] > arr[j+1]){
        swap(&arr[j], &arr[j+1]);
        (*count)++;
      } 
    }
  }
}

void christmasTrain(int kasus){
  int N, X;
  scanf("%d %d", &N, &X);

  int arr[N];
  for(int i = 0; i < N; ++i){
    scanf("%d", &arr[i]);
  }

  int count = 0;
  bubleSort(&count, arr, N);
  printf("Case #%d: %d\n", kasus, X * count);
}

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    christmasTrain(i);
  }
}