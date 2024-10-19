#include <stdio.h>
#include <string.h>

int romanToInt(char a){
  switch(a){
    case 'I' :
      return 1;
      break;
    case 'V' :
      return 5;
      break;
    case 'X' :
      return 10;
      break;
    case 'L' :
      return 50;
      break;
    case 'C' :
      return 100;
      break;
    case 'D' :
      return 500;
      break;
    case 'M' :
      return 1000;
      break;
  }
  return 0;
}
int main(){
  char s[16];
  scanf("%s", s);
  int curr, next;
  int result = 0;
  for(int i = 0; i < strlen(s); ++i){
    curr = romanToInt(s[i]);
    next = romanToInt(s[i+1]);

    if (curr<next) {
      result -= curr;
    } else {
      result += curr;
    }
  }

  printf("%d\n", result);
}