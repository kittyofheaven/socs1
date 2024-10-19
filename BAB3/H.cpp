#include <stdio.h>

void swap(char *a, char *b){
  char temp = *a;
  *a = *b;
  *b = temp;
}


int main(){
  char A,B,C;
  char arr[3] = {1,2,3};
  scanf("%c %c %c", &A, &B, &C);

  // A B C
  if(A > B ){
    swap(&A, &B);
    swap(&arr[0], &arr[1]);
  }

  if(B > C){
    swap(&B,&C);
    swap(&arr[1], &arr[2]);
  }

  if(A > B){
    swap(&A,&B);
    swap(&arr[0], &arr[1]);
  }

  printf("%d %d %d\n", arr[0], arr[1], arr[2]);
  return 0;
}