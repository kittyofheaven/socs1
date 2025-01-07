#include <stdio.h>
#include <string.h>
#include <math.h>

int binarySearch(char arr[101][101], int low, int high, char *target){
  if(low <= high){
    int mid = low + (high-low) / 2;
    if(strcmp(arr[mid], target) == 0 ) return mid;
    else if(strcmp(target, arr[mid]) < 0) {
      return binarySearch(arr, low, mid-1, target);
    } else {
      return binarySearch(arr, mid+1, high, target);
    }
  }

  return -1;
}

int main(){
  int T, P;
  scanf("%d", &T); getchar();
  scanf("%d", &P); getchar();

  char arr[101][101];
  for(int i = 0; i < T; ++i){
    scanf("%s", arr[i]); getchar();
  }

  char temp[101];
  scanf("%s", temp); getchar();
  int index = binarySearch(arr, 0, T-1, temp);
  int result = ceil(((double)index + 1.0) / (double)P);
  printf("%d\n", result);
}