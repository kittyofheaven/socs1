#include <stdio.h>
#include <ctype.h>

void floatFill(char map[1001][1001], int x, int y, int N, int *count){
	
	if(isalpha(map[x][y])) map[x][y] = '0';
	if(map[x][y] == '#') return;
	if(x < 0 || y < 0 || x >= N || y >= N) return;
	
	*count += (map[x][y] - '0');
	map[x][y] = '#';
	floatFill(map, x+1, y, N, count);
	floatFill(map, x-1, y, N, count);
	floatFill(map, x, y+1, N, count);
	floatFill(map, x, y-1, N, count);
}

typedef struct {
	int count;
	char character;
} Harvester;

void merge(Harvester *arr, int low, int mid, int high){
	int lLen = mid - low + 1;
	int rLen = high - mid;
	
	Harvester lTemp[lLen], rTemp[rLen];
	for(int i = 0; i < lLen; ++i) lTemp[i] = arr[i+low];
	for(int i = 0; i < rLen; ++i) rTemp[i] = arr[i+mid+1];
	
	for(int i = 0, j = 0, k = low; k <= high; ++k){
		if((i < lLen && j >=rLen) || (i < lLen) && (lTemp[i].character < rTemp[j].character || (lTemp[i].character == rTemp[j].character && lTemp[i].count >= rTemp[j].count) )) arr[k] = lTemp[i++];
		else arr[k] = rTemp[j++];
	}
}

void mergeSort(Harvester *arr, int low, int high){
	if(low < high){
		int mid = low + (high - low) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}

int main(){
	int N, H;
	scanf("%d %d", &N, &H); getchar();
	char map[1001][1001];
	
	Harvester harvester[27];
	int harvesterCount = 0;
	
	for(int i = 0; i <= 26; ++i){
		harvester[i].count = 0;
	}
	
	for(int i = 0; i < N; ++i){
		
		scanf("%s", &map[i]);
		
		getchar();
	}
	
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(isalpha(map[i][j])){
				harvester[harvesterCount].character = map[i][j];
				floatFill(map, i, j, N, &harvester[harvesterCount++].count);
			}
		}
	}
	
//	for(int i = 0; i < N; ++i){
//		for(int j = 0; j < N; ++j){
//			printf("%c", map[i][j]);
//		}
//		printf("\n");
//	}
	
	mergeSort(harvester, 0, harvesterCount - 1);
	
	for(int i = 0; i < H; ++i){
		printf("%c %d\n",harvester[i].character, harvester[i].count);
	}
//	printf("\n");
	
	return 0;
}
