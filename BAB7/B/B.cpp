#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tanaman
{
  int id;
  char name[41];
} Tanaman;

void merge(Tanaman *setOfTanaman, int low, int mid, int high){
  int leftLength = mid - low + 1;
  int rightLength = high - mid;

  Tanaman *leftTanamanArr = (Tanaman *) malloc(sizeof(Tanaman) * leftLength);
  Tanaman *rightTanamanArr = (Tanaman *) malloc(sizeof(Tanaman) * rightLength);

  for(int i = 0; i < leftLength; ++i) leftTanamanArr[i] = setOfTanaman[i + low];
  for(int i = 0; i < rightLength; ++i) rightTanamanArr[i] = setOfTanaman[i + mid + 1];

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < leftLength && j >= rightLength) || (i < leftLength && (strcmp(leftTanamanArr[i].name, rightTanamanArr[j].name) <= 0))) setOfTanaman[k] = leftTanamanArr[i++];
    else setOfTanaman[k] = rightTanamanArr[j++];
  }

  free(leftTanamanArr);
  free(rightTanamanArr);
}

void mergeSortChar(Tanaman *setOfTanaman, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSortChar(setOfTanaman, low, mid);
    mergeSortChar(setOfTanaman, mid+1, high);
    merge(setOfTanaman, low, mid, high);
  }
}

int main(){
  FILE *fptr;
  fptr = fopen("testdata.in", "r");

  if(fptr == NULL){
    printf("error opening files!\n");
    return 1;
  }

  int N;
  fscanf(fptr, "%d", &N);
  
  int arr[N];

  Tanaman *arrTanaman = (Tanaman *) malloc(sizeof(Tanaman) * N);

  for (int i = 0; i < N; ++i)
  {
    fscanf(fptr, "%d#%[^\n]", &arrTanaman[i].id, arrTanaman[i].name);
  }

  mergeSortChar(arrTanaman, 0, N-1);

  for (int i = 0; i < N; ++i)
  {
    printf("%d %s\n", arrTanaman[i].id, arrTanaman[i].name);
  }

  free(arrTanaman);  // Free the array of pointers
  return 0;
}