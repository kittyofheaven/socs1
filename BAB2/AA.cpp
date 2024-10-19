#include <stdio.h>

int main(){
    float tugas, ujian_tengah, ujian_akhir;
    scanf("%f %f %f", &tugas, &ujian_tengah, &ujian_akhir);

    float result = (20.0/100.0*tugas) + (30.0/100.0*ujian_tengah) + (50.0/100.0*ujian_akhir);

    printf("%.2f\n", result);
    return 0;
}