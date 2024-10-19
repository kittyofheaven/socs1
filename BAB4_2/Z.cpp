#include <stdio.h>

int main(){
  int N;
  scanf("%d", &N);

  long long total = 0;
  for(int i = 0; i < N; ++i){
    int lemparanDadu;
    scanf("%d", &lemparanDadu);
    
    total += lemparanDadu;
    total %= 40;

    switch (total)
    {
    case 30:
      total = 10;
      break;

    case 12:
      total = 28;
      break;

    case 35:
      total = 7;
      break;

    default:
      break;
    }
  }
  
  printf("%lld\n", total);
}