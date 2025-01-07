#include <stdio.h>
#include <stdlib.h>
int *arrSort = (int*) calloc(sizeof(int), 1001);

void printArr(int *arr, int length){
  for(int i = 0; i < length; ++i){
    printf("%d", arr[i]);
    if(i != length-1)printf(" ");
  }
  printf("\n");
}

void theSort(int *arr, int length){
  for(int i = 0; i < length; ++i){
    printf("%d\n", arr[i]);
    (arrSort[arr[i]])++; 
  }
  for(int i = 0, j = 0; i <= 1000 && j < length; ++i){
    if(arrSort[i] != 0){
      for(int k = 0; k < arrSort[i]; ++k){
        arr[j++] = i;
      }
    }
  }

  printArr(arrSort, 1000);
}

int main(){
  int arr[10] = {0,8,9,7,6,4,5,3,2,1000};
  int arrLen = 10;
  printArr(arr, arrLen);
  theSort(arr, arrLen);
  printArr(arr, arrLen);
  free(arrSort);
}