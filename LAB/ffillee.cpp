#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[101];
  int price;
  int stock;
} Item;

Item itemList[100];
int itemCounter = 0;

void loadFile(){
  FILE *fp;
  fp = fopen("items.txt", "r");

  if(fp == NULL){
    puts("No file");
    return;
  }
}

void saveFile(){
  
}

void sortByPrice(){

}

int searchById(int id){ // return -1 if not found
  
}

void clearScreen(){
  system("clear");
}

void printMenu(){
  puts("1. Insert New Product");
  puts("2. View Product List");
  puts("3. Delete Product");
  puts("4. Exit");
  printf(">> ");
}

void createMenu(){
  FILE *fp;
  fp = fopen("items.txt", "a");

  if(fp == NULL){
    puts("No file");
    return;
  }

  Item tempItem;
  printf("Input item name : ");
  scanf("%[^\n]", tempItem.name); getchar();
  printf("Input item price : ");
  scanf("%d", &tempItem.price); getchar();
  printf("Input item stock : ");
  scanf("%d", &tempItem.stock); getchar(); 

  fprintf(fp, "%s;%d;%d\n", tempItem.name, tempItem.price, tempItem.stock);
  fclose(fp);
}

void viewMenu(){
  FILE *fp;
  fp = fopen("items.txt", "r");

  if(fp == NULL){
    puts("No file");
    return;
  }

  Item tempItem;
  int count = 0;
  while ((fscanf(fp, "%[^;];%d;%d\n", tempItem.name, &tempItem.price, &tempItem.stock)) != EOF){
    printf("Item no. %d\n", ++count);
    printf("Item name\t: %s\n", tempItem.name);
    printf("Item price\t: %d\n", tempItem.price);
    printf("Item stock\t: %d\n", tempItem.stock);
    puts("=====================");
  }
  fclose(fp);
}

void deleteMenu(){
  FILE *fp;
  fp = fopen("items.txt", "r");

  if(fp == NULL){
    puts("No file");
    return;
  }

  char toDelete[100];
  printf("Input item to delete : ");
  scanf("%[^\n]", toDelete); getchar();

  Item tempItem;
  Item willBeDeleted;
  bool found = false;
  while ((fscanf(fp, "%[^;];%d;%d\n", tempItem.name, &tempItem.price, &tempItem.stock)) != EOF){
    if(strcmp(toDelete, tempItem.name) != 0){
      itemList[itemCounter++] = tempItem; 
    } else {
      if(!found){
        willBeDeleted = tempItem;
        found = true;
      }
    }
  }

  if(found == true){
    FILE *fp =  fopen("items.txt", "w");
    printf("%d\n", itemCounter);
    for(int i = 0; i < itemCounter; ++i){
      printf("%s;%d;%d\n", itemList[i].name, itemList[i].price, itemList[i].stock);
      fprintf(fp, "%s;%d;%d\n", itemList[i].name, itemList[i].price, itemList[i].stock);
    }
    fclose(fp);
  }

  itemCounter = 0;
}

int main(){
  int choice = -1;
  while(1){
    // clearScreen();
    printMenu();
    scanf("%d", &choice); getchar();

    switch (choice)
    {
    case 1:
      createMenu();
      break;
    case 2:
      viewMenu();
      break;
    case 3:
      deleteMenu();
      break;
    case 4:
      return 0;
      break;
    default:
      puts("Please provide valid input(1-4)");
      break;
    }
  }
  return 0;
}