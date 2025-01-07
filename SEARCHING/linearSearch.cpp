#include<stdio.h>

int linearSearch(int *arr, int len, int search){
  for(int i = 0; i < len; ++i){
    if(arr[i] == search){
      return i;
    }
  }
  return -1;
}

int main(){
  int arr[6] = {3,5,1,7,10,9};

  printf("%d\n", linearSearch(arr, 6, 9));

  return 0;
}