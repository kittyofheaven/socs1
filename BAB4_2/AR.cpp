#include <stdio.h>

int main(){

    int banyak, baris;
    scanf("%d %d",&banyak, &baris);

    for(int jumlah = 0; jumlah < banyak; ++jumlah){
      for(int i = 0; i < baris; ++i){
        for(int j = 0; j < baris - i-1; ++j){
          printf(" ");
        }
        for(int j = 0; j < baris - (baris - i - 1); ++j){
          printf("*");
        }
        printf("\n");
      } 
    }
  return 0;
}