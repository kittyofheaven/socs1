#include <stdio.h>

int horseRecursion(int x1, int y1, int x2, int y2, int N, int count){
  // printf("%d %d %d %d\n", x1,y1,x2,y2);
  if(x1 == x2 && y1 == y2) return 1;
  if(count >= N) return 0;

  int arr[10][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

  for(int i = 0; i < 8; ++i){
    int newX1 = x1 + arr[i][0];
    int newY1 = y1 + arr[i][1];

    if(newX1 <= 8 && newX1 > 0 && newY1 <=8 && newY1 >0){
      if(horseRecursion(newX1, newY1, x2, y2, N, count + 1)) return 1;
    }
  }
  return 0;
}

void horse(int kasus){
  int N;
  char str1[3], str2[3];
  int x1, y1, x2, y2;
  scanf("%d", &N);
  scanf("%s %s", str1, str2);

  x1 = str1[0] - ('A' - 1);
  x2 = str2[0] - ('A' - 1);
  y2= str2[1] - '0';
  y1 = str1[1] - '0';
  
  // printf("%d %d %d %d", x1, y1, x2, y2);
  if (horseRecursion(x1, y1, x2, y2, 2 * N, 0)) {
        printf("Case #%d: YES\n", kasus);
  } else {
      printf("Case #%d: NO\n", kasus);
  }
}

int main(){
  int T;
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    horse(i);
  }

  return 0;
} 