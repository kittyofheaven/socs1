#include <stdio.h>

// typedef struct 
// {
//   char nama[101];
//   int total;
// } Restoran;

typedef struct {
    char nama[101];
    int p;
    int j;
} Restoran;

// void merge(Restoran *arr, int low, int mid, int high){
//   int lLen = mid - low + 1;
//   int rLen = high - mid;

//   Restoran lTemp[lLen];
//   Restoran rTemp[rLen];

//   for(int i = 0; i < lLen; ++i) lTemp[i] = arr[low+i];
//   for(int i = 0; i < rLen; ++i) rTemp[i] = arr[mid+1+i];

//   for(int i = 0, j = 0, k = low; k <= high; ++k){
//     if((i < lLen && j >= rLen) || (i < lLen) && (lTemp[i].total >= rTemp[j].total)) arr[k] = lTemp[i++];
//     else arr[k] = rTemp[j++];
//   }
// }

// void mergeSort(Restoran *arr, int low, int high){
//   if(low < high){
//     int mid = low + (high - low) / 2;
//     mergeSort(arr, low, mid);
//     mergeSort(arr, mid+1, high);
//     merge(arr, low, mid, high);
//   }
// }

// void bubleSort(Restoran *arr, int N){
//   for(int i = 0; i < N-1; ++i){
//     for(int j = 0; j < N-i-1; ++j){
//       if(arr[j].total == arr[j+1].total){
//         continue;
//       }
//       else if(arr[j].total < arr[j+1].total){
//         Restoran temp = arr[j];
//         arr[j] = arr[j+1];
//         arr[j+1] = temp;
//       }
//     }
//   }
// }

// void selectionSort(Restoran *arr, int N){
//   for(int i = 0; i < N-1; ++i){
//     int min = i;
//     for(int j = i+1; j < N; ++j){
//       if(arr[j].total > arr[min].total){
//         min = j;
//       }
//     }
//     Restoran temp = arr[i];
//     arr[i] = arr[min];
//     arr[min] = temp;
//   }
// }


// void bodoAmatSort(Restoran arr[], int N) {
//     for (int i = 1; i < N; ++i) {
//         Restoran key = arr[i];
//         int j = i - 1;

//         while (j >= 0 && arr[j].total < key.total) {
//             arr[j + 1] = arr[j];
//             --j;
//         }
//         arr[j + 1] = key;
//     }
// }

void swap(Restoran* a , Restoran* b){
	Restoran temp = *a;
	*a = *b;
	*b = temp;
}

void bubleSort(Restoran* arr, int n) {
    for (int i = 0 ; i < n - 1; i++){
      for (int k = i + 1 ; k < n; k++){
        if(arr[i].p * arr[i].j < arr[k].p * arr[k].j)
          swap(&arr[i], &arr[k]);
      }
	}
}

int main(){
  int N;
  scanf("%d", &N); getchar();

  Restoran pelanggan[N], pelangganAsli[N];

  for(int i = 0; i < N; ++i){
    int temp1, temp2;
    scanf("%s %d %d", pelanggan[i].nama, &temp1, &temp2); getchar();
    // pelanggan[i].total = temp1*temp2;
    pelanggan[i].p =temp1;
    pelanggan[i].j =temp2;
  }

  for(int i = 0; i < N; ++i){
    pelangganAsli[i] = pelanggan[i];
  }

  // mergeSort(pelanggan, 0, N-1);
  // bubleSort(pelanggan, N);
  bubleSort(pelanggan, N);
  // bodoAmatSort(pelanggan, N);


  for (int i = 0; i < N; i++) {
        printf("%s %d\n", pelanggan[i].nama, pelanggan[i].p * pelanggan[i].j);
  }

  return 0;
}
