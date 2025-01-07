#include <stdio.h>
#include <string.h>

int main(){
  FILE *fptr;
  fptr = fopen("testdata.in", "r");
  char baris[100][101];
  int barisCount = 0;
  while (fscanf(fptr, "%s", baris[barisCount]) != EOF) {
    barisCount++;
  }
  fclose(fptr);

  long long int count = 0;
  for (int i = 0; i < barisCount; ++i) {
    int len = strlen(baris[i]);
    if (baris[i][0] == ';') count++;
    for (int j = 0; j < len - 1; ++j) {
      if (baris[i][j] == ';' && baris[i][j + 1] == ';') count++;
    }
  }

  long long int result = 101;
  for (long long int i = 1; i < count; ++i) {
    result = (result * 101) % 1000000007;
  }

  if (count == 0) {
    printf("1\n");
  } else {
    printf("%lld\n", result);
  }

  return 0;
}
