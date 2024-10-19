#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char productID[100][17];
char productName[100][255];
char productCategory[100][255];
int productPrice[100];
int isSpicy[100];
int productCount=0;

void printMenu(){
  system("clear");
  printf("Program management\n");
  puts("===========================");
  printf("1. Insert Product\n");
  printf("2. View Product\n");
  printf("3. Delete Product\n");
  printf("4. Update Product\n");
  printf("5. Exit\n");
  printf(">>");
}

int nextInput(){
  int temp= -1;
  while(1){
    scanf("%d", &temp); getchar();
    if(temp<0 || temp > 5){
      printf("choose number beetwen 1-4\n");
    }else{
      break;
    }
  }
  return temp;
}

void insertProduct(){
  printf("Insert Product ID: ");
  scanf("%[^\n]", productID[productCount]);getchar();
  
  printf("Insert Product Name: ");
  scanf("%[^\n]", productName[productCount]);getchar();

  printf("Insert Product Category: ");
  scanf("%[^\n]", productCategory[productCount]);getchar();

  printf("Insert Product Price: ");
  scanf("%d", &productPrice[productCount]);getchar();

  printf("Insert isSpicy: ");
  scanf("%d", &isSpicy[productCount]);getchar();

  char confirmationInput;
    printf("Are you sure you want to add this product?\n");
    scanf("%c", &confirmationInput); getchar();

  if(confirmationInput != 'y' && confirmationInput != 'n'){
    printf("Input must be between y or n!\n");
  }
  while(confirmationInput != 'y' && confirmationInput != 'n');
  if(confirmationInput =='y'){
    productCount++;
  }
  printf("please ENTER to continue..");
  getchar();
}

void viewProduct(){
  if(productCount == 0){
    puts("Product list is empty!");
  }

  for (int i=0; i<productCount; i++){
    printf("Product No. %d\n", i+1);
    printf("============================\n");
    printf("Product ID: %s\n",productID[i]);
    printf("Product Name: %s\n",productName[i]);
    printf("Product Category: %s\n",productCategory[i]);
    printf("Product Price: %d\n",productPrice[i]);
    printf("Product is Spicy: %d\n",isSpicy[i]);
    printf("=============================\n");
  }

  printf("please ENTER to continue..");
  getchar();
}

void deleteProduct(){
  viewProduct();
  int targetIndex;
  printf("input bumber you want delete: ");
  scanf("%d", &targetIndex); getchar();
  targetIndex -= 1;

  for(int i=targetIndex; i<productCount; i++){
    strcpy(productID[i], productID[i+1]);
    strcpy(productName[i], productName[i+1]);
    strcpy(productCategory[i], productCategory[i+1]);
    productPrice[i]= productPrice[i+1];
    isSpicy[i]=isSpicy[i+1];
    
    productCount--;
  }
}

  

void updateProduct(){
  viewProduct();

  printf("Input Product Number to Update: ");
  int input= nextInput();
  int index = input -1;

  char idTemp[17];
  char nameTemp[255];
  int priceTemp;

  printf("Insert Product ID: ");
  scanf("%[^\n]", &idTemp);getchar();
  
  printf("Insert Product Name: ");
  scanf("%[^\n]", &idTemp);getchar();

  printf("Insert Product Category: ");
  scanf("%[^\n]", &idTemp );getchar();

  printf("Insert Product Price: ");
  scanf("%d", &idTemp);getchar();

  printf("Insert isSpicy: ");
  scanf("%d", &idTemp);getchar();

  char confirmationInput;
    printf("Are you sure you want to add this product?\n");
    scanf("%c", &confirmationInput); getchar();

  if(confirmationInput != 'y' && confirmationInput != 'n'){
    printf("Input must be between y or n!\n");
  }
  while(confirmationInput != 'y' && confirmationInput != 'n');
  
  if(confirmationInput =='y'){
  strcpy(productID[index], idTemp);
  strcpy(productName[index], idTemp);
  strcpy(productCategory[index], idTemp);
  productPrice[index], idTemp;
  isSpicy[index], idTemp;
  }

}


int main(){
  int choice= -1;
  do{ 
    printMenu();
    choice = nextInput();

    switch(choice){

      case 1:
        insertProduct();
      break;

      case 2:
        viewProduct();
        break;

      case 3:
        deleteProduct();
        break;

      case 4:
        updateProduct();
        break;

      case 5:
        return 0;
        break;
    }
    
  }while(1);

  return 0;
}