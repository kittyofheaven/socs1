#include <stdio.h>

void ular_tangga(int *lokasi){
  switch (*lokasi)
  {
  case 9:
    *lokasi = 21;
    break;
  case 33:
    *lokasi = 42;
    break;
  case 76:
    *lokasi = 92;
    break;
  case 53:
    *lokasi = 37;
    break;
  case 80:
    *lokasi = 59;
    break;
  case 97:
    *lokasi = 88;
    break;
  default:
    break;
  }
}

int main(){
  int N;
  scanf("%d", &N);

  int dadu[N];
  for(int i = 0; i < N; ++i){
    scanf("%d", &dadu[i]);
  }

  int lokasi = 0;
  for(int i = 0; i < N; ++i){
    lokasi+=dadu[i];
    ular_tangga(&lokasi);
  }

  printf("%d\n", lokasi);
}