#include <stdio.h>

int anjay(int number){
  for(int i = number-1 ; i > 0; i --){
    number+=i;
  }
  return number;
}

int main(){
  int n;
  scanf("%d", &n);
  int harga[n];

  for(int i = 0; i < n; ++i){
    scanf("%d", &harga[i]);
  }
  int selisihHarga[anjay(n) + 1];
  int selisihCount = 0;

  for(int i = 0; i < n; ++i){
    for(int j = i+1; j < n; ++j){
      selisihHarga[selisihCount] = harga[j] - harga[i];
      selisihCount++;
    }
  }

  int max = 0;
  for(int i = 0; i < selisihCount; ++i){
    // printf("%d", selisihHarga[i]);
    if(max < selisihHarga[i]) max = selisihHarga[i];
  }

  printf("%d\n", max);

}