#include <stdio.h>

int main(){
  int N, max, min;
  scanf("%d", &N);

  for(int i = 0; i < N; ++i){
    int temp;
    scanf("%d", &temp);
    if(i == 0){
      max = temp;
      min = temp;
    }

    if(temp > max) max = temp;
    else if (temp < min) min = temp;
  }

  printf("min : %d\nmax: %d\n", min, max);
  return 0;
}