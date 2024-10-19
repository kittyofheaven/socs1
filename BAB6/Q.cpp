#include <stdio.h>

int chessBoard[9][9] = {-1};

int rec(int x1, int y1, int x2, int y2, int count){
  // printf("%d %d %d %d\n", x1, y1, x2, y2);
  int moves[10][2] = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};
  if(count >= 6) return -1;
  for(int i = 0; i <8; ++i){
    int newX1 = x1+moves[i][0];
    int newY1 = y1+moves[i][1];

    if(newX1 <= 8 && newX1 > 0 && newY1 <=8 && newY1 >0){
      if(chessBoard[newX1][newY1] == -1 || chessBoard[newX1][newY1] >= count){
        chessBoard[newX1][newY1] = count;
      }
      int result = rec(newX1, newY1, x2, y2, count+1);
      if(result != -1) return result;
    }
  }
  return -1;
}

void horse(int kasus){

  for(int i = 0; i < 9; ++i){
    for(int j = 0; j < 9; ++j){
      chessBoard[i][j] = -1;
    }
  }
  
  char str1[3],str2[3];
  scanf("%s %s", str1, str2); getchar();
  int x1 = str1[0] - 'A' + 1;
  int x2 = str2[0] - 'A' + 1;
  int y1 = str1[1] - '0';
  int y2 = str2[1] - '0';
  int count = rec(x1,y1,x2,y2, 1);

  if(x1 == x2 && y1 == y2) chessBoard[x2][y2] = 0;

  printf("Case #%d: %d\n", kasus, chessBoard[x2][y2]);
}

int main(){
  int T;
  scanf("%d", &T); getchar();  
  for(int i = 1; i<= T; ++i){
    horse(i);
  }
  return 0;
}