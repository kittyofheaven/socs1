#include <stdio.h>

int main(){
  int N;
  scanf("%d", &N);
  int max = 0;
  int arr[1001] = {0};

  int temp;
  for(int i = 0; i < N; ++i){
    scanf("%d", &temp);
    if(temp > max) max = temp;
    arr[temp]++;
  }

  int modus = 0;
  for(int i = 1; i <=max; ++i){
    if(arr[i] > modus) modus = arr[i];
  }

  printf("%d\n", modus);
}