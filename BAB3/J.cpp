#include <stdio.h>

int main(){
  int x,y,k;
  scanf("%d %d %d", &x, &y, &k); // x naik ; y turun

  int jarak1 = x <= k ? k - x : (100 - x) + (100 -k); 
  int jarak2 = y >= k ? y - k : y + k; 

  int seconds;
  if (jarak1 == jarak2) {
    seconds = y-k;
    seconds = seconds < 0 ? seconds * -1 : seconds; // ini buat klo detiknya minus di mutlakin.
  } else {
    seconds = -1; // imposible
  }

  printf("%d\n", seconds);
}