#include<stdio.h>

int main(){
  int baris;
  scanf("%d", &baris);

  // kotak
  for(int i = 0; i < baris; ++i){
    for(int j = 0; j < baris; ++j){
      printf("*");
    }
    printf("\n");
  }

  printf("\n");

  // segitiga siku siku kiri
  for(int i = 0; i < baris; ++i){
    for(int j = 0; j < baris - (baris - i - 1); ++j){
      printf("*");
    }
    printf("\n");
  }

  printf("\n");

  // segitiga siku siku terbalik kiri
  for(int i = 0; i < baris; ++i){
    for(int j = 0; j < baris - i; ++j){
      printf("*");
    }
    printf("\n");
  }

  printf("\n");

  // segitiga siku siku kanan
  for(int i = 0; i < baris; ++i){
    for(int j = 0; j < baris - i; ++j){
      printf("#");
    }

    for(int j = 0; j < baris - (baris - i - 1); ++j){
      printf("*");
    }
    printf("\n");
  }

  printf("\n");

  // segitiga siku siku terbalik kanan
  for(int i = 0; i < baris; ++i){
    for(int j = 0; j < baris - (baris - i - 1); ++j){
      printf("#");
    }

    for(int j = 0; j < baris - i; ++j){
      printf("*");
    }
    printf("\n");
  }

  printf("\n");
  

  printf("\n");
  // Segitiga sama kaki di tengah
  for(int i = 0; i < baris; ++i){
    for(int j = 0; j < baris - i -1; ++j){
      printf(" ");
    }

    for(int j = 0; j < baris - (baris - i - 1); ++j){
      printf("*");
    }

    for(int j = 0; j < baris - (baris - i); ++j){
      printf("*");
    }

    printf("\n");
  }

  printf("\n");

  //segitiga sama kaki terbalik
  for(int i = 0; i < baris; ++i){
    for(int j = 0; j < baris - (baris - i); ++j){
      printf(" ");
    }

    for(int j = 0; j < baris - i; ++j){
      printf("*");
    }

    for(int j = 0; j < baris - i - 1; ++j){
      printf("*");
    }

    printf("\n");
  }
  
  printf("\n");
  // diamond
  // seg atas
  int barisDiamond =(baris & 1) ? (baris / 2) + 1 : (baris / 2);
  for(int i = 0; i < ((baris & 1) ? barisDiamond - 1 : barisDiamond); ++i){
    for(int j = 0; j < barisDiamond - i -1; ++j){
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

  for(int i = 0; i < barisDiamond; ++i){
    for(int j = 0; j < barisDiamond - (barisDiamond - i); ++j){
      printf(" ");
    }

    for(int j = 0; j < barisDiamond - i; ++j){
      printf("*");
    }

    for(int j = 0; j < barisDiamond - i - 1; ++j){
      printf("*");
    }

    printf("\n");
  }


}