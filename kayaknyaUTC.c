#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  char masukkan[10];
  scanf("%s", masukkan);

  for(int i=0 ; i < strlen(masukkan) ;++i){
    if(islower(masukkan[i]) != 0){
      masukkan[i] = toupper(masukkan[i]);
    } else {
      masukkan[i] = tolower(masukkan[i]);
    }
  }
  printf("%s\n", masukkan);

}