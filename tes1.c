#include <stdio.h>

int main(){

  int size = 4;

  
  int b = size;
  for(int i = 0 ; i < size ; i++){
    for ( int j = 0; j < b; j++)
    { 
  
      printf("*");
    }
    b--;
    printf("\n");
  }
}