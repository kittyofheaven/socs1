#include <stdio.h>
#include <math.h>

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

void guest(int kasus){
  long long int arr[25] = {0};
  for(int i = 0; i < 25; ++i){
    scanf("%lld", &arr[i]);
  }
  mergeSort(arr, 0, 24);
  for(int i = 0; i < 25; ++i){
    printf("%lld ", arr[i]);
  }
  printf("\n%lf %lf %lf %lf %lf\n", ceil(arr[0]/2.0), ceil(arr[5]/2.0), ceil(arr[10]/2.0), ceil(arr[15]/2.0), ceil(arr[20]/2.0));

}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    guest(i);
  }
  return 0;
}