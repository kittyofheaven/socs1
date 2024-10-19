#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char ProductId[100][17];
char ProductName[100][21]; // 20-21 chars
char ProductCategory[100][11]; // Harus antara [Sweet, Sour, Balanced] dan harus sesuai dengan huruf besar/kecil (case sensitive)
int ProductPrice[100]; // Harus antara 7000 - 19000 (inklusif)
int ProductCount = 0;

void printMenu(){
  printf("1. Create\n");
  printf("2. View\n");
  printf("3. Update\n");
  printf("4. Delete\n");
  printf("5. Exit\n");
}

void clearScreen(){
  system("clear");
}

void pauseConsole(){
  printf("Press ENTER to Continue...");
  getchar();
}

void randomId(char id[]){
  char choice = -1;
  char character;
  char symboList[6] = "!@#$&";
  for(int i = 0; i < 16; ++i){
    choice = rand() % 3;
    switch (choice)
    {
    case 0: //a-z
      character = rand() % 26 + 97;
      id[i] = character;
      break;
    case 1: //A-Z
      character = rand() % 26 + 65;
      id[i] = character;
      break;
    case 2: // symbol
      character = rand() % 5;
      id[i] = symboList[character];
      break;
    }
  }
  id[16] = '\0';
}

int menuInput(){
  int choice;
  while(1){
    printf(">> ");
    scanf("%d", &choice); getchar();

    if(choice >= 1 && choice <= 5){
      break;
    } else {
      printf("Please input value between 1-4!\n");
    }
  }
  return choice;
}

int yesNoValidation(){
  char confirmation;
  while (1)
  {
    printf("Do you wish to continue this action (y/n): ");
    scanf("%c", &confirmation); getchar();
    if(confirmation == 'y' || confirmation == 'Y'){
    return 1;
    } else if (confirmation == 'n' || confirmation == 'N'){
      return 0;
    } else {
      printf("Please input value between y / n !\n");
    }
  }
}

void inputProductName( char productName[] ){
  char temp[101];
  while(1){
    printf("Input product name : ");
    scanf("%[^\n]", temp); getchar();

    if(strlen(temp) < 5 || strlen(temp)>20){
      printf("Product name length must be between 5 - 20\n");
    } else {
      strcpy(productName, temp);
      break;
    }
  }
}

void inputProductCategory( char productCategory[] ){
  char temp[101];
  while(1){
    printf("Input product category [Sweet, Sour, Balanced] : ");
    scanf("%[^\n]", temp); getchar();

    if((strcmp(temp, "Sweet") == 0) || (strcmp(temp, "Sour") == 0) || (strcmp(temp, "Balanced") == 0)){
      strcpy(productCategory, temp);
      break;
    } else {
      printf("Product category must between [Sweet, Sour, Balanced] (Case Sensitive)!\n");
    }
  }
}

void inputProductPrice( int *productPrice ){
  int temp;
  while(1){
    printf("Input product price : ");
    scanf("%d", &temp); getchar();

    if(temp >= 7000 && temp <=19000){
      *productPrice = temp;
      break;
    } else {
      printf("Product price must between 7000-19000!\n");
    }
  }
}

void createProduct(){
  clearScreen();
  randomId(ProductId[ProductCount]);
  inputProductName(ProductName[ProductCount]);
  inputProductCategory(ProductCategory[ProductCount]);
  inputProductPrice(&ProductPrice[ProductCount]);

  clearScreen();
  printf("Product Id : %s\n", ProductId[ProductCount]);
  printf("Product Name : %s\n", ProductName[ProductCount]);
  printf("Product Category : %s\n", ProductCategory[ProductCount]);
  printf("Product Price : %d\n", ProductPrice[ProductCount]);

  if(yesNoValidation()){
    printf("New Product succesfully inserted!\n");
    ProductCount++;
  } else {
    printf("Product canceled!\n");
  }
  pauseConsole();
}

void viewProduct(){
  clearScreen();
  if(ProductCount == 0){
    printf("Product is empty!\n");
  } else {
    for(int i = 0; i < ProductCount; ++i){
      printf("No. %d\n", i+1);
      printf("Product Id: %s\n", ProductId[i]);
      printf("Product Name: %s\n", ProductName[i]);
      printf("Product Category: %s\n", ProductCategory[i]);
      printf("Product Price: %d\n", ProductPrice[i]);
      printf("==================================\n");
    }
  }
}

void deleteProduct(){
  int temp;
  if(ProductCount == 0){
    printf("Product is empty!\n");
  } else{
    viewProduct();
    printf("Input product number to be deleted : ");
    scanf("%d", &temp); getchar();

    if(temp > ProductCount || temp < 1){
      printf("Product not found !\n");
    } else {
      if(yesNoValidation()){
        for(int i = temp-1 ; i < ProductCount; ++i){
          strcpy(ProductId[i], ProductId[i+1]);
          strcpy(ProductName[i], ProductName[i+1]);
          strcpy(ProductCategory[i], ProductCategory[i+1]);
          ProductPrice[i] = ProductPrice[i+1];
        }
        ProductCount--;
        printf("Product %d has been succesfully deleted!\n", temp);
      } else {
        printf("Product delete has been canceled!\n");
      }
    }
  }
  pauseConsole();
}

void updateProduct(){
  char tempName[21];
  char tempCategory[11];
  int tempPrice;
  int index;
  
  viewProduct();
  if(ProductCount == 0){
    pauseConsole();
    return;
  }

  while(1){
    printf("Input No of product you want to update: ");
    scanf("%d", &index); getchar();
    if(index < 1 || index > ProductCount){
      printf("Choice not valid !!!\n");
    } else {
      break;
    }
  }

  clearScreen();

  index--;
  inputProductName(tempName);
  inputProductCategory(tempCategory);
  inputProductPrice(&tempPrice);

  clearScreen();
  printf("Product Id : %s\n", ProductId[index]);
  printf("Product Name : %s\n", tempName);
  printf("Product Category : %s\n", tempCategory);
  printf("Product Price : %d\n", tempPrice);

  if(yesNoValidation()){
    strcpy(ProductName[index], tempName);
    strcpy(ProductCategory[index], tempCategory);
    ProductPrice[index] = tempPrice;
  } else {
    printf("Product Update Canceled!\n");
  }

  pauseConsole();
}

int main(){
  srand(time(0));
  int choice;
  while(1){
    clearScreen();
    printMenu();
    choice = menuInput();
    switch (choice)
    {
    case 1:
      createProduct();
      break;
    case 2:
      viewProduct();
      pauseConsole();
      break;
    case 3:
      updateProduct();
      break;
    case 4:
      deleteProduct();
      break;
    case 5:
      if(yesNoValidation()){
        pauseConsole();
        return 0;
      }
      break;
    }
  }
  return 0;
}