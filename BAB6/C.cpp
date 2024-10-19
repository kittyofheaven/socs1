#include <stdio.h>

int ackerman(int m, int n){
  if(m == 0){
    return n + 1;
  } else if(m > 0 && n == 0){
    return ackerman(m-1, 1);
  } else if (m > 0 && n > 0){
    return ackerman(m-1, ackerman(m , n-1));
  } else {
    return -1;
  }
}

int main(){
  int M,N;
  scanf("%d %d", &M, &N);

  printf("result: %d\n", ackerman(M, N));

}