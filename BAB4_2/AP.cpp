#include <stdio.h>
#include <string.h>

int main(){
  int T;
  scanf("%d", &T);

  for(int k = 1; k <= T; ++k){
    int N;
    long long K;

    scanf("%d %lld", &N, &K);
    getchar();
    char theInput[N+1];
    scanf("%s", theInput);

    for(int i = 0; i < N ; ++i){
      int tambahan = K % 26;
      if(theInput[i] + tambahan > 'z') {
        int selisih = theInput[i] + tambahan - 'z';
        theInput[i] = 'a' - 1 + selisih;
      } else {
        theInput[i] += tambahan;
      }
    }

    printf("Case #%d: %s\n", k, theInput);
  }
}