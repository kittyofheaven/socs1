#include <stdio.h>

int main() {
    int n1, n2, n3;
    
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    
    int middle_digit1 = (n1 / 10) % 10;
    int middle_digit2 = (n2 / 10) % 10;
    int middle_digit3 = (n3 / 10) % 10;
    
    printf("%d\n", middle_digit1);
    printf("%d\n", middle_digit2);
    printf("%d\n", middle_digit3);

    return 0;
}
