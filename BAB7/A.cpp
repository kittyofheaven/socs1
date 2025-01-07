#include <stdio.h>

void merge(long long int arr[], long long int low, long long int mid, long long int high){
  long long int leftLength = mid - low +1;
  long long int rightLength = high - mid;

  long long int tempLeftArr[leftLength];
  long long int tempRightArr[rightLength];

  for(long long int i = 0; i < leftLength ; ++i) tempLeftArr[i] = arr[low+i];
  for(long long int i = 0; i < rightLength ; ++i) tempRightArr[i] = arr[mid + 1 +i];

  for(long long int i = 0, j = 0, k = low; k <= high; ++k){
    if(((i < leftLength) && (j >= rightLength)) || (i < leftLength) && tempLeftArr[i] <= tempRightArr[j]) arr[k] = tempLeftArr[i++];
    else arr[k] = tempRightArr[j++];
  }
}

void mergeSort(long long int arr[], long long int low, long long int high){
  long long int mid = low + (high-low) / 2;
  if(low < high){
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

int main(){
  long long int N;
  scanf("%lld", &N);
  long long int arr[N];
  for(long long int i = 0; i < N ; ++i){
    scanf("%lld", &arr[i]);
  }

  mergeSort(arr, 0, N-1);

  long long int result[1001] = {0};
  long long int resultCount = 0, max = 0;
  for(long long int i = 0; i < N-1 ; ++i){
    if((arr[i+1] - arr[i]) > max){
      max = arr[i+1] - arr[i];
    }
  }

  for(long long int i = 0; i < N-1 ; ++i){
    if(arr[i+1] - arr[i] == max){
      result[resultCount++] = arr[i];
      result[resultCount++] = arr[i+1];
    }
  }

  for(long long int i = 0; i < resultCount; ++i){
    printf("%lld", result[i]);
    if(i<resultCount-1) printf(" ");
  }
  printf("\n");

  return 0;
}