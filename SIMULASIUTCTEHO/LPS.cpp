#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]){
  int start = 0;
  int end = strlen(str) - 1;

  int isValid = 1;
  while(start < end){
    if (str[start] != str[end]) isValid = 0;
    start++;
    end--;
  }

  return(isValid);
}

int main(){
  char s[1001];
  char kumpulanPalindrome[1001][1001];
  int kumpulanPalindromeCount = 0;

  scanf("%s", s); getchar();
  int sLen = strlen(s);
  
  //hazel
  char temp[1001];
  for(int i = 1; i <= sLen; ++i){
    for(int j = 0; j <= sLen - i; ++j){
      strcpy(temp,"");
      strncpy(temp, s+j, i);
      if(isPalindrome(temp)){
        // printf("%s\n", temp);
        strcpy(kumpulanPalindrome[kumpulanPalindromeCount], temp);
        kumpulanPalindromeCount++;
      }
    }
  }

  char longestPalindrome[1001];
  char max = 0; 

  for(int i = 0 ; i < kumpulanPalindromeCount; ++i){
    if(strlen(kumpulanPalindrome[i]) > max){
      max = strlen(kumpulanPalindrome[i]);
      strcpy(longestPalindrome, kumpulanPalindrome[i]);
    }
  }

  printf("%s\n", longestPalindrome);
}