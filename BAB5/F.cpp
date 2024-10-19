#include <stdio.h>
#include <string.h>

int main(){

  int T;
  scanf("%d", &T); getchar();

  for(int kasus = 1; kasus <= T; ++kasus){
    char S[100001];
    char SDuplicate[100001] = "";
    scanf("%[^\n]", S); getchar();

    long long count = 0;
    char alreadyInsideArray[26] = {0};
    
    for(int i = 0; i < strlen(S); ++i){
      char temp = S[i];
      // printf("%d\n", temp-'a');

      if(!alreadyInsideArray[temp - 'a']){
        alreadyInsideArray[temp - 'a'] = 1;
        count++;
      }
    }

    printf("Case #%d: ", kasus);
    ((count & 1) == 1) ? printf("Ewwww\n") : printf("Yay\n");
  }
  return 0;
}