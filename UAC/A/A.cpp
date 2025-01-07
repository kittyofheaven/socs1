#include <stdio.h>
#include <string.h>

typedef struct{
  char name[101];
  char password[21];
} Databases;

// ABCDEFG
void translate(char *translate){
  int diff = 1;
  bool minus = false;
  int len = strlen(translate);

  for(int i = 0; i < len; ++i){

    if(minus){
      translate[i] = translate[i] - diff;
      minus = false;
    }
    else {
      translate[i] = translate[i] + diff;
      minus = true;
    }

    diff += 1;
  }
}

int main(){

  Databases data[100];
  FILE *fp = fopen("testdata.in", "r");

  int N;
  fscanf(fp, "%d\n", &N);

  for(int i = 0; i < N; ++i){
    fscanf(fp,"%[^#]#%[^\n]\n", data[i].name, data[i].password);
  }

  int T;
  fscanf(fp, "%d\n", &T);
  char temp[21];
  for(int i = 0; i < T; ++i){
    fscanf(fp,"%[^\n]\n", temp);
    translate(temp);
    // printf("%s\n", temp);

    bool found = false;

    for(int j = 0; j < N; ++j){
      if(strcmp(temp, data[j].password) == 0){
        found = true;
        printf("Case #%d: %s\n", i+1, data[j].name);
        break;
      }
    }

    if(!found){
      printf("Case #%d: Tidak Terdaftar\n", i+1);
    }

  }

  

  // char src[21] = "MONEYANDHONEY";
  // translate(src);
  // printf("%s\n", src);

  printf("%d %d diff: %d\n", 'A', 'B', 'B'-'A');
  printf("%d %d diff: %d\n", 'B', '@', '@'-'B');
  printf("%d %d diff: %d\n", 'C', 'F', 'F'-'C');
  printf("%d %d diff: %d\n", 'D', '@', '@'-'D');
  printf("%d %d diff: %d\n", 'E', 'J', 'J'-'E');
  printf("%d %d diff: %d\n", 'F', '@', '@'-'F');
  printf("%d %d diff: %d\n", 'G', 'N', 'N'-'G');



}