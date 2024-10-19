#include <stdio.h>

void light(int kasus){

  int friends, rooms, many;
  scanf("%d %d %d", &friends, &rooms, &many);

  char lamps[rooms];
  for(int i = 0; i < rooms; ++i){
    lamps[i] = 0;
  }

  int matrix[friends][rooms];
  for(int i = 0; i < friends; ++i){
    for(int j = 0; j < rooms; j++){
      scanf("%d", &matrix[i][j]);
    }
  }

  int friendIndexList[many];
  for(int i = 0; i < many; ++i){
    scanf("%d", &friendIndexList[i]);

    for(int j= 0; j < rooms; ++j){
      if (matrix[friendIndexList[i] - 1][j]){
        lamps[j] = lamps[j] ? 0 : 1; 
      } 
    }
  }

  printf("Case #%d:\n", kasus);
  for(int i = 0; i < rooms; ++i){
    lamps[i] ? printf("YES\n") : printf("NO\n");
  }
}


int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    light(i);
  }
  return 0;
}