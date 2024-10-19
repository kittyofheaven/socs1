#include <stdio.h>
#include <string.h>

int main(){
  int N;
  scanf("%d", &N);

  int jumlahTayangan[N];
  memset(jumlahTayangan, 0, sizeof(jumlahTayangan)/sizeof(jumlahTayangan[0]));

  for(int i =0; i < N; ++i){
    scanf("%d", &jumlahTayangan[i]);
  }

  int Q;
  scanf("%d", &Q);

  for(int i = 1; i <= Q; ++i){
    int tempA, tempB;
    scanf("%d %d", &tempA, &tempB);

    long long totalTayangan = 0;
    for(int j = tempA-1; j < tempB; ++j ){
      totalTayangan += jumlahTayangan[j];
    }

    printf("Case #%d: %lld\n", i, totalTayangan);
  }
  return 0;
}