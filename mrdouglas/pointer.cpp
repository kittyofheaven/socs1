#include <stdio.h>

int main(){
  int x = 10;

  int *ptr = &x;
  int **ptr_ptr = &ptr;

  printf("x value: %d\n", x);
  printf("x address: %d\n", &x);

  printf("*ptr value: %d\n", *ptr);
  printf("ptr real value: %d\n", ptr);
  printf("ptr address: %d\n", &ptr);

  printf("**ptr_ptr value: %d\n", **ptr_ptr);
  printf("*ptr_ptr value: %d\n", *ptr_ptr);
  printf("ptr_ptr real value: %d\n", ptr_ptr); 
  printf("ptr_ptr address: %d\n", &ptr_ptr);
}