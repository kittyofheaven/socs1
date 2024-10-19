#include <stdio.h>

void emergencyExit(int kasus){

  int N,K;
  scanf("%d %d", &N, &K); getchar();
  char lorong[N+1];
  scanf("%s", lorong);

  int isUpstair = 0;
  int breath = K;

  for(int i =0; i < N; ++i){
    lorong[i]-=48;
  }

  for(int i = 0; i < N; ++i){

    // printf("i:%d lorong:%d breath:%d\n",i, lorong[i], breath);

    if (i == 1){
      if(lorong[i] == 1){
        isUpstair = isUpstair ? 0 : 1; 
      }
    } else {
      if(!isUpstair){
      breath--;
      } else {
        breath = K;
      }
      if(lorong[i] == 1){
        isUpstair = isUpstair ? 0 : 1; 
      }
      if(breath <= 0){
        printf("Case #%d: Dead\n", kasus);
        break;
      }
    }
  }

  if(breath > 0){
      printf("Case #%d: Alive\n", kasus);
  }

}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    emergencyExit(i);
  }

  return 0;
}