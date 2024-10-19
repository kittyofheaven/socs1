#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]){
  int start = 0, end = strlen(str) - 1, valid = 1;
  while(start < end){
    if(str[start] != str[end]) {
      valid = 0;
      break;
    }
    start++;
    end--;
  }
  return valid;
}

int main(){
  char input[1001];
  scanf("%[^\n]", input); getchar();
  int count = 0;

  char palindromeList[5001][1001];
  int countPalindromeList = 0;

  char temp[101];
  for(int i = 1; i <= strlen(input) ; ++i){
    for(int j = 0 ; j <= strlen(input) - i; ++j){
      strncpy(temp, input + j, i);
      if (isPalindrome(temp)) {

        int notYetPalindrome = 1;
        for(int k = 0; k < countPalindromeList; ++k){
          if (strcmp(palindromeList[k], temp) == 0){
            notYetPalindrome = 0;
            break;
          }
        }

        if(notYetPalindrome){
          printf("%s\n", temp);
          strcpy(palindromeList[countPalindromeList], temp);
          countPalindromeList++;
          count++; 
        }
      } 
    }
  }

  printf("%d\n", count);

  return 0;
}