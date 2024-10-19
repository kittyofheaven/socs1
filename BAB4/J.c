#include <stdio.h>

int main(){

  int N;
  scanf("%d", &N); // jumlah peserta lain

  int others[N];

  int j,l,b;
  scanf("%d %d %d", &j, &l, &b);

  for(int i = 0; i < N; ++i){
    scanf("%d", &others[i]);
  }

  int sum = 0;
  for(int i = 0; i < N; ++i){
    sum+= others[i];
  }

  // jumlahkan dengan jlb
  sum = sum + j + l + b;

  // mean
  float mean = sum / ((N + 3) * 1.0);

  (j >= mean) ? printf("Jojo lolos\n") : printf("Jojo tidak lolos\n");
  (l >= mean) ? printf("Lili lolos\n") : printf("Lili tidak lolos\n");
  (b >= mean) ? printf("Bibi lolos\n") : printf("Bibi tidak lolos\n");
}
