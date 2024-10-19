#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
  int maxcount;
  scanf("%d", &maxcount);

  srand(time(NULL));

  int streakCounter = 0;
  int totalCoinThrow = 0;
  do{
    // angka = 1, gambar = 0;
    int random = rand();
    int coinSide = random & 1;
    printf("%d\n", coinSide);
    
    totalCoinThrow++;
    streakCounter = coinSide == 1 ? streakCounter + 1 : 0;

  } while (streakCounter < maxcount);

  printf("Total Coin Throws : %d", totalCoinThrow);

  return 0;
}