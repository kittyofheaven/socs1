#include <stdio.h>

int main(){
  int countDayInMonth, startDay;
  scanf("%d %d", &countDayInMonth, &startDay);

  puts("Mo|Tu|We|Th|Fr");
  puts("--+--+--+--+--");

  int days = 1;
  while(days <= countDayInMonth){

    if(days < startDay){
      printf("%2c", ' ');
    } else {
      printf("%2d", days);
      days++;
    }

    // print pager atau endline
    if((days % 5 - 1) == 0 && days != 1 ){
      printf("\n");
      days+=2;
    }else{
      printf("|");
    }
  }

  days++;
}