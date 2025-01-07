#include <stdio.h>
#include <string.h>

typedef struct
{
  char name[51];
  int number;
}Hahaha;

void merge(Hahaha *arr, int low, int mid, int high){
  int lLen = mid - low +1;
  int rLen = high - mid;

  Hahaha lTemp[lLen];
  Hahaha rTemp[rLen];

  for(int i = 0; i < lLen; ++i) lTemp[i] = arr[low+i];
  for(int i = 0; i < rLen; ++i) rTemp[i] = arr[mid+1+i];

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || ((i < lLen) && (lTemp[i].number >= rTemp[j].number))){
      if(lTemp[i].number == rTemp[j].number){
        if(strcmp(lTemp[i].name,rTemp[j].name) <= 0) arr[k] = lTemp[i++];
        else arr[k] = rTemp[j++];
      } else arr[k] = lTemp[i++];
    } else arr[k] = rTemp[j++];
  }
}

void mergeSort(Hahaha *arr, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

void gatau(int kasus){
  int N;
  scanf("%d", &N); getchar();

  Hahaha arr[N];

  for(int i = 0; i < N; ++i){
    scanf("%[^#]#%d", arr[i].name, &arr[i].number); getchar();
  }

  mergeSort(arr, 0, N-1);
  
  printf("Case #%d:\n", kasus);
  for(int i = 0; i < N; ++i){
    printf("%s - %d\n", arr[i].name, arr[i].number);
  }
}

int main(){
  int T;
  scanf("%d", &T); getchar();
  for(int i = 1; i <= T; ++i){
    gatau(i);
  }
}
