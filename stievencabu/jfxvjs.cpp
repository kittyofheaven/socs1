#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomId(char id[]){
  int choice;
  int character;
  char symbolList[6] = "!@#$%"; //symbolList[0]
  for(int i = 0; i < 16; ++i){
    choice = rand() % 4;

    switch (choice)
    {
    case 0: // kecil
      character = (rand() % 26 )+ 97;
      id[i] = character;
      break;

    case 1: // kapital
      character = (rand() % 26 )+ 65;
      id[i] = character;
      break;

    case 2: // angka
      character = (rand() % 10 )+ 48;
      id[i] = character;
      break;

    case 3: // simbol
      character = rand() % 5;
      id[i] = symbolList[character];
      break;
    }
  }
}

char productId[100][17];
int main(){
  srand(time(0));

  printf("%d %d\n", 'a', 'z'); // 97 - 122 (26)
  printf("%d %d\n", 'A', 'Z'); // 65 - 90 (26)
  printf("%d %d\n", '0', '9'); // 48 - 57 (10)
  printf("%d\n", 'z' - 'a');
  printf("%d\n", 'Z' - 'A'); 
  printf("%d\n", '9' - '0');


  randomId(productId[0]);

  printf("%s\n", productId[0]);

}