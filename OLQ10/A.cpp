#include <stdio.h>
#include <string.h>

typedef struct {
  char name[256];
  int number;
} Range;

int binarySearch(Range *arr, int low, int high, char *target){
  if(low <= high){
    int mid = low + (high-low) / 2;
    if(strcmp(arr[mid].name, target) == 0 ) return mid;
    else if(strcmp(target, arr[mid].name) < 0) {
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

  Range arr[T];
  
  for(int i = 0; i < T; ++i){
    scanf("%s %d", arr[i].name, &arr[i].number); getchar();
  }

  int M;
  scanf("%d", &M);
  char temp[256], temp1[256];
  for(int i = 0; i < M; ++i){
    scanf("%s %s", temp, temp1); getchar();
    int index = binarySearch(arr, 0, T-1, temp);
    int index1 = binarySearch(arr, 0, T-1, temp1);

    if(strcmp(temp, temp1) == 0){
      printf("not valid\n");
    } else if(index == -1 || index1 == -1){
      printf("not found\n");
    } else{
      int result = ((arr[index].number - arr[index1].number) > 0) ? arr[index].number - arr[index1].number : arr[index1].number - arr[index].number;
      int selisih = ((index1-index) > 0) ? index1-index : index - index1;
      printf("%d %d\n", result, selisih);
    }
  }
}