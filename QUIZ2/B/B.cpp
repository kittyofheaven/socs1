#include <stdio.h>
#include <string.h>

int main(){
  FILE *fp = fopen("testdata.in", "r");
  int N;
  fscanf(fp, "%d\n", &N);

  char temp[101];
  int page[12] = {0};
  int pageCounter = 1;
  while(fscanf(fp, "%s", temp) != EOF){
    if(strcmp("#", temp) == 0){
      pageCounter++;
    } else {
      page[pageCounter]++;
      // printf("%s %d %d\n", temp, page[pageCounter], pageCounter);
    }
  }

  bool correct = true;
  for(int i = 1; i < pageCounter; ++i){
    if(page[i] < N){
      correct = false;
      printf("page %d: %d word(s)\n", i, page[i]);
    }
  }

  if(correct) printf("The essay is correct\n");
}