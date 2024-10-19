#include <stdio.h>

int main(){
  int baris;
  scanf("%d",&baris);

  int barisDiamond = (baris & 1) ? baris / 2 + 1 : baris / 2;
  for(int i = 0; i < ((baris & 1) ? (barisDiamond - 1) : (barisDiamond)); ++i){
    for(int j = 0; j < barisDiamond-i - 1; ++j){
      printf(" ");
    }

    for(int j = 0; j < barisDiamond - (barisDiamond - i - 1); ++j){
      printf("*");
    }

    for(int j = 0; j < barisDiamond - (barisDiamond - i); ++j){
      printf("*");
    }

    printf("\n");
  }
  // printf("\n");

  for(int i = 0; i < barisDiamond; ++i){
    for(int j = 0; j < barisDiamond - (barisDiamond - i); ++j){
      printf(" ");
    }
    for(int j = 0; j < barisDiamond-i; ++j){
      printf("*");
    }
    for(int j = 0; j < barisDiamond-i-1; ++j){
      printf("*");
    }
    printf("\n");
  }
}