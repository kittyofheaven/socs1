#include <stdio.h>
#include <string.h>

typedef struct 
{
  char shortWord[101];
  char Word[101];
} Translate;

int main(){
  FILE *fp = fopen("testdata.in", "r");
  int T;
  fscanf(fp ,"%d", &T); fgetc(fp);

  Translate arr[T];
  for(int i =0; i < T; ++i){
    fscanf(fp ,"%[^#]#%[^\n]\n", arr[i].shortWord, arr[i].Word);
  }


  int TC;
  char tempS[101];
  char tempW[101][101];
  fscanf(fp ,"%d", &TC); fgetc(fp);
  for(int i =0; i < TC; ++i){
    fscanf(fp, "%[^\n]\n", tempS);
    char *token = strtok(tempS, " ");

    int wordCount = 0;
    while (token != NULL){
      bool found = false;
      for(int a = 0; a < T; ++a){
        if(strcmp(arr[a].shortWord, token) == 0){
          found = true;
          strcpy(tempW[wordCount++], arr[a].Word);
          break;
        }
      }
      if(!found) strcpy(tempW[wordCount++], token);
      token = strtok(NULL, " ");
    }
    
    
    printf("Case #%d:\n", i + 1);
    for (int k = 0; k < wordCount; k++) {
        printf("%s", tempW[k]);
        if(k < wordCount - 1) printf(" ");
    }
    printf("\n");

  }

  // for(int i =0; i < T; ++i){
  //   printf("%s %s\n", arr[i].shortWord, arr[i].Word);
  // }



  return 0;
}
