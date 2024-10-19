#include <stdio.h>
#include <string.h>

int inside(char str[], char characters){
  int isInside = 0;
  for(int i = 0; i < strlen(str); ++i){
    if(str[i] == characters) {
      isInside = 1 ; 
      break;
    };
  }
  return isInside;
}

char vowel(char characters){
  char changeA[5] = "ABCD";
  char changeE[5] = "EFGH";
  char changeI[7] = "IJKLMN";
  char changeO[7] = "OPQRST";
  char changeU[7] = "UVWXYZ";

  if(inside(changeA, characters)) characters = 'A';
  else if(inside(changeE, characters)) characters = 'E';
  else if(inside(changeI, characters)) characters = 'I';
  else if(inside(changeO, characters)) characters = 'O';
  else if(inside(changeU, characters)) characters = 'U';

  return characters;
}

void message(int kasus){
  char str[1001];
  scanf("%[^\n]", str); getchar();
  int difference[strlen(str)];
  char temp;
  for(int i = 0; i < strlen(str) ; ++i){
    temp = vowel(str[i]);
    difference[i] = str[i] -  temp;
    str[i] = temp;
  }

  printf("Case #%d:\n", kasus);
  printf("%s\n", str);
  for(int i = 0; i < strlen(str) ; ++i){
    printf("%d",difference[i]);
  }
  printf("\n");

}

int main(){
  int T;
  scanf("%d", &T); getchar();
  for(int i = 1; i <= T; ++i){
    message(i);
  }
}