#include <stdio.h>
#include <string.h>

void charToAscii(int kasus){
  char S[1001];
  scanf("%[^\n]", S); getchar();

  printf("Case %d: ", kasus);
  for(int i = 0; i < strlen(S); ++i){
    printf("%d",S[i]);
    if(i < strlen(S)-1){
      printf("-");
    }
  }
  printf("\n");
}

int main(){
  int T;
  scanf("%d", &T); getchar();

  for(int i = 1; i<=T; ++i){
    charToAscii(i);
  }
}