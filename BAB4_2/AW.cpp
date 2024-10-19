#include <stdio.h>

int main(){
  
  int T;
  scanf("%d", &T);

  for(int k = 1; k <= T; ++k){

    int N;
    scanf("%d", &N);

    int max = 0; //4
    int hadiah = 0; //3
    for(int i = 0; i < N; ++i){
      int nilai;
      scanf("%d", &nilai);
      if(nilai > max){
        max = nilai;
        hadiah = 1;
      } else if(nilai == max){
        hadiah += 1;
      } 
    }

    printf("Case #%d: %d\n", k, hadiah);


  }
  return 0;
}