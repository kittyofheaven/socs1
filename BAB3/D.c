#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);

  int male[T], female[T];

  for(int i = 0 ; i < T ; ++i){
    scanf("%d %d", &male[i], &female[i]);
  }

  for(int i = 0 ; i < T ; ++i){
    int result = male[i] * female[i];
    ((result & 1) == 1) ? printf("Case #%d: Need more frogs\n", i+1) : printf("Case #%d: Party time!\n", i+1);
  }
  return 0;
}