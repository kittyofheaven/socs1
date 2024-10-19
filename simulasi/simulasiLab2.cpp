#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char RunnerName[100][101];
int RunnerGender[100];
char RunnerTrackCategory[100][101];

void printMenu(){
  puts("1. Add a runner");
  puts("2. View all runner");
  puts("3. Delete a runner");
  puts("4. Get door prize winner");
  puts("5. Exit");
}

void pauseConsole(){
  puts("Press enter to continue...");
  getchar();
}

void clearScreen(){
  system("clear");
}

int menuInput(){
  int temp;
  while(1){
    printf(">> ");
    scanf("%d", &temp); getchar();
    if(temp <= 5 && temp >= 1) break;
    else {
      puts("Please provide valid input!");
    }
  }

  return temp;
}

void runnerDoorPrizeNumber(int *randNum){
  *randNum = (rand() % 200) + 1;
}

void inputName(){
  char temp[100];
  char mrVld[4] = "Mr.";
  char msVld[4] = "Ms.";

  scanf("%[^\n]", temp); getchar();
  
  strncmp(temp, mrVld);


}
int main(){
  srand(time(0));
  int choice; 

  while(1){
    printMenu();
    choice = menuInput();

    switch(choice){

    }
  }

}