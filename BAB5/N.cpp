#include <stdio.h>

void Maximum(int kasus){
  int N;
  long long int max1 = -1000001;
  long long int max2 = -1000001;
  scanf("%d", &N);
  long long int arr[N];
  
  char arrFlag[N];
  for(int i = 0; i < N; ++i){
    arrFlag[i] = 0;
  }

  for(int i = 0; i < N; ++i){
    scanf("%lld", &arr[i]);
    if(arr[i] > max1){
      max1 = arr[i];
    }
  }

  for(int i = 0; i < N; ++i){
    if(arr[i] == max1){
      arrFlag[i] = 1;
      break;
    }
  }

  for(int i = 0; i < N; ++i){
    if(arr[i] > max2 && arr[i] <= max1 && (arrFlag[i] == 0)){
      max2 = arr[i];
    }
  }

  printf("Case #%d: %lld\n", kasus, max1+max2);

}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    Maximum(i);
  }
  return 0;
}