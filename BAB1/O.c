#include <stdio.h>

int main(){
  char words[3][21];
  scanf("%s %s %s", words[0], words[1], words[2]);
  printf("%s %s %s\n", words[2], words[1], words[0]);
}