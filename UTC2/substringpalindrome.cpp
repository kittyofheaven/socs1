#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int length){
  int start = 0;
  int end = length - 1;

  int palindrome = 1;
  while (start < end)
  {
    if(str[start] != str[end]) palindrome = 0;
    start++;
    end--;
  }
  
  return palindrome;
}

int isAlreadyFound(char palindrome[][1001], int count, char temp[]){
  int alreadyFound = 0;
  for(int i = 0; i < count; ++i){
    if(strcmp(palindrome[i], temp) == 0) alreadyFound = 1;
  }
  return alreadyFound;
}

int main(){
  char input[1001];
  scanf("%[^\n]", input);

  int length = strlen(input);
  char palindrome[1001][1001];
  char temp[1001];
  long long count = 0;
  for(int i = 1; i <= length; ++i){
    for(int j = 0; j <= length - i; ++j){
      strncpy(temp, input + j, i);
      temp[i+1] = '\0';

      if(isPalindrome(temp, strlen(temp)) && isAlreadyFound(palindrome, count, temp) ==0 ){
        strcpy(palindrome[count], temp);
        printf("%s\n", temp);
        count++;
      }
    }
  }
  printf("%lld\n", count);
}