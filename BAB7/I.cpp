#include <stdio.h>

void merge(long long int *arr, int low, int mid, int high){
  int lLen =  mid - low + 1;
  int rLen = high - mid;

  long long int lTemp[lLen];
  long long int rTemp[rLen];

  for(int i = 0; i < lLen; ++i) lTemp[i] = arr[low+i];
  for(int i = 0; i < rLen; ++i) rTemp[i] = arr[mid+1+i];
  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || ((i < lLen) && (lTemp[i] <= rTemp[j]))) arr[k] = lTemp[i++];
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

void theatre(int kasus){
  int N;
  scanf("%d", &N);
  
  long long int arr[N];
  for(int i = 0; i < N; ++i){
    scanf("%lld", &arr[i]);
  }

  mergeSort(arr, 0, N-1);

  // for(int i = 0; i < N ; ++i){
  //   printf("%lld ", arr[i]);
  // }

  int mid = (N / 2) - 1;
  long long int max = 0;
  for(int i = 0; i < N-1; ++i){
    if(i == mid) continue;
    
    long long int selisih = ((arr[i] - arr[i+1]) < 0) ? (arr[i+1] - arr[i]) : (arr[i] - arr[i+1]) ; 
    if(max < selisih) max = selisih;
  }

  printf("Case #%d: %lld\n", kasus, max);
}

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    theatre(i);
  }
} 