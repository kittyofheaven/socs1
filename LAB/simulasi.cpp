#include <stdio.h>
#include <string.h>

int main(){
  char emailvalidation[10] = "@ti22.com";
  char email[101];
  while(1){
    printf("Enter your email: ");
    scanf("%ss", email); getchar();

    char adaAt = 0;
    int atIndex = -1;
    for(int i = 0; i < strlen(email) ; ++i){ 
      if(email[i] == '@') { // cari @
        adaAt = 1;
        atIndex = i;
        break;
      }
    }

    char temp[100] = "";
    if(adaAt && atIndex >= 5){ // atIndex di 5 biar minimal ada 5 huruf didepan @
      strncpy(temp, email + atIndex, strlen(email) - atIndex);
    }
    printf("%s\n", temp);
    
    if(strcmp(temp, emailvalidation) == 0){
      puts("Email valid!");
      break;
    } else {
      puts("Please enter valid email!");
    }
  }
  
  
}