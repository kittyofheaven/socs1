#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int id;
  char name[101];
  int price;
  int stock;
} Item;

Item itemList[100];
int itemCounter = 0;

void merge(Item *arr, int low, int mid, int high){
  int lLen = mid - low +1;
  int rLen = high - mid;

  Item lTemp[lLen], rTemp[rLen];
  for(int i = 0; i < lLen; ++i) lTemp[i] = arr[low + i];
  for(int i = 0; i < rLen; ++i) rTemp[i] = arr[mid + 1 + i];
  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || (i < lLen && (lTemp[i].id <= rTemp[j].id))) arr[k] = lTemp[i++];
    else arr[k] = rTemp[j++];
  }
}

void mergeSort(Item *arr, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid , high);
  }
}

void loadFile(){
  FILE *fp;
  fp = fopen("items.txt", "r");

  if(fp == NULL){
    puts("No file");
    return;
  }

  while((fscanf(fp, "%d;%[^;];%d;%d\n", &itemList[itemCounter].id , itemList[itemCounter].name, &itemList[itemCounter].price, &itemList[itemCounter].stock)) != EOF){
    itemCounter++;
  }

  fclose(fp);
}

void saveFile(){
  FILE *fp;
  fp = fopen("items.txt", "w");

  for(int i = 0; i < itemCounter; ++i){
    fprintf(fp, "%d;%s;%d;%d\n", itemList[i].id, itemList[i].name, itemList[i].price, itemList[i].stock);
  }

  fclose(fp);
}

void sortByPrice(){

}

int searchById(int id){ // return -1 if not found
  for(int i = 0; i < itemCounter; i++){
    if(itemList[i].id == id) return i;
  }
  return -1;
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
  // FILE *fp;
  // fp = fopen("items.txt", "a");

  // if(fp == NULL){
  //   puts("No file");
  //   return;
  // }

  Item tempItem;
  tempItem.id = rand() % 1000;
  printf("Input item name : ");
  scanf("%[^\n]", tempItem.name); getchar();
  printf("Input item price : ");
  scanf("%d", &tempItem.price); getchar();
  printf("Input item stock : ");
  scanf("%d", &tempItem.stock); getchar(); 

  itemList[itemCounter++] = tempItem;

  // fprintf(fp, "%s;%d;%d\n", tempItem.name, tempItem.price, tempItem.stock);
  // fclose(fp);
  saveFile();
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
  while ((fscanf(fp, "%d;%[^;];%d;%d\n", &tempItem.id, tempItem.name, &tempItem.price, &tempItem.stock)) != EOF){
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

void updateMenu(){
  int toUpdate;
  printf("Enter item id to update: ");
  scanf("%d", &toUpdate); getchar();
  
  int result = searchById(toUpdate);

  if(result != -1){
    int newPrice;
    printf("Input new price : ");
    scanf("%d", &newPrice); getchar();
    itemList[result].price = newPrice;

    saveFile();
  } else {
    puts("id not found");
  } 
}

int main(){
  srand(time(NULL));
  int choice = -1;
  while(1){
    // clearScreen();
    loadFile();
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