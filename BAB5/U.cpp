#include <stdio.h>

void match(int kasus){
  int N, Bibi, Lili;
  scanf("%d", &N);
  int arr[N];
  for(int i = 0; i < N; ++i){
    scanf("%d", &arr[i]);
  }
  scanf("%d %d", &Bibi, &Lili);

  printf("Case #%d : ", kasus);
  if(arr[Bibi-1] > arr[Lili-1]){
    printf("Bibi\n");
  } else if (arr[Bibi-1] < arr[Lili-1]){
    printf("Lili\n");
  } else {
    printf("Draw\n");
  }
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    match(i);
  }
}