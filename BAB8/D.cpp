#include <stdio.h>
#include <string.h>

typedef struct {
  char name[101];
  int score;
} Student;

void merge(Student *arr, int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  Student lTemp[lLen];
  Student rTemp[rLen];

  for(int i = 0; i < lLen; ++i) lTemp[i] = arr[i + low];
  for(int i = 0; i < rLen; ++i) rTemp[i] = arr[mid + 1 + i];

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || (i < lLen && (lTemp[i].score > rTemp[j].score))) arr[k] = lTemp[i++];

    else if((j < rLen && i >= lLen) || (j < rLen && (rTemp[j].score > lTemp[i].score ))) arr[k] = rTemp[j++];

    else {

      if(strcmp(lTemp[i].name, rTemp[j].name) <= 0 ) arr[k] = lTemp[i++];
      else arr[k] = rTemp[j++];

    }
  }

}

void mergeSort(Student *arr, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

int binarySearch(Student *arr, int low, int high, char target[101]){
  while (low <= high){
    int mid = low + (high - low) / 2;
    if(strcmp(target, arr[mid].name) == 0) return mid;
    else if(strcmp(target, arr[mid].name) < 0){
      high = mid -1;
    }
    else {
      low = mid+1;
    }
  }
  return -1;
}

void Rank(int kasus){
  int N;
  scanf("%d", &N); getchar();

  Student arr[N];
  for(int i = 0; i < N; ++i){
    scanf("%[^#]#%d", arr[i].name, &arr[i].score); getchar();
  }

  mergeSort(arr, 0, N-1);

  char temp[101];
  scanf("%[^\n]", temp); getchar();

  int index = binarySearch(arr, 0, N-1, temp);
  int result = (index == -1) ? -1 : (index + 1);
  printf("Case #%d: %d\n", kasus, result);

  // for(int i = 0; i < N; ++i){
  //   printf("%s %d\n", arr[i].name, arr[i].score);
  // }

}

int main(){
  int T; 
  scanf("%d", &T); getchar();

  for(int i = 1; i <= T; ++i){
    Rank(i);
  }
  return 0;
}