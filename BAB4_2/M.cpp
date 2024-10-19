#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);

  for(int k = 1; k <= T; ++k){
    int N, M;
    scanf("%d %d", &N, &M);

    long long totalHarga = 0;
    for(int i = 0; i < N; i++){
      long long hargaBarang;
      scanf("%lld", &hargaBarang);
      totalHarga += hargaBarang;
    }

    (M >= totalHarga) ? printf("Case #%d: No worries\n", k) : printf("Case #%d: Wash dishes\n", k);
  }

  return 0;
}