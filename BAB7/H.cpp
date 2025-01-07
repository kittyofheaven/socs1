#include <stdio.h>
#include <string.h>

void mergeC(char str[201], int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  char lTemp[lLen+1];
  char rTemp[rLen+1];

  for(int i = 0; i < lLen ; ++i) lTemp[i] = str[low+i];
  lTemp[lLen] = '\0';
  for(int i = 0; i < rLen ; ++i) rTemp[i] = str[mid+1+i];
  rTemp[rLen] = '\0';

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >=rLen) || (i < lLen && lTemp[i] <= rTemp[j])) str[k] = lTemp[i++];
    else str[k] = rTemp[j++];
  }
}

void mergeSortC(char str[201], int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSortC(str, low, mid);
    mergeSortC(str, mid+1, high);
    mergeC(str, low, mid, high);
  }
}

void mergeStr(char str[201][201], int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  char lTemp[lLen+1][201];
  char rTemp[rLen+1][201];

  for(int i = 0; i < lLen ; ++i) strcpy(lTemp[i], str[low+i]);
  for(int i = 0; i < rLen ; ++i) strcpy(rTemp[i], str[mid+1+i]);

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >=rLen) || (i < lLen && (strcmp(lTemp[i], rTemp[j]) >= 0))) strcpy(str[k],lTemp[i++]);
    else strcpy(str[k],rTemp[j++]);
  }
}

void mergeSortStr(char str[201][201], int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSortStr(str, low, mid);
    mergeSortStr(str, mid+1, high);
    mergeStr(str, low, mid, high);
  }
}

int main(){
  int R, C;
  scanf("%d %d", &R, &C); getchar();

  char str[201][201];
  for(int i = 0; i < R; ++i){
    scanf("%[^\n]", str[i]); getchar();
    mergeSortC(str[i], 0, strlen(str[i]) - 1);
  }

  mergeSortStr(str, 0, R-1);


  for(int i = 0; i < R; ++i){
    printf("%s\n", str[i]);
  }
  return 0;
}