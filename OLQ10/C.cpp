#include <stdio.h>
#include <string.h>
#include <math.h>

int binarySearch(char arr[10001][101], int low, int high, char *target){
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
  int T;
  scanf("%d", &T); getchar();

  char arr[10001][101];
  for(int i = 0; i < T; ++i){
    scanf("%s", arr[i]); getchar();
  }
  char temp[10001];
  scanf("%s", temp); getchar();

  (binarySearch(arr, 0, T-1, temp) != -1) ? printf("Found\n") : printf("Not Found\n");
}