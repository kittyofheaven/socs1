#include <stdio.h>
#include <string.h>

int main(){
  char S[101];
  char P[101];

  scanf("%[^\n]", S); getchar();
  scanf("%[^\n]", P); getchar();

  int Plength = strlen(P);

  int result = 0;

  for(int i = 0; i <= strlen(S) - Plength; ++i){
    char temp[101];
    strncpy(temp, S + i, Plength);
    
    if(strcmp(temp, P) == 0){
      result = 1;
    }
  }
  result ? printf("Yey") : printf("No");
  return 0;
}