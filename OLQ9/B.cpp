#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char **setOfChar, int low, int mid, int high, int choice){
  int leftLength = mid - low + 1;
  int rightLength = high - mid;

  char **leftCharArr = (char **) malloc(sizeof(char *) * leftLength);
  char **rightCharArr = (char **) malloc(sizeof(char *) * rightLength);
  for(int i = 0; i < leftLength; ++i){
    leftCharArr[i] = (char *) malloc(sizeof(char) * 41 );
  }
  for(int i = 0; i < rightLength; ++i){
    rightCharArr[i] = (char *) malloc(sizeof(char) * 41 );
  }

  for(int i = 0; i < leftLength; ++i) strcpy(leftCharArr[i], setOfChar[i+low]);
  for(int i = 0; i < rightLength; ++i) strcpy(rightCharArr[i], setOfChar[i+mid+1]);

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if(choice == 0){
      if((i < leftLength && j >= rightLength) || (i < leftLength && (strcmp(leftCharArr[i], rightCharArr[j]) <= 0))) strcpy(setOfChar[k], leftCharArr[i++]);
      else strcpy(setOfChar[k], rightCharArr[j++]);
    } else {
      if((i < leftLength && j >= rightLength) || (i < leftLength && (strcmp(leftCharArr[i], rightCharArr[j]) >= 0))) strcpy(setOfChar[k], leftCharArr[i++]);
      else strcpy(setOfChar[k], rightCharArr[j++]);
    }
  }

  for (int i = 0; i < leftLength; ++i) {
    free(leftCharArr[i]);
  }
  free(leftCharArr);

  for (int i = 0; i < rightLength; ++i) {
    free(rightCharArr[i]);
  }
  free(rightCharArr);
}

void mergeSortChar(char **setOfChar, int low, int high, int choice){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSortChar(setOfChar, low, mid, choice);
    mergeSortChar(setOfChar, mid+1, high, choice);
    merge(setOfChar, low, mid, high, choice);
  }
}

int main(){
  int N;
  scanf("%d", &N); getchar();

  char **str = (char **)malloc(sizeof(char *) * N);

  for(int i = 0; i < N; ++i){
    str[i] = (char *)malloc(sizeof(char) * 1001);
  }

  for(int i = 0; i < N; ++i){
    scanf("%[^\n]", str[i]); getchar();
  } 
  int choice;
  scanf("%d", &choice); getchar();
  mergeSortChar(str, 0, N-1, choice);

  for(int i = 0; i < N; ++i){
    printf("%s\n", str[i]);
  }
}