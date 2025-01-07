#include <stdio.h>
#include <string.h>
typedef struct{
	int day;
	int month;
	int year;
	char name[21];
} Date;

int bandingkan(Date a, Date b){
	if(a.year == b.year){
		
		if(a.month == b.month){
			if(a.day == b.day){
				return 0;
			} else if( a.day > b.day){
				return -1;
			} else {
				return 1;
			}
		} else if( a.month > b.month){
			return -1;
		} else {
			return 1;
		}
	
	} else if( a.year > b.year){
		return -1;
	} else {
		return 1;
	}
}

void merge(Date *arr, int low, int mid, int high){
	int lLen = mid - low + 1;
	int rLen = high - mid;
	
	Date lTemp[lLen], rTemp[rLen];
	for(int i = 0; i < lLen; ++i) lTemp[i] = arr[i+low];
	for(int i = 0; i < rLen; ++i) rTemp[i] = arr[i+mid+1];
	
	for(int i = 0, j = 0, k = low; k <= high; ++k){
		if((i < lLen && j >=rLen) || (i < lLen) && ((bandingkan(lTemp[i], rTemp[j]) > 0) || (bandingkan(lTemp[i], rTemp[j]) == 0 && strcmp(lTemp[i].name, rTemp[j].name) <= 0))) arr[k] = lTemp[i++];
		else arr[k] = rTemp[j++];
	}
}

void mergeSort(Date *arr, int low, int high){
	if(low < high){
		int mid = low + (high - low) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}

int main(){
	int N;
	scanf("%d", &N); getchar();
	
	Date dateList[20001];
	
	for(int i = 0; i < N; ++i){
		scanf("%d-%d-%d %s", &dateList[i].year, &dateList[i].month, &dateList[i].day, dateList[i].name); getchar();
	}
	
	mergeSort(dateList, 0, N-1);
	
	
//	for(int i = 0; i < N; ++i){
//		printf("%04d-%02d-%02d %s\n", dateList[i].year, dateList[i].month, dateList[i].day, dateList[i].name);
//	}

	int T;
	scanf("%d", &T); getchar();
	for(int i = 0; i < T; ++i){
		int temp = 0;
		scanf("%d", &temp); getchar();
		printf("%04d-%02d-%02d %s\n", dateList[temp-1].year, dateList[temp-1].month, dateList[temp-1].day, dateList[temp-1].name);
	}
	
	return 0;
}
