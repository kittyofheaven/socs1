#include <stdio.h>

int main(){
  int startDay, dayCounts;
  scanf("%d %d", &dayCounts, &startDay);

  int day = 1;
  if(startDay == 6){
    day = 3;
    startDay = 1;
  } else if (startDay == 7) {
    day = 2;
    startDay = 1;
  }

  printf("Mo|Tu|We|Th|Fr\n");
	printf("--+--+--+--+--\n");

  for(int i = 1; i <= 25; ++i){
    if (i < startDay || i > dayCounts){
      printf("%2c", ' ');
    } else {
      printf("%2d", day);
      day++;
    }

    if(i % 5 == 0){
      day+=2;
      printf("\n");
    } else {
      printf("|");
    }

    if(i % 5 == 0 && day > dayCounts) break;
  }
}