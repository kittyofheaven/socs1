#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
  char id[9];
  char name[101];
  char category[101];
  int stock;
  double price;
} Gift;

Gift gifts[101];
int giftsCount = 0;

void clear(){
  system("clear");
}

void pause(){
  printf("Press enter to continue...");
  getchar();
}

bool confirmation(){
  char temp;
  while(1){
    printf("Do you wish to continue this action? (y/n): ");
    scanf("%c", &temp); getchar();
    if(tolower(temp) == 'y') return true;
    else if(tolower(temp) == 'n') return false;
    else{
      puts("Input between y / n");
    }
  }
}

void merge(Gift *arr, int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  Gift lTemp[lLen], rTemp[rLen];
  for(int i = 0; i < lLen; ++i) lTemp[i] = arr[low + i];
  for(int i = 0; i < rLen; ++i) rTemp[i] = arr[mid + 1 + i];

  for(int i =0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || ((i < lLen) && lTemp[i].price > rTemp[j].price)) arr[k] = lTemp[i++];
    else if((j < rLen && i >= lLen) || ((j < rLen) && rTemp[j].price > lTemp[i].price)) arr[k] = rTemp[j++];
    else {
      if(strcmp(lTemp[i].name, rTemp[j].name) <= 0) arr[k] = lTemp[i++];
      else arr[k] = rTemp[j++];
    }
  }

}

void mergeSort(Gift *arr, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

void printMenu(){
  puts("1. Add gifts");
  puts("2. View gifts");
  puts("3. Buy gifts");
  puts("4. Exit");
  printf(">> ");
}

void loadFile(){
  FILE *fp = fopen("gifts.txt", "r");

  if (fp == NULL){
    puts("Load file failed");
    return;
  }

  while ((fscanf(fp, "%[^#]#%[^#]#%[^#]#%d#%lf\n", gifts[giftsCount].id, gifts[giftsCount].name, gifts[giftsCount].category, &gifts[giftsCount].stock, &gifts[giftsCount].price)) != EOF){
    giftsCount++;
  }

  fclose(fp);
}

void saveFile(){
  FILE *fp = fopen("gifts.txt", "w");

  if (fp == NULL){
    puts("Save file failed");
    return;
  }

  for(int i = 0; i < giftsCount; ++i){
    fprintf(fp, "%s#%s#%s#%d#%.2lf\n", gifts[i].id, gifts[i].name, gifts[i].category, gifts[i].stock, gifts[i].price);
  }

  fclose(fp);
}

void createId(char *target, char name[101]){
  int last = strlen(name);
  char x1 = name[last-2];
  char x2 = name[last-1];

  sprintf(target, "XMAS%02d%c%c", giftsCount, toupper(x1), toupper(x2));
}

void inputName(char *target){
  char temp[101];
  while (1)
  {
    printf("Input gift name : ");
    scanf("%[^\n]", temp); getchar();

    if(strlen(temp) >= 5 && strlen(temp) <= 25) break;
    else{
      puts("Please input valid name between 5-25 chars");
    }
  }
  strcpy(target, temp);
}

void inputCategory(char *target){
  char temp[101];
  while (1)
  {
    printf("Input gift category : ");
    scanf("%[^\n]", temp); getchar();

    if((strcmp(temp, "Toys") == 0) || (strcmp(temp, "Decorations") == 0) || (strcmp(temp, "Electronics") == 0) || (strcmp(temp, "Clothing") == 0)) break;
    else{
      puts("Please input valid category (Toys, Decorations, Electronics, Clothing)");
    }
  }
  strcpy(target, temp);
}

void inputStock(int *target){
  int temp;
  while (1)
  {
    printf("Input gift stock : ");
    scanf("%d", &temp); getchar();

    if(temp > 0) break;
    else{
      puts("Stock must be more than zero");
    }
  }
  *target = temp;
}

void inputPrice(double *target){
  double temp;
  while (1)
  {
    printf("Input gift price : ");
    scanf("%lf", &temp); getchar();

    if(temp > 0) break;
    else{
      puts("Price must be more than zero");
    }
  }
  *target = temp;
}

void createGift(){
  clear();
  inputName(gifts[giftsCount].name);
  inputCategory(gifts[giftsCount].category);
  inputStock(&gifts[giftsCount].stock);
  inputPrice(&gifts[giftsCount].price);
  createId(gifts[giftsCount].id, gifts[giftsCount].name);

  if(confirmation()){
    giftsCount++;
    puts("New gift successfully created!");
    saveFile();
  } else {
    puts("New gift canceled!");
  }
}

void viewAllGift(){
  if(giftsCount == 0){
    puts("There is no gift yet!");
    pause();
    return;
  }

  for(int i = 0; i < giftsCount; ++i){
    printf("Gifts No %d.\n", i+1);
    printf("Id : %s\n", gifts[i].id);
    printf("Name : %s\n", gifts[i].name);
    printf("Category : %s\n", gifts[i].category);
    printf("Stock : %d\n", gifts[i].stock);
    printf("Price : %.2lf\n", gifts[i].price);
    puts("=========================================");
  }
  pause();
}

void viewSomeGift(){
  if(giftsCount == 0){
    puts("There is no gift yet!");
    pause();
    return;
  }
  char category[101];
  inputCategory(category);
  bool found = false;

  printf("categorical view (%s)\n", category);
  for(int i = 0; i < giftsCount; ++i){
    if(strcmp(category, gifts[i].category) == 0){
      found = true;
      printf("Gifts No %d.\n", i+1);
      printf("Id : %s\n", gifts[i].id);
      printf("Name : %s\n", gifts[i].name);
      printf("Category : %s\n", gifts[i].category);
      printf("Stock : %d\n", gifts[i].stock);
      printf("Price : %.2lf\n", gifts[i].price);
      puts("=========================================");
    }
  }

  if(!found) puts("there is no gift in this category yet.");
  pause();
}

void viewGift(){
  while (1) {
    clear();
    int choice = -1;
    puts("1. View All");
    puts("2. View by Category");
    puts("3. Return to menu");
    scanf("%d", &choice); getchar();

    switch (choice){
    case 1:
      viewAllGift();
      break;
    
    case 2:
      viewSomeGift();
      break;
    
    case 3:
      return;
      break;
    
    default:
      puts("Please insert valid menu 1-3");
      break;
    }

  } 
}

void deleteGift(int index){
  for(int i = index; i < giftsCount-1; ++i){
    gifts[i] = gifts[i+1];
  }
  giftsCount--;
}

void buyGift(){
  puts("Buy GIFTS");
  int stock;
  char name[101];
  inputName(name);

  int index = -1;
  bool found = false;
  for(int i = 0; i < giftsCount; ++i){
    if(strcmp(name, gifts[i].name) == 0){
      index = i;
      found = true;
      break;
    }
  }

  if(!found){
    puts("gift was not found!!!!");
    return;
  }

  printf("Id : %s\n", gifts[index].id);
  printf("Name : %s\n", gifts[index].name);
  printf("Category : %s\n", gifts[index].category);
  printf("Stock : %d\n", gifts[index].stock);
  printf("Price : %.2lf\n", gifts[index].price);

  while (1)
  {
    printf("Input buy stock : ");
    scanf("%d", &stock); getchar();

    if(stock > 0 && stock <= gifts[index].stock) break;
    else{
      puts("Stock must be more than zero and less than stock");
    }
  }

  puts("Succesfully buyed!!!");
  gifts[index].stock -= stock;
  if(gifts[index].stock == 0) {
    deleteGift(index);
  }
  saveFile();
  pause();
}

int main(){
  loadFile();
  while (1) {
    mergeSort(gifts, 0, giftsCount - 1);
    clear();
    int choice = -1;
    printMenu();
    scanf("%d", &choice); getchar();

    switch (choice){
    case 1:
      createGift();
      break;
    
    case 2:
      viewGift();
      break;
    
    case 3:
      buyGift();
      break;
    
    case 4:
      puts("Thankyou!!!");
      return 0;
      break;
    
    default:
      puts("Please insert valid menu 1-4");
      break;
    }
  }
  

  return 0;
}