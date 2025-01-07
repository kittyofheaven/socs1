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

int binarySearch(int *arr, int low, int high, int target){
  while (low <= high){
    int mid = low + (high - low) / 2;
    if(arr[mid] == target) return mid;
    else if(target < arr[mid]){
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

void anjay(int kasus){
  int N;
  scanf("%d", &N);

  int MMR[N];
  for(int i = 0; i < N; ++i){
    scanf("%d", &MMR[i]);
  }

  mergeSort(MMR, 0, N-1);
  int min = -1, max = -1, temp;
  scanf("%d", &temp);

  int index = binarySearch(MMR, 0, N-1, temp);

  if(index != -1){
    if(index == 0){
      min = MMR[0];
      max = MMR[1];
    } else if(index == N-1){
      min = MMR[index-1];
      max = MMR[index];
    } else{
      min = MMR[index];
      max = MMR[index+1];
    }
  }

  printf("CASE #%d: %d %d\n", kasus, min, max);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    anjay(i);
  }

  return 0;
}