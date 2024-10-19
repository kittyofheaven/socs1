#include <stdio.h>

int main(){
  int N, J, S;

  scanf("%d %d %d", &N, &J, &S);
  int i = 1;
  int count = 0;
  int justify = 0;
  while(i <= N){
    if(justify < S){
      printf("%-3c", ' ');
      justify++;
      count++;
    } else {
      printf("%-3d", i);
      if(count < J-1 && i < N) printf(" ");
      i++;
      count++;
    }    
    if (count == J){
      printf("\n");
      count = 0;
    }
  }
}