#include <stdio.h>

typedef struct {
	int min;
	int max;
} Suhu;

void merge(Suhu *arr, int low, int mid, int high){
	int lLen = mid - low + 1;
	int rLen = high - mid;
	
	Suhu lTemp[lLen], rTemp[rLen];
	for(int i = 0; i < lLen; ++i) lTemp[i] = arr[i+low];
	for(int i = 0; i < rLen; ++i) rTemp[i] = arr[i+mid+1];
	
	for(int i = 0, j = 0, k = low; k <= high; ++k){
		if((i < lLen && j >=rLen) || (i < lLen) && ( lTemp[i].min < rTemp[j].min || (lTemp[i].min == rTemp[j].min && lTemp[i].max <= rTemp[j].max))) arr[k] = lTemp[i++];
		else arr[k] = rTemp[j++];
	}
}

void mergeSort(Suhu *arr, int low, int high){
	if(low < high){
		int mid = low + (high - low) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}

int main(){
	int N; 
	scanf("%d", &N);
	
	Suhu arr[1001];
	for(int i = 0; i < N; ++i){
		scanf("%d %d", &arr[i].min, &arr[i].max);
	}
	
	mergeSort(arr, 0, N-1);
	
	int size = arr[0].min;
	int max = arr[0].max;
	int count = 0;
	count++;
	
	for(int i = 1; i < N; ++i){
		if(arr[i].min <= size && size <= arr[i].max) continue;
		else if(arr[i].min > size && arr[i].min <= max){
			size = arr[i].min;
			if(arr[i].max < max) max = arr[i].max;
		} else{
			count++;
			size = arr[i].min;
			max = arr[i].max;	
		}
	}
	
//	for(int i = 0; i < N; ++i){
//		printf("%d %d\n", arr[i].min, arr[i].max);
//	}
	printf("%d\n", count);
	
	return 0;
}
