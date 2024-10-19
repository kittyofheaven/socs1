#include <stdio.h>
int count = 0;
int recursion(int A, int B){
  if(A == B) return 1;
  else if (A == 1) return 0;
  else if (A & 1) return recursion((A * 3) + 1, B); // ganjil
  else if ((A & 1) == 0) return recursion(A/2, B); // genap

  return 0;
}

int main(){
  int T;
  scanf("%d", &T);

  int A,B;
  for(int i = 1; i <= T; ++i){
    scanf("%d %d", &A, &B);
    (recursion(A,B)) ? printf("Case #%d: YES\n", i) : printf("Case #%d: NO\n", i);
  }
}