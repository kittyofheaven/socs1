#include <stdio.h>
#include <string.h>

bool isPalindrome(char str[]){
  int start = 0;
  int end = strlen(str) - 1;
  bool isValid = true;
  while(start < end){

    if(str[start] != str[end]) isValid = false; 

    start++;
    end--;
  }

  return isValid;
}

int main(){
  char temp[101];
  scanf("%[^\n]", temp);
  (isPalindrome(temp)) ? printf("Yay\n") : printf("Nay\n");
}