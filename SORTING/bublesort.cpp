#include <stdio.h>
void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void bubleSort(int *arr, int length){
  for(int i = 0; i < length; ++i){
    for(int j = 0; j < length-1; ++j){
      if(arr[j] > arr[j+1]) swap( &arr[j], &arr[j+1]);
    }
  }
}

void printArr(int *arr, int length){
  for(int i = 0; i < length; ++i){
    printf("%d", arr[i]);
    if(i != length-1)printf(" ");
  }
  printf("\n");
}

int main(){
  int arr[10] = {0,8,9,7,6,4,5,3,2,1};
  int arrLen = 10;
  printArr(arr, arrLen);
  bubleSort(arr, arrLen);
  printArr(arr, arrLen);



  return 0;
}