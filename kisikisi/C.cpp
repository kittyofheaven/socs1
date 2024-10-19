#include <stdio.h>

int main(){
  int N, B;
  scanf("%d %d", &N, &B);
  (((N>>(B-1)) & 1) == 1) ? printf("Menyala\n") : printf("Tidak Menyala\n");
}