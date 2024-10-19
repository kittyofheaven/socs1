#include <stdio.h>
#include <string.h>

void playingWithString(int kasus){
  char str[1001];
  int M;
  scanf("%[^\n]", str); getchar();
  scanf("%d", &M); getchar();

  for(int i = 0; i < M; ++i){
    char tempA, tempB;
    scanf("%c %c", &tempA, &tempB); getchar();
    for(int j = 0; j < strlen(str); ++j){
      if(str[j] == tempA) str[j] = tempB;
    }
  }

  printf("Case #%d: %s\n", kasus, str);

}

int main(){
  int T;
  scanf("%d", &T); getchar();
  for(int i = 1; i <= T; ++i){
    playingWithString(i);
  }
}