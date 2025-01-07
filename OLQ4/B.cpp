#include <stdio.h>
#include <string.h>

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    int minutes, hours;
    char ampm[3];
    scanf("%d:%d %s", &hours, &minutes, ampm);

    if(hours == 12){
      hours = 00;
    }

    if(strcmp(ampm,"pm") == 0){
      hours +=12; 
    } 

    printf("Case #%d: %02d:%02d\n",i, hours, minutes);

  }

  return 0;
}