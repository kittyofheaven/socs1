#include <stdio.h>

void merge(int *arr, int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  int lTemp[lLen];
  int rTemp[rLen];

  for(int i = 0; i < lLen; ++i) lTemp[i] = arr[low+i];
  for(int i = 0; i < rLen; ++i) rTemp[i] = arr[mid+1+i];
  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || (i < lLen) && (lTemp[i] <= rTemp[j])) arr[k] = lTemp[i++];
    else arr[k] = rTemp[j++];
  }
}

void mergeSort(int *arr, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

int binarySearch(int *arr, int low, int high, int search){
  if(low <= high){
    int mid = low + (high - low) / 2;
    if(arr[mid] == search) return mid;
    else if (search < arr[mid])
    {
      return binarySearch(arr, low, mid-1, search);
    } else {
      return binarySearch(arr, mid+1, high, search);
    }
  }

  return -2;
}

int main(){
  int N, Q;
  scanf("%d", &N);

  int heights[N];
  for(int i = 0; i < N; ++i){
    scanf("%d", &heights[i]);
  }

  mergeSort(heights, 0, N-1);

  scanf("%d", &Q);
  int temp;
  for(int i = 0; i < Q; ++i){
    scanf("%d", &temp);
    printf("%d\n", binarySearch(heights, 0, N-1, temp) + 1);
  }
  return 0;
}