#include <stdio.h>

int main(){
  int S;
  scanf("%d", &S);
  
  int l = S % 10;
  S/=10; 
  printf("%d\n", S);
  int k =  S % 10 *10;
  S/=10; 
  printf("%d\n", S);
  int j =  S % 10 * 100;
  S/=10; 
  printf("%d\n", S);
  int i =  S % 10 * 1000;

  printf("%d %d %d %d\n", i,j,k,l);

  return 0;
}