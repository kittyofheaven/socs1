#include <stdio.h>

int main(){
  char course[5][11];
  int start_hours[5], start_minutes[5], end_hours[5], end_minutes[5];

  for(int i = 0 ; i < 5 ; ++i){
    scanf("%s %d:%d-%d:%d", course[i], &start_hours[i], &start_minutes[i], &end_hours[i], &end_minutes[i]);
  }
  for(int i = 0 ; i < 5 ; ++i){
    printf("%s %02d:%02d-%02d:%02d\n", course[i], start_hours[i]-1, start_minutes[i], end_hours[i]-1, end_minutes[i]);
  }
}