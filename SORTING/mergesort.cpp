#include <stdio.h>

void merge(int arr[], int low, int mid, int high){
  int leftLength = mid - low + 1;
  int rightLength = high - mid;

  int tempLeftArr[leftLength]; // create a temp for left arr.
  int tempRightArr[rightLength]; // create a temp for right arr.

  for(int i = 0; i < leftLength; ++i) tempLeftArr[i] = arr[low + i]; // copy left arr to temp.
  for(int i = 0; i < rightLength; ++i) tempRightArr[i] = arr[mid + 1 + i]; // copy right arr to temp.

  for(int i = 0, j =0, k = low; k <= high; ++k){ 
    // k buat track index dari array yg asli dan di loop sampe array nya habis yaitu di index ke high
    // i itu buat track index tempLeftArr
    // j itu buat track index tempRightArr
    if((i < leftLength && (j >= rightLength)) || (i < leftLength) && (tempLeftArr[i] <= tempRightArr[j])){ // sorting bisa dibalik descending atau ascending dengan mengubah tanda di (tempLeftArr[i] <= tempRightArr[j])
      // jika i (tempLeftArr) && jika j (tempRightArr) sudah habis || jika i belum habis maka bandingkan (lanjut dibawah),
      // jika lebih besar tempLeftArr[i] maka masukkan ke arr[k],
      // jika lebih besar tempRightArr[j] maka masuk ke else yaitu memasukkan tempRightArr[j] ke arr[k].
      arr[k] = tempLeftArr[i++];
      // ++i;
    } else { // maka else akan terjadi jika tempRightArr belum habis atau tempRightArr[j] lebih besar.
      arr[k] = tempRightArr[j++];
      // ++j;
    }
  }
}

void mergeSort(int arr[], int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2; // ini buat cari index ke middle dari array tersebut dan di floor.
    
    //recursively call merge sort.
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1 , high);

    // after both divided array is solved, we have to perform merging.
    merge(arr, low, mid, high);
  }
}

int main(){
  int arr[12] = {0,5,2,3,4,6,7,9,8,10,11,12};
  int length = 12;
  mergeSort(arr, 0, length - 1);

  printf("sorted arrays:");
  for(int i = 0; i < length; ++i){
    printf(" %d", arr[i]);
  }
  return 0;
}