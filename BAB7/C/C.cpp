#include <stdio.h>
#include <string.h>

typedef struct student{
  char id[11];
  char name[21];
} Student;

void merge(Student *studentArr, int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  Student lTemp[lLen];
  Student rTemp[rLen];

  for(int i = 0; i < lLen; ++i) lTemp[i] = studentArr[low + i];
  for(int i = 0; i < rLen; ++i) rTemp[i] = studentArr[mid + 1 + i];

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || (i < lLen && strcmp(lTemp[i].id, rTemp[j].id) <= 0 )) studentArr[k] = lTemp[i++];
    else studentArr[k] = rTemp[j++];
  }
}

void mergeSort(Student *studentArr, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(studentArr, low, mid);
    mergeSort(studentArr, mid + 1, high);
    merge(studentArr, low, mid, high);
  }
}

int main(){
  FILE *fptr;
  fptr = fopen("testdata.in", "r");
  if(fptr == NULL){
    printf("File open failed\n");
    return 1;
  }

  int N;
  fscanf(fptr, "%d", &N);
  fgetc(fptr);

  Student studentArr[N];

  for(int i = 0; i < N; ++i){
    fscanf(fptr, "%s %[^\n]", studentArr[i].id, studentArr[i].name);
    fgetc(fptr);
  }

  mergeSort(studentArr, 0, N-1);

  for(int i = 0; i < N; ++i){
    printf("%s %s\n", studentArr[i].id, studentArr[i].name);
  }

  return 0;
}