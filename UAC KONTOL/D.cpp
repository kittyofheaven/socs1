#include <stdio.h>


void merge(int *arr, int low, int mid, int high){
	int lLen = mid - low + 1;
	int rLen = high - mid;
	
	int lTemp[lLen], rTemp[rLen];
	for(int i = 0; i < lLen; ++i) lTemp[i] = arr[i+low];
	for(int i = 0; i < rLen; ++i) rTemp[i] = arr[i+mid+1];
	
	for(int i = 0, j = 0, k = low; k <= high; ++k){
		if((i < lLen && j >=rLen) || (i < lLen) && (lTemp[i] < rTemp[j])) arr[k] = lTemp[i++];
		else arr[k] = rTemp[j++];
	}
}

void mergeSort(int *arr, int low, int high){
	if(low < high){
		int mid = low + (high - low) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}

int binSearch(int *arr, int low, int high, int target){
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(arr[mid] == target) return mid;
		else if(target < arr[mid]){
			high = mid - 1;
		} else {
			low = mid + 1;	
		}
	}
	
//	for(int i = 0; i <= high; ++i){
//		if(arr[i] == target) return i;
//	}
	return -1;
}

int arrJumlah[1000000];
char flag[100001] = {0};
int arrJumlahCount = 0;
int main(){
	int N;
	scanf("%d", &N);
	
	
	int arr[N];
	int arrCount = 0;

	for(int i = 0; i < N; ++i){
		int temp;
		scanf("%d", &temp);
		
		bool plus = false;
		if(flag[temp] > 1){
			continue;
		}
		
		arr[arrCount] = temp;
	 	plus = true;
		flag[temp] = 1;
			
		for(int j = 0; j < arrCount; ++j){
			arrJumlah[arrJumlahCount++] = arr[i] + arr[j];
		}
		if(plus){
			arrCount++;
		}
	}
	
//	printf("arr count : %d\n", arrCount);
	

	
//	for(int i = 0; i < arrJumlahCount; ++i){
//		printf("%d ", arrJumlah[i]);
//	}
	
	mergeSort(arrJumlah, 0, arrJumlahCount - 1);
	
//	printf("\n");
//	for(int i = 0; i < arrJumlahCount; ++i){
//		printf("%d ", arrJumlah[i]);
//	}
	
	int target;
	scanf("%d", &target);
	int index = binSearch(arrJumlah, 0, arrJumlahCount-1, target);
//	printf("%d\n", index);
	(index == -1) ? printf("No\n") : printf("Yes\n");
	return 0;
}
