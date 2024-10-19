#include <stdio.h>

void swap(int *a, int*b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high){
  int pivot = arr[high];

  int i = low - 1; // karena pointer i terletak sebelum elemen pertama array, sedangkan pointer j terletak di elemen pertama array

  for(int j = low; j <= high - 1 ; ++j){
    if(arr[j] < pivot){
      i++; // only increment i when the elemen is < pivot;
      swap(&arr[i], &arr[j]);
    }

  }
  // Move pivot after smaller elements and
  // return its position
  swap(&arr[i + 1], &arr[high]); // tempatkan pivot ke posisinya
  return i + 1; // return pivot index
}

void quicksort(int arr[], int low, int high){
  if(low < high){
    int pivot = partition(arr, low, high);

    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
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

  quicksort(arr, 0, n-1);
  printArray(arr, n);
  return 0;
}