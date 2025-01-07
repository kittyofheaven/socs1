#include <stdio.h>
int main(){
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    int temp = -1;
    scanf("%d", &temp);
    if(temp == 1){
      printf("not easy\n");
      return 0;
    }
  }
  printf("easy\n");
  return 0;
}