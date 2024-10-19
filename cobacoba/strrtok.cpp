#include <stdio.h>
#include <string.h>

int main(){
  char theString[1001];
  char theString1[1001];

  scanf("%[^\n]", theString); getchar();

  char *token = strtok(theString, ",");
  while (token != NULL){
    printf("%-3s\n", token);
    token = strtok(NULL, " ");
  }

}