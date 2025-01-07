#include <stdio.h>
#include <string.h>

typedef struct {
  char NIM[11];
  char name[21];
} Student;

int main(){
  FILE *fp = fopen("testdata.in", "r");
  int N;
  fscanf(fp, "%d\n", &N);

  Student studentList[N];
  for(int i = 0; i < N; ++i){
    fscanf(fp, "%s %[^\n]\n", studentList[i].NIM, studentList[i].name);
  }

  int T;
  fscanf(fp, "%d\n", &T);

  for(int i = 0; i < T; ++i){
    char tempNIM[11];
    fscanf(fp, "%s\n", tempNIM);

    printf("Case #%d: ", i+1);
    bool found = false;
    for(int j = 0; j < N; ++j){
      if(strcmp(tempNIM, studentList[j].NIM) == 0){
        found = true;
        printf("%s\n", studentList[j].name);
      }
    }

    if(!found) printf("N/A\n");
  }

  return 0;
}