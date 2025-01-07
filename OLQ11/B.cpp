#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct{
  char name[11];
  int RR;
} Balorant;

void merge(Balorant *arr, int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  Balorant lTemp[lLen], rTemp[rLen];
  for(int i = 0; i < lLen; ++i) lTemp[i] = arr[low+i];
  for(int i = 0; i < rLen; ++i) rTemp[i] = arr[mid+1+i];

  for(int i = 0, j =0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || ((i < lLen) && (lTemp[i].RR > rTemp[j].RR))) arr[k] = lTemp[i++];
    else if (j < rLen && (i >= lLen || lTemp[i].RR < rTemp[j].RR)) arr[k] = rTemp[j++];
    else {
      if(strcmp(lTemp[i].name, rTemp[j].name) <= 0) arr[k] = lTemp[i++];
      else arr[k] = rTemp[j++];
    }
  }
}

void mergeSort(Balorant *arr, int low, int high){
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

  Balorant ranks[N];
  long long int RRsum = 0;
  for(int i = 0; i < N; ++i){
    scanf("%d %[^\n]", &ranks[i].RR, ranks[i].name); getchar();
    RRsum += ranks[i].RR;
  }

  double mean = (double)RRsum / (double)N;

  mergeSort(ranks, 0, N-1);

  for(int i = 0; i < N; ++i){
    long long int selisih = floor((double)ranks[i].RR - mean);

    if(ranks[i].RR >=0 && ranks[i].RR <= 200){
      printf("Ascend ");
    } else if (ranks[i].RR >=201 && ranks[i].RR <= 350){
      printf("Mortal ");
    } else if (ranks[i].RR >=351 && ranks[i].RR <= 500){
      printf("Radial ");
    }

    printf("%d %lld %s\n", ranks[i].RR, selisih, ranks[i].name);
  }
}