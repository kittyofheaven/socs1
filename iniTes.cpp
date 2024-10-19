#include <stdio.h>

int func(int input) {
  if (input == 1) return 1;
  else if (input % 2 == 0) return func(input / 2);
  else if (input % 2 == 1) return func(input - 1) + func(input + 1);
  else return input;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int tc = 1; tc <= T; tc++) {
    int N;
    scanf("%d", &N);

    printf("Case #%d: ", tc);
    printf("%d\n", func(N));
  }
  return 0;
}