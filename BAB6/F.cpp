#include <stdio.h>

void printReverse(char *str){
  if(*str != '\0'){
    printReverse(str + 1);
    printf("%c", *str);
  }
}


void reverseText(int kasus){
  char str[1001];
  scanf("%[^\n]", str); getchar();
  printf("Case #%d: ", kasus);
  printReverse(str);
  printf("\n");
}

int main(){
  int T;
  scanf("%d", &T); getchar();
  for(int i = 1; i <= T; ++i){
    reverseText(i);
  }
  return 0;
}