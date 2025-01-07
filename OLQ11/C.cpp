#include <stdio.h>

int customFibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    
    if (n % 3 == 0) {
        return 10;
    }
    
    return customFibonacci(n - 1) + customFibonacci(n - 2);
}

int main() {
    int n = 10;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("%d", customFibonacci(i));
        if(i != n-1) printf(" ");
    }
    printf("\n");
    return 0;
}
