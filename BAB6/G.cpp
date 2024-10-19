#include <stdio.h>
#include <string.h>
bool isPalindrome(char *str, int start, int end){
  if(start >= end) return true;
  else if(str[start] == str[end]) return isPalindrome(str, start+1, end-1);
  else return false;
}

void palindromic(int kasus){
  char str[1001];
  scanf("%[^\n]", str); getchar();
  (isPalindrome(str, 0, strlen(str)-1))? printf("Case #%d: yes\n", kasus) : printf("Case #%d: no\n", kasus);
}

int main(){
  int T;
  scanf("%d", &T); getchar();
  for(int i =1; i <= T; ++i){
    palindromic(i);
  }

  return 0;
}