#include <stdio.h>

int main(){
  int N;
  scanf("%d", &N); getchar();
  int x = 0, y = 0;

  char temp[N+1];
  scanf("%s", temp); getchar();

  for(int i =0; i < N ;++i){
    switch(temp[i]){
      case 'p':
        x+=10;
        break;
      case 'o':
        x-=10;
        break;
      case 'u':
        y+=5;
        break;
      case 'q':
        y-=5;
        break;
    }
  }

  printf("%d %d\n", x,y);
  return 0;
}