#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// struct Product
// {
//   char productId[17]; 
//   char productName[255]; 
//   char productCategory[50];
//   int productPrice;
//   bool isSpicy;
// };

// struct Product productArray[100];
// GABOLEH PAKE STRUCT DI UTP BOLEHNYA UAP;

// PAKE GLOBAL ARRAY SAJA
char productId[100][17]; 
char productName[100][255]; 
char productCategory[100][50];
int productPrice[100];
int isSpicy[100]; //1 or 0

int productCount = 0;

void printMenu(){
  printf("Select one to proceed\n");
  printf("1. Insert Product\n");
  printf("2. View Product\n");
  printf("3. Update Product\n");
  printf("4. Delete Product\n");
  printf("5. Exit\n");
  printf(">> ");
}

void clearScreen(){
  system("clear");
}

void waitForEnter(){
  printf("Press enter to continue ...\n");
  getchar();
}

// CRUD
void menu1(){ // create
  printf("Insert Product ID : ");
  scanf("%[^\n]", productId[productCount]); getchar();

  printf("Insert Product Name : ");
  scanf("%[^\n]", productName[productCount]); getchar();

  printf("Insert Product Category : ");
  scanf("%[^\n]", productCategory[productCount]); getchar();

  printf("Insert Product Price : ");
  scanf("%d", &productPrice[productCount]); getchar();

  printf("Is Product Spicy? (1 or 0) : ");
  scanf("%d", &isSpicy[productCount]); getchar();

  productCount++;
}
void menu2(){ // read
  for(int i = 0; i < productCount ; ++i){
    printf("No. %d\n", i+1);
    printf("Product ID : %s\n", productId[i]);
    printf("Insert Product Name : %s\n", productName[i]);
    printf("Insert Product Category : %s\n", productCategory[i]);
    printf("Insert Product Price : %d\n", productPrice[i]);
    printf("Is Product Spicy? (1 or 0) : %d\n", isSpicy[i]);
    printf("===============================================\n");
  }
  waitForEnter();
}

void menu3(){ // update
  char tempId[17];
  printf("Insert Product ID : ");
  scanf("%[^\n]", tempId); getchar();
  int index = 0;
  while( strcmp(productId[index], tempId)  != 0) {
    
    if(index == productCount) {
      printf("Product not found!\n");
      waitForEnter();
      break;
    }
    index++;
  }
  
  if(strcmp(productId[index], tempId)  == 0){
    printf("Update Product Name : ");
    scanf("%[^\n]", productName[index]); getchar();

    printf("Update Product Category : ");
    scanf("%[^\n]", productCategory[index]); getchar();

    printf("Update Product Price : ");
    scanf("%d", &productPrice[index]); getchar();

    printf("Update Is Product Spicy? (1 or 0) : ");
    scanf("%d", &isSpicy[index]); getchar();
  }
}

void menu4(){
  char tempId[17];
  printf("Insert Product ID : ");
  scanf("%[^\n]", tempId); getchar();
  int index = 0;
  while( strcmp(productId[index], tempId)  != 0) {
    
    if(index == productCount) {
      printf("Product not found!\n");
      waitForEnter();
      break;
    }
    index++;
  }

  if(strcmp(productId[index], tempId)  == 0){

    for(int i = index; i < productCount - 1; ++i){
      strcpy(productId[i], productId[i+1]);
      strcpy(productName[i], productName[i+1]);
      strcpy(productCategory[i], productCategory[i+1]);
      productPrice[i] = productPrice[i+1];
      isSpicy[i] = isSpicy[i+1];
    }

    productCount--;
    printf("Product deleted succesfully!\n");
    waitForEnter();

  }
}

int nextInput(){
  int input;
  scanf("%d", &input); getchar();
  return input;
}

int main(){
  bool stillRunning = true;
  do
  {
    system("clear");
    printMenu();
    int input = nextInput();

    switch (input)
    {
    case 1:
      clearScreen();
      menu1();
      break;

    case 2:
      clearScreen();
      menu2();
      break;

    case 3:
      clearScreen();
      menu3();
      break;
    
    case 4:
      clearScreen();
      menu4();
      break;

    case 5:
      printf("Goodbye ");
      fflush(stdout);
      for(int i = 0; i < 3; ++i){
        usleep(500000);
        printf(".");
        fflush(stdout);
      }
      printf("\n");
      stillRunning = false;
      break;

    default:
      break;
    }
  
  } while (stillRunning);
  

}