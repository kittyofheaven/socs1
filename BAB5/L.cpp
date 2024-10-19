#include <stdio.h>

int main(){
  int N;
  scanf("%d", &N);
  int index[N];
  int arr[N];

  for(int i = 0; i < N; ++i){
    scanf("%d", &index[i]);
  }

  for(int i = 0; i < N; ++i){
    scanf("%d", &arr[index[i]]);
  }

  for(int i = 0; i < N; ++i){
    printf("%d", arr[i]);
    if(i < N-1) printf(" ");
  }
  printf("\n");
}