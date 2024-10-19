#include <stdio.h>

int main() {
    int arr[5] = {1,10};
    int size = 2;

    int selisih[size];
    for (int i = 0; i < size-1; i++)
    { 
      selisih[i] = arr[i] - arr[i+1];
      selisih[i] = selisih[i] < 0 ? selisih[i] * -1 : selisih[i]; // permutlakan
    }
    
    // mencari min
    int min = selisih[0];
    for (int i = 1; i < size-1; i++) {
        if (selisih[i] < min) {
            min = selisih[i];
        }
    }

    printf("%d", min);

    return 0;
}

