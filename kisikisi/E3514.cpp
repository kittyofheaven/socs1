#include <stdio.h>
#include <math.h>

int main(){
  int bilangan;
  scanf("%d", &bilangan);

  int count = 0;
  int arr[100];
  while(bilangan > 0){
    arr[count] = bilangan % 10 * pow(10,count);
    bilangan /= 10;
    count++;
  }

  for(int i = count-1; i >= 0; --i){
    printf("%d", arr[i]);
    if(i != 0) printf(" ");
  }
  printf("\n");
}