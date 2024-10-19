#include <stdio.h>

int main(){

    char name[2][101];
    double T[2];
    int U[2];

    for(int i = 0 ; i < 2 ; i++){
        scanf("%s %lf %d", name[i], &T[i], &U[i]);
    }

    for(int i = 1 ; i <= 2 ; i++){
        printf("Name %d: %s\n", i, name[i-1]);
        printf("Height %d: %.2lf\n", i, T[i-1]);
        printf("Age %d: %d\n", i, U[i-1]);
    }

    return 0;
}