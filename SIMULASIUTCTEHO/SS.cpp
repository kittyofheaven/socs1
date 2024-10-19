#include <stdio.h>
#include <math.h>

int main(){
  int n;
  scanf("%d", &n);

  int apalah[n];
  int banyakCase = pow(2,n);
  int arrFlag[banyakCase+1][n];


  for(int i = 0; i < n; ++i){
    scanf("%d", &apalah[i]);
  }

  // for(int i = 0; i < n; ++i){
  //   printf("%d ", apalah[i]);
  // }

  for(int i = 0; i <= banyakCase; ++i){
    for(int j = 0; j < n; ++j){
      arrFlag[i][j] = (i>>j) & 1;
    }
  }
  // printf("\n%d asdawd\n", apalah[1]);


  for(int i = 0; i <= pow(2,n); ++i){
    int count = 0;
    for(int j = 0; j < n; ++j){
      // printf("%d ", arrFlag[i][j]);
      if(arrFlag[i][j] == 1) printf("%d ", apalah[j]);
      count ++;
    }
    printf("\n");
  }
}