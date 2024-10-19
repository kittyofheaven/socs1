#include <stdio.h>

void revString(int kasus){
  char S[1001];
  scanf("%[^\n]", S); getchar();
  char *ptr = S;
  while(*ptr != '\0'){
    ++ptr;
  }

  printf("Case #%d : ", kasus);
  while(ptr != S){
    --ptr;
    printf("%c", *ptr);
  }
  printf("\n");

  

}

int main(){
  int T;
  scanf("%d", &T); getchar();

  for(int i = 1; i <= T; ++i){
    revString(i);
  }
}