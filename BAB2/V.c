#include <stdio.h>

int main(){

  int T;
  scanf("%d", &T);

  int A[T];

  for(int i = 0 ; i < T ; ++i){
    scanf("%d", &A[i]);
  }
  for(int i = 0 ; i < T ; ++i){
    float reamur = 0.8 * A[i];
    float farenheit = (1.8 * A[i]) + 32.0;
    float kelvin = A[i] + 273.0;

    printf("%.2f %.2f %.2f\n", reamur, farenheit, kelvin);
  }
}
