#include <stdio.h>

void swap(long long int *a, long long int *b){
  long long int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(long long int *arr, int low, int high){
  int pivot = arr[high];
  int i = low - 1;

  for(int j = low; j < high; ++j){
    if(arr[j] < pivot){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  i++;
  swap(&arr[i], &arr[high]);
  return i;
}

void quickSort(long long int *arr, int low, int high){
  if(low < high){
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }
}

void ilys(int kasus){
  int N;
  scanf("%d", &N);
  long long int arr[N];
  long long int sum = 0;
  for(int i = 0; i < N; ++i){
    scanf("%lld", &arr[i]);
    sum += arr[i];
  }

  double mean = ((double) sum) / ((double) N);

  quickSort(arr, 0, N-1);
  // for(int i = 0; i < N; ++i){
  //   printf("%lld ", arr[i]);
  // }

  double median;
  if(N & 1){
    median = (double) arr[N/2];
  } else {
    median = (((double)arr[N/2]) + ((double)arr[N/2-1])) / 2;
  } 

  printf("Case #%d:\n", kasus);
  printf("Mean : %.2lf\n", mean);
  printf("Median : %.2lf\n", median);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i<=T; ++i){
    ilys(i);
  }
  return 0;
}