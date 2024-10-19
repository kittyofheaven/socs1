#include <stdio.h>

int main(){
    int physical_damage, magical_damage, pure_damage;
    scanf("%d %d %d", &physical_damage, &magical_damage, &pure_damage);
    float result = (physical_damage * 20.0/100.0) + (magical_damage * 30.0/100.0) + (pure_damage * 50.0/100.0);
    printf("%.2f\n", result);
}