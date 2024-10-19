#include <stdio.h>

int main(){
  int N;
  scanf("%d", &N);

  double jojo, lili, bibi;
  scanf("%lf %lf %lf", &jojo, &lili, &bibi);

  double others_scores = 0.0;
  for(int i = 0; i < N; ++i){
    double score;
    scanf("%lf", &score);
    others_scores = others_scores + score;
  }

  double mean = (others_scores + jojo + lili + bibi) / (N + 3) * 1.0;

  (jojo >= mean) ? printf("Jojo lolos\n") : printf("Jojo tidak lolos\n");
  (lili >= mean) ? printf("Lili lolos\n") : printf("Lili tidak lolos\n");
  (bibi >= mean) ? printf("Bibi lolos\n") : printf("Bibi tidak lolos\n");

  return 0;
}