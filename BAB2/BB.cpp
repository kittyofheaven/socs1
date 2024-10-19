#include <stdio.h>

int main(){
    double N;
    scanf("%lf", &N);
    printf("%.lf\n", N*100 + (N/2 * ((N-1) * 50)));
}