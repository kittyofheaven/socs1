#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);
  int N[T];
  for(int i = 0 ; i < T; ++i){
    scanf("%d", &N[i]);
  }

  for(int i = 0 ; i < T; ++i){
    printf("Case #%d:\n", i+1);

    for(int j = 1 ; j <= N[i] ; ++j){ // j adalah baris
      for(int k = 1 ; k <= N[i]-j ; ++k){ // dari kolom 1 hingga kolom N[i]-j
        printf(" ");
      }

      for(int l = N[i]-j+1 ; l <= N[i] ; ++l){
        ((l+j) & 1) == 1 ? printf("#") : printf("*");
      }
      printf("\n");
    }
  }
  return 0;
}