#include <stdio.h>

void apakahCukup(int kasus){
  int N;
  scanf("%d", &N);

  int jumlahDibutuhkan[N];
  int jumlahSudahTersedia[N];
  for(int i = 0; i < N; ++i){
    scanf("%d", &jumlahDibutuhkan[i]);
  }
  for(int i = 0; i < N; ++i){
    scanf("%d", &jumlahSudahTersedia[i]);
  }
  printf("Case #%d:", kasus);
  for(int i = 0; i < N; ++i){
    printf(" %d", jumlahDibutuhkan[i] - jumlahSudahTersedia[i]);
  }
  printf("\n");
}

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    apakahCukup(i);
  }

  return 0;
}