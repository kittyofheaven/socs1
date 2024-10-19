#include <stdio.h> 

void clever(int kasus){
  long long int A,B;
  scanf("%lld %lld", &A, &B);

  long long sum = 0;
  long long tempA, tempB;
  int count = 1;

  while(A > 0 || B > 0){
    tempA = A % 10;
    A /= 10;
    tempB = B % 10;
    B /= 10;

    sum += ((tempA + tempB) % 10) * count;
    count *= 10;
  }

  printf("Case #%d: %lld\n", kasus, sum);  
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    clever(i);
  }
}