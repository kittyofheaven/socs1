#include <stdio.h>

void merge(long long int *arr, int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  long long int lTemp[lLen];
  long long int rTemp[rLen];

  for(int i = 0; i < lLen; ++i) lTemp[i] = arr[low+i];
  for(int i = 0; i < rLen; ++i) rTemp[i] = arr[mid+1+i];

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || (i < lLen && lTemp[i] <= rTemp[j])) arr[k] = lTemp[i++];
    else arr[k] = rTemp[j++];
  }
}

void mergeSort(long long int *arr, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

int main(){
  int N, jumlah = 0;
  scanf("%d", &N);
  long long int arr[N], Y;
  for(int i = 0; i < N; ++i){
    scanf("%lld", &arr[i]);
  }
  mergeSort(arr, 0, N-1);
  scanf("%lld", &Y);
  for(int i = 0; i < N; ++i){
    if (arr[i] <= Y) {
        jumlah++;
        Y -= arr[i];
    }
  }
  printf("%d\n", jumlah);
}