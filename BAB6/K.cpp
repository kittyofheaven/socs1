#include <stdio.h>

long long int notFibo(int a, int b, int K){
  if(K == 0) return a;
  else if (K == 1) return b;
  else return notFibo(a,b,K-1)+ notFibo(a,b,K-2);
}

int main(){
  int a,b, K;
  scanf("%d %d", &a, &b);
  scanf("%d", &K);
  long long int result = 0;
  result = notFibo(a,b,K);
  printf("%lld\n", result);
  return 0;
}