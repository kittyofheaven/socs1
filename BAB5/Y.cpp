#include <stdio.h>

void swap(char arr[], int indexA, int indexB){
  int temp;
  temp = arr[indexA];
  arr[indexA] = arr[indexB];
  arr[indexB] = temp;
}


void secretCode(int kasus){
  int Q;
  char S[1001];

  scanf("%d %[^\n]", &Q, S); getchar();

  int indexA = -1, indexB = -1;
  for(int i = 0; i < Q; ++i){
    scanf("%d %d", &indexA, &indexB); getchar();

      indexA --;
      indexB --;
      while(indexA < indexB){
        swap(S, indexA, indexB);
        indexA++;
        indexB--;
      }

  }

  printf("Case #%d: %s\n", kasus, S);
}


int main(){
  int T;
  scanf("%d", &T); getchar();

  for(int i = 1; i <= T; ++i ){
    secretCode(i);
  }
}