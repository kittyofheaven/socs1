#include<stdio.h>

int binarySearch(int *arr, int low, int high, int search){
  if(low <= high){
    int mid = low + (high - low) / 2;

    if(search == arr[mid]){
      return mid;
    }
    else if(search > arr[mid]){
      return binarySearch(arr, mid+1, high, search);
    } else {
      return binarySearch(arr, low, mid-1, search);
    }
  }

  return -1;
}

int main(){
  int arr[6] = {1,3,5,7,9,10};

  printf("%d\n", binarySearch(arr, 0, 6-1, 7));

  return 0;
}