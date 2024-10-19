#include <stdio.h>
#include <string.h>

// int main(){
//   char str[101];
//   char subString[102];
//   scanf("%s %s", str, subString); getchar();
//   (strstr(str, subString) != NULL) ? printf("Yay\n") : printf("Nay\n");
// }
int main(){
  char str[101];
  char subString[102];
  scanf("%s %s", str, subString); getchar();

  int subStringLen = strlen(subString), count = 0;

  for(int i = 0; i < strlen(str) ; ++i){
    // char temp[101];
    // strncpy(temp, str + i, subStringLen);
    // printf("%s %s\n", temp, subString);
    if (strncmp(subString, str + i, subStringLen) == 0) count ++;
  }

  printf("%d\n", count);
}
// {1,2,3,4}
// "H A Z E L \0"