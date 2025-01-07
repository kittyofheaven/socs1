#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    long long favorable_outcomes = (1 << N) - 1; 
    printf("%lld\n", favorable_outcomes);
    return 0;
}