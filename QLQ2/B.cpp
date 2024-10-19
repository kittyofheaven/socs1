#include <stdio.h>

int main(){
  char S[5][11];
  scanf("%s", S[0]);
  scanf("%s", S[1]);
  scanf("%s", S[2]);
  scanf("%s", S[3]);
  scanf("%s", S[4]);

  printf("%10s|%s\n", S[0],S[0]);
  printf("%10s|%s\n", S[1],S[1]);
  printf("%10s|%s\n", S[2],S[2]);
  printf("%10s|%s\n", S[3],S[3]);
  printf("%10s|%s\n", S[4],S[4]);

  return 0;
}