#include <stdio.h>
#include <math.h>

int main(){
  long long int a,b,c;
  scanf("%lld %lld %lld", &a, &b, &c);

  long long int count = 0;
  for(int i = a; i <= b ; ++i){
    
    if(i == c){
      count ++;
    } else {
      long long int angka = i;
      long long int temp = 0;
      for(int j = 0; j < 5; ++j){
        temp += angka % 10;
        angka/=10;
      }
      if(temp == c){
        count++;
      }
    }
  }

  printf("%lld", count);

}