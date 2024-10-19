#include <stdio.h>

int main(){
  int awal, akhir;
  printf("Input awal dan akhir : ");
  scanf("%d %d", &awal, &akhir);
  printf("Hasil :");
  for(int i = awal; i <= akhir; ++i){
    (i&1) ? printf(" %d",i) : printf(" *");
  }
  printf("\n");
}