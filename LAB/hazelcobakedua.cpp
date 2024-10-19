#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char productId[100][17];
char productName[100][101];
char productCategory[100][101];
int productPrice[100];
int isSpicy[100];
int productCount = 0;

void pauseConsole(){
  printf("Press enter to continue...\n");
  getchar();
}

void clearConsole(){
  system("clear");
}

void printMenu(){
  printf("1. Create Menu\n");
  printf("2. View Menu\n");
  printf("3. Update Menu\n");
  printf("4. Delete Menu\n");
  printf("5. Exit\n");
}

int getMenuInput(){
  int temp;
  while(1){
    printf(">> ");
    scanf("%d", &temp); getchar();

    if(temp < 1 || temp > 5){
      printf("Please input valid option (1-4)\n");
    } else {
      break;
    }
  }
  return temp;
}

void randomId(char id[]){
  int choice;
  int character;
  char symbolList[6] = "!@#$&";

  for(int i = 0; i < 16 ; ++i){
    choice = rand() % 4;
    switch(choice){
      case 0:
        character = (rand() % 26) + 'a';
        id[i] = character;
        break;
      case 1:
        character = (rand() % 26) + 'A';
        id[i] = character;
        break;
      case 2:
        character = (rand() % 10) + '0';
        id[i] = character;
        break;
      case 3:
        character = rand() % 5;
        id[i] = symbolList[character];
        break; 
    }
  }
  id[16] = '\0';  
}

void insertProductName(int index){
  char temp[101];
  while(1){
    printf("Insert Product Name: ");
    scanf("%[^\n]", temp); getchar();
    if(strlen(temp) > 10 || strlen(temp) < 5){
      printf("Please input name between 5-10 characters\n");
    } else {
      break;
    }
  }
  strcpy(productName[index],temp);
}

void insertProductCategory(int index){
  char temp[101];
  while(1){
    printf("Insert Product Category [Drink, Dessert, Main]: ");
    scanf("%[^\n]", temp); getchar();
    if((strcmp(temp,"Drink") == 0) || (strcmp(temp,"Dessert") == 0) || (strcmp(temp,"Main") == 0) ){
      break;
    } else {
      printf("Please input category between [Drink, Dessert, Main] (Case sensitive)\n");
    }
  }
  strcpy(productCategory[index], temp);
}

void insertProductPrice(int index){
  int temp;
  while (1)
  {
    printf("Insert Product Price: ");
    scanf("%d", &temp); getchar();
    if(temp < 500 || temp > 12000){
      printf("Price must between 500-12000\n");
    } else {
      break;
    }
  }

  productPrice[index] = temp;
}

void insertIsSpicy(int index){
  int temp;
  while (1)
  {
    printf("Is Product Spicy: ");
    scanf("%d", &temp); getchar();
    if(temp !=0 && temp != 1){
      printf("isSpicy must between 0 or 1\n");
    } else {
      break;
    }
  }
  isSpicy[index] = temp;
}

void createProduct(){
  randomId(productId[productCount]);
  insertProductName(productCount);
  insertProductCategory(productCount);
  insertProductPrice(productCount);
  insertIsSpicy(productCount);

  char confirmationChar;
  while (1)
  {
    printf("Are you sure want to insert this product y/n: ");
    scanf("%c", &confirmationChar); getchar();

    if(confirmationChar == 'y'){
      printf("product succesfully inserted!\n");
      productCount++;
      break;
    } else if (confirmationChar == 'n'){
      printf("product not inserted!\n");
      break;
    } else {
      printf("%c\n", confirmationChar);
      printf("Input must be either y or n (Case sensitive)\n");
    }
  }
  pauseConsole();
}

void viewProduct(){
  clearConsole();
  for(int i = 0; i < productCount; ++i){
    printf("Product No: %-2d\n", i+1);
    printf("Product ID: %-2s\n", productId[i]);
    printf("Product Name: %-2s\n", productName[i]);
    printf("Product Category: %-2s\n", productCategory[i]);
    printf("Product Price: %-2d\n", productPrice[i]);
    printf("Is Product Spicy: %-2d\n", isSpicy[i]);
    printf("=================================\n");
  }
  pauseConsole();
}

void updateProduct(){
  clearConsole();
  char tempId[17];
  printf("Insert product ID: ");
  scanf("%[^\n]", tempId); getchar();

  int index = 0;
  while(index < productCount){
    if(strcmp(tempId, productId[index]) == 0){
      break;
    }
    index++;
  }

  if(index >= productCount){
    printf("Product not found\n");
  } else {
    insertProductName(index);
    insertProductCategory(index);
    insertProductPrice(index);
    insertIsSpicy(index);
    printf("Product succesfully updated!\n");
  }
  pauseConsole();
}

void deleteProduct(int index){
  for(int i = index; i < productCount-1; ++i){
      strcpy(productId[i],productId[i+1]);
      strcpy(productName[i],productName[i+1]);
      strcpy(productCategory[i],productCategory[i+1]);
      productPrice[i] = productPrice[i+1];
      isSpicy[i] = isSpicy[i+1];
  }
}

void deleteProductMenu(){
  clearConsole();
  char tempId[17];
  printf("Insert product ID: ");
  scanf("%[^\n]", tempId); getchar();

  int index = 0;
  while(index < productCount){
    if(strcmp(tempId, productId[index]) == 0){
      break;
    }
    index++;
  }

  if(index >= productCount){
    printf("Product not found\n");
  } else {
    deleteProduct(index);
    printf("Product succesfully deleted!\n");
    productCount--;
  }
  pauseConsole();
}


int main(){
  srand(time(0));
  int choice = 0;
  while(1){
    clearConsole();
    printMenu();
    choice = getMenuInput();

    switch(choice){
      case 1:
        createProduct();
        break;
      case 2:
        viewProduct();
        break;
      case 3:
        updateProduct();
        break;
      case 4:
        deleteProductMenu();
        break;
      case 5:
        return 0;
        break;
    }
  }

  // printf("%d %d\n", 'a', 'z');
  // printf("%d %d\n", 'A', 'Z');
  // printf("%d %d\n", '0', '9');

  return 0;
}