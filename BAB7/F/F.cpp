#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct deadline{
  char name[11];
  long long int date;
} Deadline;

void merge(Deadline *jadwal, int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen =  high - mid;

  Deadline *lTemp = (Deadline *) malloc(sizeof(Deadline) * lLen);
  Deadline *rTemp = (Deadline *) malloc(sizeof(Deadline) * rLen);

  for(int i = 0; i < lLen; ++i) lTemp[i] = jadwal[low + i];
  for(int i = 0; i < rLen; ++i) rTemp[i] = jadwal[mid + 1 + i];

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || (i < lLen && (lTemp[i].date <= rTemp[j].date) )){
      if((lTemp[i].date == rTemp[j].date) && (strcmp(lTemp[i].name, rTemp[j]. name) <= 0)){
        jadwal[k] = lTemp[i++];
      } else if((lTemp[i].date == rTemp[j].date) && (strcmp(lTemp[i].name, rTemp[j]. name) > 0)) jadwal[k] = rTemp[j++];
      else jadwal[k] = lTemp[i++];
    } else jadwal[k] = rTemp[j++];
  }
}

void mergeSort(Deadline *jadwal, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(jadwal, low, mid);
    mergeSort(jadwal, mid + 1, high);
    merge(jadwal, low, mid , high);
  }
}

int main(){
  int N;
  scanf("%d", &N); getchar();

  Deadline *jadwal = (Deadline *) malloc(sizeof(Deadline) * N);

  for(int i = 0; i < N; ++i){
    scanf("%s %lld", jadwal[i].name, &jadwal[i].date); getchar();
  }

  mergeSort(jadwal, 0, N-1);

  for(int i = 0; i < N; ++i){
    printf("%s\n", jadwal[i].name);
  }

  return 0;
}