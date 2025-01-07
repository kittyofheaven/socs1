#include <stdio.h>
#include <string.h>

int main(){
  FILE *fp = fopen("testdata.in", "r");
  int T;
  fscanf(fp, "%d", &T); fgetc(fp);

  char nama[101][101];
  for(int i = 0; i < T; ++i){
    fscanf(fp, "%[^\n]\n", nama[i]);
  }

  int N;
  fscanf(fp, "%d", &N); fgetc(fp);
  char temp[101];
  for(int i = 0; i < N; ++i){
    bool found = false;
    fscanf(fp, "%[^\n]\n", temp);
    for(int j = 0; j < T; ++j){
      if(strcmp(temp, nama[j]) == 0){
        printf("%d\n", j);
        found = true;
        break;
      }
    }
    if(!found) printf("-1\n");
  }
}