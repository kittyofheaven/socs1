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
  int N;
  scanf("%d", &N);

  long long int arr[N];
  for(int i = 0; i < N; ++i){
    scanf("%lld", &arr[i]);
  }

  mergeSort(arr, 0, N-1);
  int mid = (N & 1) ? (N/2)+1 : (N/2)+1;
  // printf("%d\n",mid);

  for(int i = mid; i < N; ++i){
    printf("%lld", arr[i]);
    if(i < N-1){
      printf(" ");
    }
  }
  printf("\n");

  return 0;

}