#include <stdio.h>

int main() {
  int days[] = { 0, 0, 0, 0, 0, 0, 0 };

  int dayCount;
  int startDay;

  int day = 1;

  scanf("%d %d", &dayCount, &startDay);
  int dayNow = startDay;

  printf("Mo|Tu|We|Th|Fr\n");
  printf("--+--+--+--+--\n");

  for (int i = 1; i < dayCount + startDay; i++) {
    if (i >= startDay) {
      printf("%2d", day);
      day++;
    } else {
      printf("  ");
    }

    if (i % 7 == 0) printf("\n");
    else printf("|");

    if (dayNow++ > 6) dayNow = 0;
  }

  printf("\n");

  return 0;
}