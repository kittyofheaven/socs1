#include <stdio.h>

void snakeAndLadders(long long int *step){
  switch(*step){
    case 9:
      *step = 21;
      break;
    case 33:
      *step = 42;
      break;
    case 76:
      *step = 92;
      break;
    case 53:
      *step = 37;
      break;
    case 80:
      *step = 59;
      break;
    case 97:
      *step = 88;
      break;
  }
}

int main(){
  int N;
  scanf("%d", &N);
  long long int step = 0, temp;
  for(int i = 0; i < N; ++i){
    scanf("%lld", &temp);
    step+=temp;
    snakeAndLadders(&step);
  }

  printf("%lld\n", step);

}