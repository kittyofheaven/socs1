#include <stdio.h>

void merge(long long int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    long long int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long long int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int canFormTriangle(long long int arr[], int n) {
    for (int i = 0; i < n - 2; i++) {
        if (arr[i] + arr[i + 1] > arr[i + 2]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *file = fopen("testdata.in", "r");

    int N;
    fscanf(file, "%d", &N);
    long long int sticks[N];

    for (int i = 0; i < N; i++) {
        fscanf(file, "%lld", &sticks[i]);
    }
    fclose(file);

    mergeSort(sticks, 0, N - 1);

    if (canFormTriangle(sticks, N)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
