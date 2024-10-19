#include <stdio.h>

int main(){
  int N = 5;

  for(int j = 1 ; j <= N ; ++j){ // j adalah baris
    for(int k = 1 ; k <= N-j ; ++k){ // dari kolom 1 hingga kolom N-j
      printf(" ");
    }

    for(int l = N-j+1 ; l <= N ; ++l){
      ((l+j) & 1) == 1 ? printf("#") : printf("*");
    }
    printf("\n");
  }
}