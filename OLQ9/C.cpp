#include <stdio.h>
#include <string.h>

typedef struct{
  char name[51];
  int urgency;
} SickPeople;

void merge(SickPeople *arr, int low, int mid, int high){
  int lLen = mid - low +1;
  int rLen = high - mid;

  SickPeople lTemp[lLen];
  SickPeople rTemp[rLen];

  for(int i = 0; i < lLen; ++i) lTemp[i] = arr[low+i];
  for(int i = 0; i < rLen; ++i) rTemp[i] = arr[mid+1+i];

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || ((i < lLen) && (lTemp[i].urgency >= rTemp[j].urgency))){
      if(lTemp[i].urgency == rTemp[j].urgency){
        if(strcmp(lTemp[i].name,rTemp[j].name) <= 0) arr[k] = lTemp[i++];
        else arr[k] = rTemp[j++];
      } else arr[k] = lTemp[i++];
    } else arr[k] = rTemp[j++];
  }
}

void mergeSort(SickPeople *arr, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

int main(){
  int N;
  scanf("%d", &N); getchar();
  SickPeople anjaymabarkelasdek[N];
  for(int i = 0; i < N; ++i){
    scanf("%s %d", anjaymabarkelasdek[i].name, &anjaymabarkelasdek[i].urgency); getchar();
  }
  mergeSort(anjaymabarkelasdek, 0, N-1);
  for(int i = 0; i < N; ++i){
    printf("%s %d\n", anjaymabarkelasdek[i].name, anjaymabarkelasdek[i].urgency);
  }
}