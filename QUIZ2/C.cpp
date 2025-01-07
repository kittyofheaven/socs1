#include <stdio.h>
#include <string.h>

void merge(char arr[10001][101], int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  char lTemp[lLen][51];
  char rTemp[rLen][51];

  for(int i = 0; i < lLen; ++i) strcpy(lTemp[i], arr[low+i]);
  for(int i = 0; i < rLen; ++i) strcpy(rTemp[i], arr[mid+1+i]);

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || (i < lLen && strcmp(lTemp[i], rTemp[j]) <= 0)) strcpy(arr[k], lTemp[i++]);
    else strcpy(arr[k], rTemp[j++]);
  }
}

void mergeSort(char arr[10001][101], int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

int binarySearch(char arr[10001][101], int low, int high, char *target){
  while (low <= high){
    int mid = low + (high - low) / 2;
    if(strcmp(arr[mid], target) == 0){
      return mid;
    } else if(strcmp(target, arr[mid]) < 0){
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

int main(){
  int N;
  scanf("%d", &N); getchar();

  char words[10001][101];
  for(int i = 0; i < N; ++i){
    scanf("%s", words[i]); getchar();
  }

  mergeSort(words, 0, N-1);

  // for(int i = 0; i < N; ++i){
  //   printf("%s\n", words[i]);
  // }

  int page = 0;
  scanf("%d", &page); getchar();
  char target[51];
  scanf("%s", target); getchar();

  int index = binarySearch(words, 0, N-1, target);

  if(index == -1){
    printf("Not Found\n");
  } else {
    int result = (index / page) + 1;
    printf("Found at %d\n", result);
  }
}