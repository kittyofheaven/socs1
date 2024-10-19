#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomId(char arr[]){

  srand(time(0));
  for(int i = 0; i < 16; ++i){
    char symbol[6] = "!@#$%";
    int randCase = rand() % 3;
    int randChar = -1;
    switch (randCase)
    {
      case 0: // a-z
        randChar = (rand() % 26) + 97;
        arr[i] = randChar;
        break;

      case 1: // A-Z
        randChar = (rand() % 26) + 65;
        arr[i] = randChar;
        break;

      case 2: // 0-9
        randChar = (rand() % 10) + 48;
        arr[i] = randChar;
        break;
      
    }
  }

  // arr[17] = '\0';
}

int main(){
  // printf("%d %d\n",'a', 'z'); // 97 - 122 a-z
  // printf("%d\n", 'z' - 'a');
  // printf("%d %d\n",'A', 'Z'); // 65 - 90 A-Z
  // printf("%d\n", 'Z' - 'A');
  // printf("%d %d\n", '0', '9'); // 48 -57
  // printf("%d\n", '9' - '0');

  char ID[17];
  randomId(ID);

  printf("%s\n", ID);
}