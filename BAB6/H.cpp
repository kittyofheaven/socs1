#include <stdio.h>

void fiboStringRec(int N, char a, char b){
  if(N == 0){
    printf("%c", a);
  } else if(N ==1){
    printf("%c",b);
  } else {
    fiboStringRec(N-1, a , b);
    fiboStringRec(N-2,a ,b);
  }
}

void fiboString(int kasus){
  int N;
  char a,b;
  scanf("%d %c %c", &N, &a, &b); getchar();
  printf("Case #%d: ", kasus);
  fiboStringRec(N, a, b);
  printf("\n");
}

int main(){
  int T;
  scanf("%d", &T); getchar();
  for(int i = 1; i <= T; ++i){
    fiboString(i);
  }
  return 0;
}