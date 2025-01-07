#include <stdio.h>

long long int teamTreesRecursion(int N, long long int result){
  if(N <= 0){
    return result;
  }

  int temp = 0;
  scanf("%d", &temp);
  result+=temp;

  return teamTreesRecursion(N-1, result);
}

void teamTrees(int kasus){
  int N;
  scanf("%d", &N);
  
  printf("Case #%d: %lld\n", kasus, teamTreesRecursion(N, 0));
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    teamTrees(i);
  }
  return 0;
}