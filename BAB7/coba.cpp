#include <stdio.h>

void merge(int *arr, int low, int mid, int high){
  int leftLen = mid - low + 1;
  int rightLen = high - mid;

  int tempLeftArr[leftLen];
  int tempRightfArr[rightLen];

  for(int i = 0; i < leftLen; ++i) tempLeftArr[i] = arr[low + i]; 
  for(int i = 0; i < rightLen; ++i) tempRightfArr[i] = arr[mid+1+i];

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < leftLen && j >= rightLen) || (i < leftLen) && tempLeftArr[i] <= tempRightfArr[j]) arr[k] = tempLeftArr[i++];
    else arr[k] = tempRightfArr[j++];
  }
}

void mergeSort(int *arr, int low, int high){
  if(low < high){
    int mid = low + (high-low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

int main(){
  int angka[10] = {8,9,7,6,8,9,0,7,6,2};
  mergeSort(angka, 0, 9);

  printf("Sorted :");
  for(int i = 0; i < 10; ++i){
    printf(" %d", angka[i]);
  }
  printf("\n");

  return 0;
}