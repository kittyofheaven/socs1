#include <stdio.h>

int main() {
    long long int number;
    scanf("%lld", &number);
    int bit1Count = 0;
    while (number > 0) {
      if(number>>=1 & 1) bit1Count++;
    }
    printf("%d\n", bit1Count);
    return 0;
}
