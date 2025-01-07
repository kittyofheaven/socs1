#include <stdio.h>
#include <string.h>

typedef struct {
  char name[101];
  int score;
} UTCScore;

void merge(UTCScore *arr, int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  UTCScore lTemp[lLen];
  UTCScore rTemp[rLen];

  for(int i = 0; i < lLen; ++i) lTemp[i] = arr[low+i];
  for(int i = 0; i < rLen; ++i) rTemp[i] = arr[mid+1+i];

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || (i < lLen && (strcmp(lTemp[i].name, rTemp[j].name) <= 0))) arr[k] = lTemp[i++];
    else arr[k] = rTemp[j++];
  }
}

void mergeSort(UTCScore *arr, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

int binarySearch(UTCScore *arr, int low, int high, char search[101]){
  if(low <= high){
    int mid = low + (high - low) / 2;
    if(strcmp(search, arr[mid].name) == 0) return arr[mid].score;
    else if(strcmp(search, arr[mid].name) < 0) return binarySearch(arr,low,mid-1,search);
    else return binarySearch(arr,mid+1,high,search);
  }
  return - 1;
}

int main(){
  int len = 4;
  UTCScore arr[4] = {{"Daniel", 90},{"Ricky", 89},{"Adriel", 100},{"Cindy", 95}};
  mergeSort(arr, 0, len-1);

  char input[101];
  printf("Input name to be search : ");
  scanf("%[^\n]", input);
  int nilai = binarySearch(arr, 0, len-1, input);

  if(nilai == -1) printf("Student not found!\n");
  else printf("score : %d\n", nilai);

  // for(int i = 0; i < len; ++i){
  //   printf("%s %d\n", arr[i].name, arr[i].score);
  // }
  return 0;
}