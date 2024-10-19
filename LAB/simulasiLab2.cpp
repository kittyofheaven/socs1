#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char RunnerName[100][101];
int RunnerGender[100];
char RunnerTrackCategory[100][101];
int DoorPrizeNumber[100];
int RunnerCount = 0;

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

int ynValidation(){
  char temp;

  while(1){
    printf("Do you wish to continue this action: ");
    scanf("%c", &temp); getchar();
    if(temp == 'y' || temp == 'Y'){
      return 1;
    } else if(temp == 'n' || temp == 'N'){
      return 0;
    } else {
      puts("Please input y or n!");
    }
  }
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

void inputName( char name[] ){
  char temp[100];
  char mrVld[4] = "Mr.";
  char msVld[4] = "Ms.";

  while(1){
    printf("Input runner name : ");
    scanf("%[^\n]", temp); getchar();

    if(strlen(temp) < 5 || strlen(temp) > 25){
      puts("Please input valid name length between 5-25!");
      continue;
    }

    if(strncmp(mrVld, temp, strlen(mrVld)) == 0 || strncmp(msVld, temp, strlen(msVld)) == 0){
      break;
    }
    else {
      puts("Please input valid name with Mr. or Ms.");      
    }
  }

  strcpy(name, temp);
}

void inputCategory( char cat[] ){
  char temp[100];
  char category[3][11] = {"Normal", "Moderate", "Super"};

  while(1){
    printf("Input Runner Category : ");
    scanf("%[^\n]", temp); getchar();

    if(strcmp(temp, category[0]) == 0 || strcmp(temp, category[1]) == 0 || strcmp(temp, category[2]) == 0){
      break;
    }
    else {
      puts("Please input valid category (Normal, Moderate, Super)");      
    }
  }

  strcpy(cat, temp);
}

void inputGender( int *gender ){
  int temp;

  while(1){
    printf("Input Runner Gender : ");
    scanf("%d", &temp); getchar();

    if(temp == 0 or temp == 1){
      break;
    }
    else {
      puts("Please input valid gender (1 for male, 0 for female)");      
    }
  }

  *gender = temp;
}



void createRunner(){
  clearScreen();
  inputName(RunnerName[RunnerCount]);
  inputGender(&RunnerGender[RunnerCount]);
  inputCategory(RunnerTrackCategory[RunnerCount]);

  runnerDoorPrizeNumber(&DoorPrizeNumber[RunnerCount]);

  if(ynValidation()) {
    puts("Runner created successfully!");
    RunnerCount++;
  } else {
    puts("Create runner canceled!");
  }
  pauseConsole();
}

void view10Runner(){
  clearScreen();
  if(RunnerCount == 0) {
    puts("Empty runner list!");
    pauseConsole();
    return;
  }

  for(int i = RunnerCount - 1; i > RunnerCount -11; i--){
    if(i < 0){
      break;
    }

    puts("==================================");
    printf("No : %d\n", i + 1);
    printf("Runner Name : %s\n", RunnerName[i]);
    printf("Runner Gender : %d\n", RunnerGender[i]);
    printf("Runner Category : %s\n", RunnerTrackCategory[i]);
    printf("Runner Door Prize Numver : %d\n", DoorPrizeNumber[i]);
    puts("==================================");
  }

  pauseConsole();
}

void viewAllRunner(){
  if(RunnerCount == 0) {
    puts("Empty runner list!");
    pauseConsole();
    return;
  }

  for(int i = 0; i < RunnerCount ; i++){
    if(i < 0){
      break;
    }

    puts("==================================");
    printf("No : %d\n", i + 1);
    printf("Runner Name : %s\n", RunnerName[i]);
    printf("Runner Gender : %d\n", RunnerGender[i]);
    printf("Runner Category : %s\n", RunnerTrackCategory[i]);
    printf("Runner Door Prize Number : %d\n", DoorPrizeNumber[i]);
    puts("==================================");
  }
}

void getDoorPrizeWinner(){
  clearScreen();
  if(RunnerCount == 0) {
    puts("Empty runner list!");
    pauseConsole();
    return;
  }

  int winnerIndex = rand() % RunnerCount;
  
  puts("DOOR PRIZE WINNER !!! ***Drumroll");
  printf("Doorprize number : %d\n", DoorPrizeNumber[winnerIndex]);
  printf("Name : %s\n", RunnerName[winnerIndex]);

  puts("CONGRATULATIONSS !!!!!");
  pauseConsole();
}

void deleteRunner(){
  viewAllRunner();
  if(RunnerCount == 0) {
    return;
  }

  int index;
  while(1){
    printf("Input Runner Number to be deleted : ");
    scanf("%d", &index); getchar();

    if(index >=1 && index <= RunnerCount){
      break;
    } else {
      puts("Please input valid runner number from the list!");
    }
  }

  index--;
  clearScreen();
  puts("You will be deleting this runner :");
  printf("No : %d\n", index + 1);
  printf("Runner Name : %s\n", RunnerName[index]);
  printf("Runner Gender : %d\n", RunnerGender[index]);
  printf("Runner Category : %s\n", RunnerTrackCategory[index]);
  printf("Runner Door Prize Number : %d\n", DoorPrizeNumber[index]);

  if(!ynValidation()){
    puts("Delete operation canceled");
    pauseConsole();
    return;
  }

  for(int i = index; i < RunnerCount -1; ++i){
    strcpy(RunnerName[i], RunnerName[i+1]);
    RunnerGender[i] = RunnerGender[i+1];
    strcpy(RunnerTrackCategory[i], RunnerTrackCategory[i+1]);
    DoorPrizeNumber[i] = DoorPrizeNumber[i+1];
  }

  puts("Delete Succesfull");
  RunnerCount--;
  pauseConsole();
}

int main(){
  srand(time(0));
  int choice; 

  while(1){
    clearScreen();
    printMenu();
    choice = menuInput();

    switch(choice){
      case 1:
        createRunner();
        break;
      case 2:
        view10Runner();
        break;
      case 3:
        deleteRunner();
        break;
      case 4:
        getDoorPrizeWinner();
        break;
      case 5:
        pauseConsole();
        return 0;
        break;
    }
  }

}