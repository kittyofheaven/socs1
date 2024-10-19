#include <stdio.h>

int interest(long long money, int interestRate){

  money = money * interestRate/100.0/12.0 * (100.0/100.0 - 20.0/100.0);

  return money;
}

void Deposito(int kasus){
  long long money; 
  int interestRate, month;
  scanf("%lld %d %d", &money, &interestRate, &month);

  printf("Case #%d:\n", kasus);
  for(int i = 1; i <= month; ++i){
    money += interest(money, interestRate);
    printf("%d %lld\n", i, money);
  }

}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; ++i){
    Deposito(i);
  }
  return 0;
}