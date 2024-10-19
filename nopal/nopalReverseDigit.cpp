#include <stdio.h>

int main(){
  int digit;
  scanf("%d", &digit);

  int result = 0;
  while (digit > 0)
  {
    result = result * 10 + (digit % 10);
    digit /= 10;
  }
  printf("%d\n", result);
}