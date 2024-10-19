#include <stdio.h>
#include <string.h>

char palindrome[1001][1001];
int palindromeCount = 0;

int isPalindrome(char str[], int length){
  int start = 0;
  int end = length - 1;
  int isPalindrome = 1;

  while(start < end)
  {
    if(str[start] != str[end]) isPalindrome = 0;
    start++;
    end--;
  }
  return isPalindrome;
}

int isAlreadySeen(char temp[]){
  int alreadySeen = 0;
  for(int i = 0; i < palindromeCount; ++i){
    if(strcmp(palindrome[i], temp) == 0){
      alreadySeen = 1;
      break;
    }
  }

  return alreadySeen;
}

int main(){
  char input[1001];
  char temp[1001];
  scanf("%[^\n]", input);
  int length = strlen(input);

  for(int i = 1; i <= length; ++i){
    for(int j = 0; j <= length - i; ++j){
      strncpy(temp, input + j, i);
      temp[i+1] = '\0';

      if(isPalindrome(temp, strlen(temp)) && isAlreadySeen(temp) == 0){
        strcpy(palindrome[palindromeCount], temp);
        printf("%s\n", temp);
        palindromeCount++;
      }

    }
  }
  printf("%d\n", palindromeCount);
}
