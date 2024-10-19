#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    // Sn = n/2 (2a + (n - 1) b)
    unsigned long long result = (N * 100) + (N/2.0 * ((N-1) * 50));
    printf("%lld", result);
    printf("\n");
    return 0;
}