#include <stdio.h>

void swap(int *a, int*b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *arr, int low, int high){
  int pivot = arr[high];
  int i = low - 1;
  for(int j = low; j < high; ++j){
    if(arr[j] < pivot){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  i++;
  swap(&arr[i], &arr[high]);
  return i;
}

void quickSort(int *arr, int low, int high){
  if(low < high){
    int p = partition(arr, low, high);
    quickSort(arr, low, p-1);
    quickSort(arr, p+1, high);
  }
}



void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
  int arr[5] = {5,4,3,2,1};
  int n = sizeof(arr)/sizeof(arr[0]);

  printf("%d\n", n);

  quickSort(arr, 0, n-1);
  printArray(arr, n);
  return 0;
}