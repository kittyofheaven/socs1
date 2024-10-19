#include <stdio.h>

#include <stdbool.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

int main(){
  int d,s,t;

  scanf("%d %d %d", &d, &s, &t);

  int arr[3] = {d,s,t};
  bubbleSort(arr, 3);

  for(int i=0 ; i<3 ; ++i){
    if (arr[i] == d) {
      printf("Daging\n");
    } else if (arr[i] == s) {
      printf("Sayur\n");
    } else if (arr[i] == t)
    {
      printf("Telur\n");
    }
  }
  return 0;
}