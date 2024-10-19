#include <stdio.h>

int main(){
  char A, B;
  scanf("%c %c", &A, &B);
  int asciiA = (int) A;
  int asciiB = (int) B;

  printf("%d\n",asciiA*asciiB);

}