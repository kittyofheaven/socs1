#include <stdio.h>

int main (){
  // while (1 == 2)
  // {
  //   printf("susanto\n");
  // }

  do{
    printf("susanto\n");
  } while (1 == 2);

  int N;
  scanf("%d", &N);

  for(int i = 0 ; i < N ; ++i){
    printf("%d\n", i);
  }
  

}