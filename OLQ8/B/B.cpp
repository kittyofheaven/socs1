#include <stdio.h>

int main(){
  FILE *fptr;
  fptr = fopen("testdata.in", "r");

  int N;
  fscanf(fptr,"%d\n", &N);

  char str[10001];
  fscanf(fptr,"%s", str);
  
  int count = 0, temp = 0, max = 0;
  bool lever = false;
  for(int i = 0; i <= N; ++i){
    if(str[i] == '1') count++;
    else if(str[i] == '0' || str[i] == '\0') {
      if(max < count) max = count;
      count = 0;
    }
  }
  printf("%d\n", max);
}