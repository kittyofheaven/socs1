#include <stdio.h>
#include <string.h>

typedef struct {
  char minimumRealSize[5];
  char maximumRealSize[5];
  int minimumSize;
  int maximumSize;
} Baju;

int translate(char *src){
  if(strcmp(src, "S") == 0) return 1;
  else if(strcmp(src, "M") == 0) return 2;
  else if(strcmp(src, "L") == 0) return 3;
  else if(strcmp(src, "XL") == 0) return 4;
  else if(strcmp(src, "XXL") == 0) return 5;
  else return 0;
}

void merge(Baju *arr, int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  Baju lTemp[lLen], rTemp[rLen];
  for(int i = 0; i < lLen; ++i) lTemp[i] = arr[i + low];
  for(int i = 0; i < rLen; ++i) rTemp[i] = arr[i + mid + 1];
  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || ((i < lLen) && (lTemp[i].minimumSize < rTemp[j].minimumSize || (lTemp[i].minimumSize == rTemp[j].minimumSize && lTemp[i].maximumSize <= rTemp[j].maximumSize)))) arr[k] = lTemp[i++];
    else arr[k] = rTemp[j++];
  }
}

void mergeSort(Baju *arr, int low, int high){
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

  Baju listBaju[N];
  for(int i = 0; i < N; ++i){
    scanf("%s %s", listBaju[i].minimumRealSize, listBaju[i].maximumRealSize); getchar();
    listBaju[i].minimumSize = translate(listBaju[i].minimumRealSize);
    listBaju[i].maximumSize = translate(listBaju[i].maximumRealSize);
  }
  mergeSort(listBaju, 0, N-1);

  for(int i = 0; i < N; ++i){
    printf("%s %s %d %d\n", listBaju[i].minimumRealSize, listBaju[i].maximumRealSize, listBaju[i].minimumSize, listBaju[i].maximumSize);
  }

  int tempMin = 0;
  int tempMax = 0;
  int size = 0;
  int count = 0;

  int arrSize[6] = {0};

  size = listBaju[0].minimumSize;
  // tempMin = listBaju[0].minimumSize;
  tempMax = listBaju[0].maximumSize;
  arrSize[size]++; 
  count++;

  for(int i = 1; i < N; ++i){
    if(listBaju[i].minimumSize <= size && size <= listBaju[i].maximumSize){
      continue;
    } else if (listBaju[i].minimumSize > size && listBaju[i].minimumSize <= tempMax){
      arrSize[size]--; 
      size = listBaju[i].minimumSize;
      arrSize[size]++;
      // tempMin = listBaju[i].minimumSize;
      if(listBaju[i].maximumSize < tempMax) tempMax = listBaju[i].maximumSize;
    } else {
      count++;
      size = listBaju[i].minimumSize;
      arrSize[size]++;
      // tempMin = listBaju[i].minimumSize;
      tempMax = listBaju[i].maximumSize;
    }
  }

  printf("count : %d\n", count);
  printf("Yang dibeli :\n");
  for(int i = 1; i <= 5; ++i){
    printf("%d ", arrSize[i]);
  }
  printf("\n");
}